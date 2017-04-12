#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define LEN 500
using namespace std;

struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) : parent(n) {
        for (int i=0; i<n; i++) parent[i]=i;
    }
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        parent[pa] = pb;
    }

};

int C, n, m;
int x[LEN], y[LEN];
double norm(int a, int b) {
    return sqrt(a*a+b*b);
}
typedef pair<double, pair<int, int> > edge;
vector<edge> edges;
void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        scanf("%d", &x[i]);
    for (int i=0; i<n; i++)
        scanf("%d", &y[i]);
    edges.clear();
    for (int i=0; i<n; i++)
        for (int j=0; j<i; j++) {
            double dist = norm(x[i]-x[j],y[i]-y[j]);
            edges.push_back(make_pair(dist, make_pair(i,j)));
        }
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int numEdges = 0;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (ds.find(a) != ds.find(b)) numEdges++;
        ds.merge(a,b);
    }
    double ans = 0.0;
    for (int i=0; i<edges.size() && numEdges < n-1; i++) {
        edge eg = edges[i];
        double w = eg.first;
        int a = eg.second.first, b = eg.second.second;
        if (ds.find(a) != ds.find(b)) {
            ans += w;
            ds.merge(a,b);
            numEdges++;
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
