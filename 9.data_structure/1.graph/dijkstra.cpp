#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 99999999

const int sz = 20001;  // size
vector<pair<int,int> > a[sz]; // adjacency list
int dist[sz]; // store shortest distance
bool visit[sz] = {0};

void Dijkstra(int source, int n) {
    for (int i=0; i<sz; i++)
        dist[i]=INF;
    class prioritize {
        public: bool operator () (pair<int, int>&p1, pair<int, int>&p2)
                { return p1.second>p2.second;}
    };
    priority_queue<pair<int, int>, vector<pair<int,int> >, prioritize> pq;
    dist[source] = 0;
    pq.push(make_pair(source,dist[source]));
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        int cv = curr.first, cu = curr.second;
        if (visit[cv])
            continue;
        visit[cv] = true;
        for (int i=0; i<a[cv].size(); i++) {
            int v = a[cv][i].first, w = a[cv][i].second;
            if(!visit[v] && cu + w < dist[v]) {
                dist[v] = cu + w;
                pq.push(make_pair(v,dist[v]));
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
