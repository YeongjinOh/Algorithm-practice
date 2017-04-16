#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
string str;
int n;
vector<char> t;
void print(int lb) {
    if (lb >= n) return;
    char m = 'z';
    int cnt = 0;
    for (int i=lb; i<n; i++) {
        if (m == str[i]) {
            cnt++;
        } else if (m > str[i]) {
            m = str[i];
            cnt = 1;
        }
    }
    if (t.size() > 0 && t.back() <= m) {
        for (int i=t.size()-1; i>=0 && t[i]<=m; i--) {
            printf("%c", t[i]);
            t.pop_back();
        }
    }
    int i;
    for (i=lb; i<n && cnt>0; i++) {
        if (str[i] == m) {
            printf("%c",m);
            cnt--;
        } else {
            t.push_back(str[i]);
        }
    }
    print(i);
}
int main() {
    cin >> str;
    n = str.size();
    print(0);
    for (int i=t.size()-1; i>=0; i--)
        printf("%c",t[i]);
    cout << endl;
    return 0;
}
