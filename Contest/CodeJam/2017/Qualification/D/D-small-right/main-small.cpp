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


ll t, n, a, b, m;

char N [100][100];

void read() {
    memset(N, 0, sizeof(N));
    cin >> n >> m;
    char c;
    for (int i=0; i<m; i++) {
        cin >> c >> a >> b;
        if (c == '.') N[a-1][b-1] = 0;
        else N[a-1][b-1] = c;
    }
}

void solve () {
    vector<pair<char, pii> > res;
    int oIdx = -1;
    // check x and o
    for (int i=0; i<n; i++) {
        if (N[0][i] == 'x') {
            res.pb(mp('o',mp(1,i+1)));
            N[0][i] = 'o';
            oIdx = i;
        } else if (N[0][i] == 'o') {
            oIdx = i;
        }
    }
    if (oIdx == -1) {
        oIdx = n-1;
        N[0][n-1] = 'o';
        res.pb(mp('o',mp(1,n)));
    }
    for (int i=0; i<n; i++) {
        if (N[0][i] == 0) {
            res.pb(mp('+',mp(1,i+1)));
        }
    }
    for (int i=2; i<n; i++) {
        res.pb(mp('x',mp(i, (oIdx+i-1)%n+1)));
    }
    if (n>=2 && (oIdx == 0 || oIdx == 1)) {
        res.pb(mp('x',mp(n, (oIdx+n-1)%n+1)));
        for (int i=2; i<=n-1; i++) {
            res.pb(mp('+',mp(n, i)));
        }
    } else {
        for (int i=2; i<=n-1; i++) {
            if (i == oIdx)
                res.pb(mp('o',mp(n, i)));
            else
                res.pb(mp('+',mp(n, i)));
        }
    }
    ll ans = 2*n;
    if (n>2) ans += (n-2);
    cout << ans << " " << res.size() << endl;
    for (int i=0; i<res.size(); i++) {
        pair<char, pii> pcii = res[i];
        cout << pcii.fi << " " << pcii.se.fi << " " << pcii.se.se << endl;
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        read();
        solve();
    }
    return 0;
}
