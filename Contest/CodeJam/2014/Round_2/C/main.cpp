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
#define INF 987654321
#define double long double // use long double when using bisection

int t;
int W, H, B;

struct building {
    int x0, y0, x1, y1;
    building() {}
    building(int x0, int y0, int x1, int y1): x0(x0), y0(y0), x1(x1), y1(y1) { }
};

#define LEN 1005
building bd[LEN];
int g[LEN][LEN];

int calcDist (int x0, int y0, int x1, int y1) {
    return max(0,max(abs(x0-x1)-1, abs(y0-y1)-1));
}

int calcDist (int x, int y, building b) {
    if (b.y0 <= y && y <= b.y1) return min(abs(x-b.x0), abs(x-b.x1))-1;
    if (b.x0 <= x && x <= b.x1) return min(abs(y-b.y0), abs(y-b.y1))-1;
    int bX[4] = {b.x0, b.x0, b.x1, b.x1}, bY[4] = {b.y0, b.y1, b.y0, b.y1};
    int res = INF;
    for (int i=0; i<4; i++) res = min(res, calcDist(x, y, bX[i], bY[i]));
    return res;
}

int calcDist (building a, building b) {
    int res = INF;
    int aX[4] = {a.x0, a.x0, a.x1, a.x1}, aY[4] = {a.y0, a.y1, a.y0, a.y1};
    int bX[4] = {b.x0, b.x0, b.x1, b.x1}, bY[4] = {b.y0, b.y1, b.y0, b.y1};
    for (int i=0; i<4; i++) res = min(res, calcDist(aX[i], aY[i], b));
    for (int i=0; i<4; i++) res = min(res, calcDist(bX[i], bY[i], a));
    return max(0,res);
}

int dijkstra(int source, int target, int n) {
    vector<int> dist(n, INF);
    dist[source] = 0;
    priority_queue<pii> pq;
    pq.push(mp(0, source));
    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        int curDist = cur.fi, v = cur.se;
        if (curDist > dist[v]) continue;
        for (int u=0; u<n; u++) {
            if (dist[u] > curDist + g[v][u]) {
                dist[u] = curDist + g[v][u];
                pq.push(mp(dist[u], u));
            }
        }
    }
    return dist[target];
}

void solve(int tc) {
    cin >> W >> H >> B;
    bd[0] = building(-1,0, -1, H);
    for (int i=1; i<=B; i++) {
        int X0, Y0, X1, Y1;
        cin >> X0 >> Y0 >> X1 >> Y1;
        bd[i] = building(X0, Y0, X1, Y1);
    }
    bd[B+1] = building(W, 0, W, H);
    for (int i=0; i<=B+1; i++) {
        for (int j=0; j<=B+1; j++) {
            g[i][j] = calcDist(bd[i], bd[j]);
        }
    }
    /*
    for (int i=0; i<=B+1; i++) {
        for (int j=0; j<=B+1; j++) {
            printf("%d ", g[i][j]);
        }
        cout << endl;
    }*/
    cout << dijkstra(0, B+1, B+2) << endl;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
