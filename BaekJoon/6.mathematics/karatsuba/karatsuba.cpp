#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
const int mod = 100;

vector<int> normalize(vector<int>& c) {
    for (int i=0; i<c.size()-1; i++) {
        if (c[i] < 0) {
            c[i+1]--;
            c[i] += mod;
            continue;
        }
        c[i+1] += c[i]/mod;
        c[i] = c[i]%mod;
    }
    while(c.size()>1 && c.back() == 0) {c.pop_back();}
    return c;
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size()+b.size()+20,0);
    for (int i=0; i<a.size(); ++i)
        for (int j=0; j<b.size(); ++j) {
            c[i+j] += a[i]*b[j];
        }
    for (int i=0; i<c.size()-1; i++) {
        c[i+1] += c[i]/mod;
        c[i] = c[i]%mod;
    }
    return normalize(c);
}

vector<int> add(const vector<int>& a, const vector<int> & b) {
    int an = a.size(), bn = b.size();
    if (an<bn) return add(b,a);
    int cn = an;
    vector<int> c(cn);
    for (int i=0; i<bn; i++) {
        c[i] = a[i] + b[i];
    }
    for (int i=bn; i<cn; i++) {
        c[i] = a[i];
    }
    return normalize(c);
}
// a should be longer than b
vector<int> sub(const vector<int>& a, const vector<int> & b) {
    vector<int> c(a.size());
    for (int i=0; i<b.size(); i++) {
        c[i] = a[i]-b[i];
    }
    for (int i=b.size(); i<c.size(); i++) {
        c[i] = a[i];
    }
    return normalize(c);
}
void print(const vector<int>& a) {
    bool fst=true;
    cout<<a[a.size()-1];
    for (int i=a.size()-2; i>=0; --i) {
            printf("%.2d",a[i]);
    }
    cout << endl;
}

// a is longer than b
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    cout << endl;
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b,a);
    if (an == 0 || bn == 0) return vector<int>();
    if (an < 20) return multiply(a,b);
    int half = an/2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(b.size(),half));
    vector<int> b1(b.begin()+min<int>(b.size(),half),b.end());
    vector<int> z0 = karatsuba(a0,b0);
    vector<int> z2 = karatsuba(a1,b1);
    vector<int> z1 = sub(karatsuba(add(a0,a1),add(b0,b1)),add(z0,z2));
    vector<int> c(a.size()+b.size()+1,0);
    for (int i=0; i<z0.size(); i++) c[i] = z0[i];
    for (int i=0; i<z1.size(); i++) c[i+half] = z1[i];
    for (int i=0; i<z2.size(); i++) c[i+2*half] = z2[i];
    return normalize(c);
}
int getTen(int k) {
    if (k == 0)
        return 1;
    return 10*getTen(k-1);
}
vector<int> getLongNumbers (const vector<int>& a) {
    int num = 0;
    vector<int> ret;
    for (int i=0; i<a.size(); i++) {
        if (i%2 == 0) {
            if (i>0)
                ret.push_back(num);
            num = 0;
        }
        num += a[i]*getTen(i%2);
    }
    ret.push_back(num);
    return ret;
}

int main() {
    char n;
    bool isA = true;
    vector<int> a, b;
    cin >> n;
    a.push_back(n-'0');
    while(1) {
        scanf("%c",&n);
        if (n == ' ') {
            isA = false;
            continue;
        }
        if (n == '\n') break;
        if (isA) a.push_back(n-'0');
        else b.push_back(n-'0');
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int> longa = getLongNumbers(a);
    vector<int> longb = getLongNumbers(b);
    vector<int> longc = karatsuba(longa,longb);
    print(longc);
    return 0;
}
