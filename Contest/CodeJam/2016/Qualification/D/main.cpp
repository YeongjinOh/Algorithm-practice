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


ll t, n, a, b, k, c, s;

void read() {
    cin >> k >> c >> s;
}

ll pow(ll n, ll k) {
    if (k==0) return 1;
    ll half = pow(n, k/2);
    if (k%2==0) return half*half;
    return half*half*n;
}

ll getPos (vector<ll> & sol) {
    ll pos = sol[0] - 1;
    for (int i=1; i<sol.size(); i++) {
        pos = k*pos + sol[i]-1;
    }
    return pos+1;
}

void solve () {
    if (s*c < k) {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<ll> sol;
    for (ll i=1; i<=k; ++i) {
        sol.pb(i);
        if (sol.size() == c) {
            cout << getPos(sol) << " ";
            sol.clear();
        }
    }
    if (sol.size() > 0) {
        for (ll i=1; i<=k && sol.size() < c; i++)
            sol.pb(i);
        cout << getPos(sol) << " ";
    }
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
