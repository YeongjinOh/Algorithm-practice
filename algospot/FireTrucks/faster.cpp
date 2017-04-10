#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321

int C, v, e, n, m, va, vb, t;
int dist[1001];

void dijkstra(int source, const vector< vector<pair<int, int> > >&  a) {
    for (int i=1; i<=v; i++)
        dist[i] = INF;
    priority_queue<pair<int, int> > pq;
    dist[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty()) {
        int v = pq.top().second, vDist = pq.top().first;
        pq.pop();
        if (vDist > dist[v]) continue;
        for (int i=0; i<a[v].size(); i++) {
            int u = a[v][i].first, w = a[v][i].second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v]+w;
                pq.push(make_pair(-dist[u],u));
            }
        }
    }
}

void solve () {
    cin >> v >> e >> n >> m;
    vector< vector<pair<int, int> > > a(v+1);
    for (int i=0; i<e; i++) {
        cin >> va >> vb >> t;
        a[va].push_back(make_pair(vb,t));
        a[vb].push_back(make_pair(va,t));
    }
    vector<int> to, from;
    for (int i=0; i<n; i++) {
        cin >> va;
        to.push_back(va);
    }
    for (int i=0; i<m; i++) {
        cin >> vb;
        from.push_back(vb);
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<i; j++) {
            a[from[i]].push_back(make_pair(from[j], 0));
            a[from[j]].push_back(make_pair(from[i], 0));
        }
    }

    // dijkstra
    dijkstra(from[0], a);
    int ans = 0;
    for (int i=0; i<to.size(); i++)
        ans += dist[to[i]];
    cout << ans << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
