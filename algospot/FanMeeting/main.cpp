#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int min (int a, int b) { return a>b?b:a; }
vector<int> multiply (const vector<int> & a, const vector<int> & b) {
    int n = a.size(), m = b.size();
    vector<int> c(n+m-1,0);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            c[i+j] += a[i]*b[j];
        }
    }
    return c;
}
vector<int> add (const vector<int> & a, const vector<int> & b) {
    int n=a.size(), m=b.size();
    if (n < m)
        return add(b,a);
    vector<int> c(n);
    for (int i=0; i<m; ++i) c[i] = a[i]+b[i];
    for (int i=m; i<n; ++i) c[i] = a[i];
    return c;
}
vector<int> sub (const vector<int> & a, const vector<int> & b) {
    int n=a.size(), m=b.size();
    // a is always longer than b
    vector<int> c(n);
    for (int i=0; i<m; ++i) c[i] = a[i]-b[i];
    for (int i=m; i<n; ++i) c[i] = a[i];
    return c;
}
vector<int> karatsuba (const vector<int> & a, const vector<int> & b) {
    int n = a.size(), m = b.size();
    if (n < m)
        return karatsuba(b,a);
    // n >= m
    if (n < 3)
        return multiply(a,b);
    if (m == 0)
        return vector<int>();
    int half = n/2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), min(b.end(),b.begin()+half));
    vector<int> b1(min(b.end(),b.begin()+half), b.end());
    vector<int> z0 = karatsuba(a0,b0);
    vector<int> z2 = karatsuba(a1,b1);
    vector<int> z1 = sub(karatsuba(add(a0,a1),add(b0,b1)),add(z0,z2));
    vector<int> c(n+m-1,0);
    for (int i=0; i<z0.size(); ++i) c[i] += z0[i];
    for (int i=0; i<z1.size(); ++i) c[half+i] += z1[i];
    for (int i=0; i<z2.size(); ++i) c[2*half+i] += z2[i];
    return c;
}

int countHugs(const string & members, const string & fans) {
    int n = members.size(), m = fans.size();
    vector<int> A(n), B(m);
    for (int i=0; i<n; ++i)  A[i] = (members[i] == 'M');
    for (int i=0; i<m; ++i) B[m-i-1] = (fans[i] == 'M');
    vector<int> C = karatsuba(A, B);
    int cnt = 0;
    // n <= m
    for (int i=n-1; i<m; ++i) {
        if (C[i] == 0)
            ++cnt;
    }
    return cnt;
}

int main() {
    int C;
    cin >> C;
    while(C--) {
        string members, fans;
        cin >> members;
        cin >> fans;
        cout << countHugs(members, fans) << endl;
    }
    return 0;
}
