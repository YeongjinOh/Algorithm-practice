#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define LEN 500
#define INF 987654321
using namespace std;

int C, n, m;
int x[LEN], y[LEN];
double norm(int a, int b) {
    return sqrt(a*a+b*b);
}
double adj[LEN][LEN];
void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        scanf("%d", &x[i]);
    for (int i=0; i<n; i++)
        scanf("%d", &y[i]);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            adj[i][j] = norm(x[i]-x[j],y[i]-y[j]);

    vector<bool> visit(n, false);
    vector<double> minWeight(n, INF);
    vector<int> parent(n,0);
    /////////////////////////////////////////////////////////////////////////////////////////
    // IMPORTANT
    //
    // 따로 visit을 추가할 필요 없이, 이미 연결된 애들의 w를 0으로 두면
    // 자동으로 얘네를 연결함 + 0을 더해도 결과에 영향 없음
    /////////////////////////////////////////////////////////////////////////////////////////
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a][b] = 0.0;
        adj[b][a] = 0.0;
    }

    // initialize
    visit[0] = true;
    minWeight[0] = 0;
    for (int i=1; i<n; i++) {
        minWeight[i] = adj[0][i];
        // we don't need to build tree
//        parent[i] = 0;
    }
    double ans = 0.0;
    for (int v=0; v<n-1; v++) {
        // get minimal weight
        int u=0;
        double minW = INF;
        for (int i=0; i<n; i++) {
            if (!visit[i] && minWeight[i] < minW) {
                u = i;
                minW = minWeight[i];
            }
        }
        visit[u] = true;
        ans += minW;
        for (int i=0; i<n; i++) {
            if (!visit[i]) {
                minWeight[i] = min<double>(minWeight[i], adj[u][i]);

            }
        }

    }
    printf("%.10lf\n",ans);
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
