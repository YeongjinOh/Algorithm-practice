#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 99999999
#define pb push_back
#define mp make_pair
const int sz = 20001;  // size
vector<pair<int,int> > a[sz]; // adjacency list
int dist[sz]; // store shortest distance

void Dijkstra(int source, int n) {
    for (int i=1; i<=n; i++)
        dist[i] = INF;
    priority_queue<pair<int, int> > pq;
    // -w, v
    dist[source] = 0;
    pq.push(mp(0,source));
    while(!pq.empty()) {
        pair<int, int> t = pq.top(); pq.pop();
        int curDist = -t.first;
        int v = t.second;
        // ignore if bigger than the one already found
        if (curDist > dist[v]) continue;
        for (int i=0; i<a[v].size(); i++) {
            // u is next node / w is w(v,u)
            int u = a[v][i].first, w = a[v][i].second;
            if (dist[u] > curDist + w) {
                dist[u] = curDist + w;
                pq.push(mp(-dist[u],u));
            }
        }
    }
}

int main() {
    int n, m, x, y, w, source;
    cin >> n >> m >> source;
    for (int i=0; i<m; i++) {
        cin >> x >> y >> w;
        a[x].push_back(make_pair(y,w));
        //a[y].push_back(make_pair(x,w));

    }

    Dijkstra(source,n);
    for (int i=1; i<=n; i++) {
        int cur = dist[i];
        if (cur == INF)
            printf("INF\n");
        else
            printf("%d\n", cur);
    }

    return 0;
}
