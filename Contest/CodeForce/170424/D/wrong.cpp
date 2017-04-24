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
#define LEN 85
int n, k;
int res = 987654321;
// g[v] = (u, c)
vector<pii> g[LEN];

bool visit[LEN][LEN][LEN][LEN];

void dfs (int here, int cnt, int sumC, int l, int r) {
    /////////////////////////////////////////////////////////////
    // IMPORTANT
    //
    // visit[here][cnt][l][r]의 값이 최소로 계산되었을 거란 보장이 안됨!
    /////////////////////////////////////////////////////////////
    printf("here:%d cnt:%d sumC:%d l:%d r:%d\n", here, cnt, sumC, l, r);
    if (visit[here][cnt][l][r]) return;
    visit[here][cnt][l][r] = true;
    if (l > r) return;
    if (res < sumC) return;
    if (cnt == k) {
        printf("here:%d cnt:%d sumC:%d l:%d r:%d\n", here, cnt, sumC, l, r);
        res = min<int>(res,sumC);
        return;
    }
    if (r-l-1 < k-cnt) return;
    for (int i=0; i<g[here].size(); i++) {
        int there = g[here][i].fi;
        if (l >= there || there >= r) continue;
        dfs(there, cnt+1, sumC + g[here][i].se, l, there);
        dfs(there, cnt+1, sumC + g[here][i].se, there, r);
    }
}
int w[LEN][LEN];

int main() {
    int m;
    scanf("%d%d%d", &n, &k, &m);
    int u, v, c;
    memset(w,0,sizeof(w));
    rep(i,0,m) {
        scanf("%d%d%d", &u, &v, &c);
        if (w[u][v] == 0) w[u][v] = c;
        else w[u][v] = min<int>(w[u][v],c);
    }
    rep(i,0,n) rep(j,0,n) if(w[u][v]) g[u].pb(mp(v,w[u][v]));
    memset(visit,0,sizeof(visit));
    for (int i=1; i<=n; i++) {
        dfs(i, 1, 0, 0, i);
        dfs(i, 1, 0, i, n+1);
    }
    if (res < 98765432) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}
