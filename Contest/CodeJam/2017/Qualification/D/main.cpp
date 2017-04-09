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

int id[2][101][101], start;
vector<vector<int> >g;
vector<int> match;
vector<bool> visited, visit; // visited is temporal
bool init;
bool useX[101], useY[101];

ll t, n, a, b, m, p;
vector<pair<char, pii> > res;
vector<pii> plusPos;
char N [101][101], Nnew[101][101];
int Agroup[300], Bgroup[300];

bool dfs(int n) {
    if (visited[n]) return false;
    visited[n] = true;
    for (int i=0; i<g[n].size(); i++) {
        int it = g[n][i];
        if (match[it] == -1 || dfs(match[it])) {
            Agroup[n] = it;
            match[it] = n;
            return true;
        }
    }
    return false;
}


void read() {
    memset(N, 0, sizeof(N));
    memset(Nnew, 0, sizeof(Nnew));
    memset(useX, 0, sizeof(useX));
    memset(useY, 0, sizeof(useY));
    char c;
    cin >> n >> m;

    // build id
    memset(id,0,sizeof(id));
    p = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (!id[0][x][y]) {
                id[0][x][y] = ++p;
                int tx = x, ty = y;
                while (true) {
                    tx++, ty--;
                    if (tx < 1 || ty < 1 || tx > n || ty > n) break;
                    id[0][tx][ty] = p;
                }
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = n; y >= 1; y--) {
            if (!id[1][x][y]) {
                id[1][x][y] = ++p;
                int tx = x, ty = y;
                while (true) {
                    tx++, ty++;
                    if (tx < 1 || ty < 1 || tx > n || ty > n) break;
                    id[1][tx][ty] = p;
                }
            }
        }
    }

    /*
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            printf("%d ", id[0][i][j]);
        }
        printf("\n");
    }
    cout << endl;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            printf("%d ", id[1][i][j]);
        }
        printf("\n");
    }*/

    // build g
    g.clear();
    g.resize(p + 1);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            g[id[0][x][y]].push_back(id[1][x][y]);
    match = vector<int>(p + 1, -1);
    visit = vector<bool>(p + 1, false);

    // read characters
    for (int i=0; i<m; i++) {
        cin >> c >> a >> b;
        if (c == '.') N[a][b] = 0;
        if (c == '+' || c == 'o') {
            N[a][b] = c;
            visit[id[1][a][b]] = visit[id[0][a][b]] = true;
            match[id[1][a][b]] = id[0][a][b];
        }
        if (c == 'x' || c == 'o') {
            N[a][b] = c;
            useX[a] = true;
            useY[b] = true;
        }
    }
}
void solve () {
    res.clear();
    plusPos.clear();

    ll ans = 0;

    // build x
    vector<int> xPos, yPos;
    for (int i=1; i<=n; i++) {
        if (!useX[i])
            xPos.pb(i);
        if (!useY[i])
            yPos.pb(i);
    }
    for (int i=0; i<xPos.size() && i<yPos.size(); i++) {
        int x=xPos[i], y=yPos[i];
        if (N[x][y] == '+') {
            Nnew[x][y] = 'o';
            N[x][y] = 'o';
        } else {
            Nnew[x][y] = 'x';
            N[x][y] = 'x';
        }
    }


    // build +
    memset(Agroup,0,sizeof(Agroup));

    for (int i = 1; i <= p; i++) {
        visited = visit;
        init = true;
        start = i;
        dfs(i);
    }
    for (int i = 1; i<=p; i++) {
        if (Agroup[i] > 0)
            plusPos.pb(mp(i,Agroup[i]));
    }
    for (int i=0; i<plusPos.size(); i++) {
        // possible id[0], id[1]
        pii pos = plusPos[i];
        int l = pos.fi, r = pos.se;
        int x = (l+r-3*n+2)/2, y = (l-r+3*n)/2;
//        printf("l:%d r:%d x:%d y:%d\n", l, r, x, y);
        if (N[x][y] == 'x') {
            N[x][y] = 'o';
            Nnew[x][y] = 'o';
        } else {
            N[x][y] = '+';
            Nnew[x][y] = '+';
        }
    }

    // calc ans
    for (int x=1; x<=n; x++) {
        for (int y=1; y<=n; y++) {
            if (Nnew[x][y] != 0)
                res.pb(mp(Nnew[x][y],mp(x,y)));
            if (N[x][y] == '+' || N[x][y] =='x')
                ans++;
            else if (N[x][y] == 'o')
                ans+=2;
        }
    }

    cout << ans << " " << res.size() << endl;
    for (int i=0; i<res.size(); i++) {
        pair<char, pii> pcii = res[i];
        cout << pcii.fi << " " << pcii.se.fi << " " << pcii.se.se << endl;
    }

    bool debug = false;
//    debug = true;

    if (debug) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (N[i][j] == 0)
                    cout << ". ";
                else
                    cout << N[i][j] << " ";
            }
            cout << endl;
        }
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
