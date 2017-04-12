//////////////////////////////////////////////////////////////////
// IMPORTANT
//
// 나는 lb와 ub에 대해서 m*O(|E|)번 걸리는 작업을 이분 탐색으로 실행했는데,
// Kruskal의 특성을 이용하면 한번의 O(|E|)로 가능
//
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int C, n, m;
typedef pair<int, pair<int, int> > edge;
vector<edge> edges(m);

struct DS {
    vector<int> parent;
    DS(int n) : parent(n) {
        for (int i=0; i<n; i++)
            parent[i]=i;
    }
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int a, int b) {
        int pa = parent[a], pb = parent[b];
        if (pa == pb) return;
        parent[pa] = pb;
    }
};
// lb is index of lower bound edge
int kruskalMinUpperBound(int lb) {
    DS ds(n);
    for (int i=lb; i<edges.size(); i++) {
        edge eg = edges[i];
        int w = eg.first, a = eg.second.first, b = eg.second.second;
        int pa = ds.find(a), pb = ds.find(b);
        if (pa == pb) continue;
        ds.merge(pa,pb);
        // 0 ~ (n-1)의 경로상 가장 마지막에 추가되는 w이 Upper bound
        if (ds.find(0) == ds.find(n-1)) return w;
    }
    return INF;
}


void solve() {
    cin >> n >> m;
    edges.clear();
    int a, b, w;
    for (int i=0; i<m; i++) {
       scanf("%d%d%d", &a, &b, &w);
       edges.push_back(make_pair(w, make_pair(a,b)));
    }
    sort(edges.begin(), edges.end());
    int res = INF;
    for (int i=0; i<edges.size(); i++)
        res = min<int> (res, kruskalMinUpperBound(i)-edges[i].first);
    cout << res << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
