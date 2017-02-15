#include <iostream>
#include <vector>

using namespace std;
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size()+b.size()+1,0);
    for (int i=0; i<a.size(); ++i)
        for (int j=0; j<b.size(); ++j) {
            c[i+j] += a[i]*b[j];
        }
    for (int i=0; i<c.size()-1; i++) {
        c[i+1] += c[i]/10;
        c[i] = c[i]%10;
    }
    while(c.size()>1 && c.back() == 0) c.pop_back();
    return c;
}
void print(const vector<int>& a) {
    for (int i=a.size()-1; i>=0; --i)
        cout << a[i];
    cout << endl;
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
    vector<int> c = multiply(a,b);
    print(c);
    return 0;
}
