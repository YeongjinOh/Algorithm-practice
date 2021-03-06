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
#define INF 5e18


ll t, n, a, b, c;
string str;
void read() {
    cin >> str;
}

void solve () {
    for (int i=0; i>=0 && i<str.size()-1;) {
        if (str[i] > str[i+1]) {
            str[i]--;
            for (int j=i+1; j<str.size(); j++)
                str[j] = '9';
            i--;
        } else {
            i++;
        }
    }
    int i=0;
    while(i<str.size() && str[i] == '0') { i++; }
    for (; i<str.size(); i++)
        cout << str[i];
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        read();
        solve();
        cout << endl;
    }
    return 0;
}
