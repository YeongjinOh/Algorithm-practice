#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
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
#define double long double // use long double when using bisection

const ll MOD = 1000002013;
int t;

ll calc(ll k, ll p) {
    ll res = p%MOD;
    return (res*(((k*(k+1)/2))%MOD))%MOD;
    if (k%2 == 0) {
        res = (res*(k/2))%MOD;
        res = (res*(k+1))%MOD;
    } else {
        res = (res*k)%MOD;
        res = (res*((k+1)/2))%MOD;
    }
    return res;
}

void solve (int tc) {
    ll n, m;
    cin >> n >> m;
    ll res = 0;
    map<ll, ll> cnt;
    vector<pair<ll,ll> > op, ep;
    for (int i=0; i<m; i++) {
        ll o, e, p;
        cin >> o >> e >> p;
        cnt[e-o] = (cnt[e-o] + p)%MOD;
        op.pb(mp(o,p));
        ep.pb(mp(e,p));
    }
    sort(all(op));
    sort(all(ep));

    for (int i=op.size()-1; i>=0; i--) {
        ll o = op[i].fi;
        for (int j=0; j<ep.size() && op[i].se > 0; j++) {
            ll e = ep[j].fi;
            if (o <= e) {
                ll p = min(op[i].se, ep[j].se);
                op[i].se -= p;
                ep[j].se -= p;
                cnt[e-o] -= p;
            }
        }
    }
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        ll k = it->fi, p = it->se;
        res -= ((p%MOD)*((k*(k+1)/2)%MOD))%MOD;
        res = res%MOD;
    }
    cout << (res+MOD)%MOD;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
        cout << endl;
        //        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
