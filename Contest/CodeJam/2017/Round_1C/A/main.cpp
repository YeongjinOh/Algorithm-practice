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

void solve () {
    int n, k;
    cin >> n >> k;
    vector<pii> rh;
    vector<double> S;
    for (int i=0; i<n; i++) {
        int r, h;
        cin >> r >> h;
        rh.pb(mp(r,h));
    }
    sort(rh.begin(), rh.end());
    for (int i=0; i<rh.size(); i++) {
        int r = rh[i].fi, h = rh[i].se;
        S.push_back(M_PI*2.0*r*h);
    }
    double res = 0.0;
    for (int i=k-1; i<n; i++) {
        double cur = S[i] + M_PI*rh[i].fi*rh[i].fi;
        if (k>1) {
            sort(S.begin(), S.begin()+i);
            for (int j=1; j<=k-1; j++) {
                cur += S[i-j];
            }
        }
        res = max<double>(res,cur);
    }
    printf("%.20lf", res);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
