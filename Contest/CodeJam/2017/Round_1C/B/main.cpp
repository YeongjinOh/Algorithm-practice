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

bool isOverlap (pii a, pii b) {
    int l1 = a.fi, r1 = a.se;
    int l2 = b.fi, r2 = b.se;
    return !((r1 <= l2) || (r2 <= l1));
}

bool isOverlap(pii a, vector<pii> b) {
    bool over = false;
    for (int j=0; j<b.size(); j++) {
        if (isOverlap(a, b[j])) {
            over = true;
            break;
        }
    }
    return over;
}

int calc(vector<pii> sc, vector<pii> sj, int sumC, int sumJ) {
    sort(sc.begin(),sc.end());
    sort(sj.begin(),sj.end());
    if (sc.size() > 0)
        sc.pb(mp(sc[0].fi+1440, sc[0].se+1440));
    if (sj.size() > 0)
        sj.pb(mp(sj[0].fi+1440, sj[0].se+1440));
    vector<pair<int, pii> > scc, sjc;   // vector of (length, (l,r) )
    for (int i=0; i<(int)sc.size()-1; i++) {
        int l = sc[i].se, r = sc[i+1].fi;
        if (l < r)
            scc.pb(mp(r-l, mp(l, r)));
    }
    for (int i=0; i<(int)sj.size()-1; i++) {
        int l = sj[i].se, r = sj[i+1].fi;
        if (l < r)
            sjc.pb(mp(r-l, mp(l, r)));
    }
    sort(scc.begin(), scc.end());
    sort(sjc.begin(), sjc.end());
    for (int i=0; i<scc.size(); i++) {
        pii s = scc[i].se;
        int len = scc[i].fi;
        if (sumC + len > 720) break;
        if (isOverlap(s,sj)) continue;
        sc.pb(s);
        sumC += len;
    }
    for (int i=0; i<sjc.size(); i++) {
        pii s = sjc[i].se;
        int len = sjc[i].fi;
        if (sumJ + len > 720) break;
        if (isOverlap(s,sc)) continue;
        sj.pb(s);
        sumJ += len;
    }
    int cnt = 0;
    sort(sc.begin(),sc.end());
    sort(sj.begin(),sj.end());
    for (int i=0; i<(int)sc.size()-1; i++) {
        if (sc[i].se != sc[i+1].fi) {
            cnt++;
            pii p(sc[i].se,sc[i+1].fi);
            if (!isOverlap(p,sj)) cnt++;
        }
    }
    for (int i=0; i<(int)sj.size()-1; i++) {
        if (sj[i].se != sj[i+1].fi) {
            cnt++;
            pii p(sj[i].se,sj[i+1].fi);
            if (!isOverlap(p,sc)) cnt++;
        }
    }
    return cnt;
}

void solve () {
    int C, J; cin >> C >> J;
    vector<pii> sc, sj; // schedule of C, J
    int sumC = 0, sumJ = 0;
    for (int i=0; i<C; i++) {
        int l, r; cin >> l >> r;
        sc.pb(mp(l,r));
        sumC += r-l;
    }
    for (int i=0; i<J; i++) {
        int l, r; cin >> l >> r;
        sj.pb(mp(l,r));
        sumJ += r-l;
    }
    cout << calc(sc,sj,sumC,sumJ) << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
