#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

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
// lower bound, upper bound
bool checkRange(int lb, int up) {
    DS ds(n);
    int edgeNum = 0;
    // find the minimal value >= lb
    int l=0, r=edges.size();
    while(l<r) {
        int mid = (l+r)/2;
        if (edges[mid].first >= lb)
            r = mid;
        else
            l = mid+1;
    }
    for (int i=l; i<edges.size() && edgeNum < n-1; i++) {
        edge eg = edges[i];
        int w = eg.first, a = eg.second.first, b = eg.second.second;
        if (w > up) break;
        if (w >= lb) {
            int pa = ds.find(a), pb = ds.find(b);
            if (pa == pb) continue;
            ds.merge(pa,pb);
            edgeNum++;
        }
    }
    return ds.find(0) == ds.find(n-1);
}

bool check(int diff) {
    for (int i=0; i+diff<=1000; i++)
        if (checkRange(i, i+diff)) return true;
    return false;
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
    int l=0, r=1000;
    while(l<r) {
        int mid = (l+r)/2;
        if (check(mid))
            r = mid;
        else
            l = mid+1;
    }
    cout << l << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
