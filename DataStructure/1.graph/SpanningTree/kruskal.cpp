#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair

typedef pair<int, pair<int, int> > edge;
int v, e;
struct DisjointSet {
    vector<int> parent;
    DisjointSet (int n) : parent(n+1) {
        for (int i=0; i<=n; i++)
            parent[i]=i; // 자기 자신으로 초기화
    }
    int find (int here) {
        if (parent[here] == here)
            return here;
        return parent[here] = find(parent[here]);
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        parent[pa] = pb;
    }
};

// return sum of weight in MST
// build MST
// O(|ElogE|)
long long kruskal (vector<edge> &edges, vector<edge> &tree) {
    long long res = 0;
    // O(|ElogE|)
    sort(edges.begin(), edges.end());
    DisjointSet ds(v);
    // O(|E|)
    for (int i=0; i<edges.size() && tree.size() < v-1; i++) {
        edge eg = edges[i];
        if (ds.find(eg.second.first) == ds.find(eg.second.second)) continue;
        ds.merge(eg.second.first, eg.second.second); // 까먹지 말기
        tree.push_back(eg);
        res += eg.first;
    }
    return res;
};

void showTree(vector<edge>& tree) {
    for (int i=0; i<tree.size(); i++)
        printf("%d %d\n", tree[i].second.first, tree[i].second.second);
    cout << endl;
}
int main() {
    cin >> v >> e;
    vector<edge> edges, tree;
    for (int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(mp(w,mp(a,b)));
    }
    long long sum = kruskal(edges, tree);
    showTree(tree);
    cout << sum << endl;
}
