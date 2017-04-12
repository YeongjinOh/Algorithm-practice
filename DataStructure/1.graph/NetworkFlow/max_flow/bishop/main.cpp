#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int n, m, ans, p, b[101][101], id[2][101][101], start;
vector<vector<int> >g;
vector<int> match;
vector<bool> visited;
bool init;

bool mbm(int n) {
    if (visited[n]) return false;
    visited[n] = true;
    for (int i=0; i<g[n].size(); i++) {
        int it = g[n][i];
        //        printf("n:%d it:%d match:%d\n", n, it, match[it]);
        if (match[it] == -1 || mbm(match[it])) {
            match[it] = n;
            //            printf("done\n");
            if (init) {
                printf(" %d - %d \n", start, it);
                init = false;
            }
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < 2; i++)
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++) {
                if (!id[i][x][y]) {
                    id[i][x][y] = ++p;
                    int tx = x, ty = y;
                    int dir = !i ? -1 : 1;
                    while (true) {
                        tx++, ty += dir;
                        if (tx < 1 || ty < 1 || tx > n || ty > n) break;
                        id[i][tx][ty] = p;
                    }
                }
            }

    g.resize(p + 1);
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            g[id[0][x][y]].push_back(id[1][x][y]);

    match = vector<int>(p + 1, -1);

    vector<bool> visit = vector<bool>(p + 1, false);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        match[id[1][x][y]] = id[0][x][y];
        visit[id[1][x][y]] = visit[id[0][x][y]] = true;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            printf("%d ", id[0][i][j]);
        }
        printf("\n");
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            printf("%d ", id[1][i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= p; i++) {
        visited = visit;
        cout << i << endl;
        init = true;
        start = i;
        if (mbm(i)) ans++;
    }
    for (int i=1; i<=p ; i++)
        printf("%d ", match[i]);
    cout << endl;
    cout << ans;
}
