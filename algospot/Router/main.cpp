#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int C, n, m;

void solve() {
    cin >> n >> m;
    vector<vector<pair<int, double> > > a(n);
    int v, u;
    double w;
    for (int i=0; i<m; i++) {
        cin >> v >> u >> w;
        a[v].push_back(make_pair(u,w));
        a[u].push_back(make_pair(v,w));
    }

    // dijkstra
    vector<double> dist(n, -1);
    dist[0] = 1;
    priority_queue<pair<double,int> > pq;
    pq.push(make_pair(-1, 0));
    while(!pq.empty()) {
        double curDist = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v] > 0 && dist[v] < curDist) continue;

        for (int i=0; i<a[v].size(); i++) {
            int u = a[v][i].first;
            double w = a[v][i].second;
            if (dist[u] == -1 || dist[u] > curDist*w) {
                dist[u] = curDist*w;
                pq.push(make_pair(-dist[u], u));
            }
        }
    }
    printf("%.10lf\n", dist[n-1]);
}
int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
