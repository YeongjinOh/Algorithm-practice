#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LEN 20000
#define INF 987654321
vector<pair<int, int> > g[LEN];
int v, e;
// e = (from, to)
typedef pair<int, int> edge;

// O(|V|^2+|E|)
long long frim (vector<edge> & tree) {
    long long res = 0;

    // initialize
    vector<int> minDist(v+1, INF), parent(v+1, 0);
    vector<bool> visit(v+1, false);
    visit[1] = true;
    minDist[1] = 0;
    parent[1] = 1;
    for (int i=0; i<g[1].size(); i++) {
        int u = g[1][i].first, w = g[1][i].second;
        parent[u] = 1;
        minDist[u] = min<int>(minDist[u], w);
    }

    // assume that there exists MST
    for (int j=0; j<v-1; j++) { // O(|V|)
        int minIdx = 1, minD = INF;
        for (int i=1; i<=v; i++) { // O(|V|^2)
            if (!visit[i] && minDist[i] < minD) {
                minIdx = i;
                minD = minDist[i];
            }
        }
        visit[minIdx] = true;
        res += minD;
        tree.push_back(make_pair(parent[minIdx], minIdx));
        for (int i=0; i<g[minIdx].size(); i++) { // O(|E|)
            int there = g[minIdx][i].first, w = g[minIdx][i].second;
            if (!visit[there] && minDist[there] > w) {
                minDist[there] = w;
                parent[there] = minIdx;
            }
        }
    }
    return res;
}

int main() {
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        // assume that node indices start from 1
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }
    vector<edge> tree;
    long long sum = frim(tree);
//    for (int i=0; i<tree.size(); i++)
//        printf("%d %d\n", tree[i].first, tree[i].second);
    cout << sum << endl;
    return 0;
}
