#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
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
#define INF 987654321
#define LEN 85
#define MAX 8000
int n, k;
// C(l,r,m,k) = min(l<i<m){ C(l,m,i,k-1) + w(m,i)} , min(m<i<r) { C(m,r,i,k-1) + w(m,i) }
int dp[LEN][LEN][LEN][LEN];
vector<pii> g[LEN];
int main() {
    int m;
    scanf("%d%d%d", &n, &k, &m);
    // init
    rep(l,0,LEN) rep(r,0,LEN) rep(m,0,LEN) rep(e,0,LEN){
        if (e == 0) dp[l][r][m][e] = 0;
        else dp[l][r][m][e] = INF;
    }
    rep(i,0,m) {
        int u, v, c;;
        scanf("%d%d%d", &u, &v, &c);
        g[u].pb(mp(v,c));
    }
    rep(e,1,k)
        rep(l,0,n+2)
            rep(r,l+1,n+2)
                rep(m,l+1,r)
                    rep(i,0,g[m].size()) {
                        int there = g[m][i].fi;
                        if (there <= l || r <= there) continue;
                        if (l < there && there < m)
                            dp[l][r][m][e] = min<int>(dp[l][r][m][e], dp[l][m][there][e-1] + g[m][i].se);
                        if (m < there && there < r)
                            dp[l][r][m][e] = min<int>(dp[l][r][m][e], dp[m][r][there][e-1] + g[m][i].se);
                    }
    int res = INF;
    rep (l,0,n+2) rep(r,0,n+2) rep(m,0,n+2) res = min<int>(res, dp[l][r][m][k-1]);
    if (res < 98765432) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}
