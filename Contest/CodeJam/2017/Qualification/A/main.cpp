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

int k;
string str;

void read() {
    cin >> str >> k;
}

void solve () {
    int res = 0;
    vector<bool> happy(str.size(), false);
    for (int i=0; i<str.size(); ++i)
        happy[i] = str[i] == '+';
    for (int i=0; i+k<=str.size(); i++) {
        if (!happy[i]) {
            for (int j=i; j<i+k; j++) {
                happy[j] = !happy[j];
            }
            res++;
        }
    }
    for (int i=str.size()-k; i<str.size(); i++) {
        if(!happy[i]) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    cout << res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        read();
        solve();
        cout << endl;
    }
    return 0;
}
