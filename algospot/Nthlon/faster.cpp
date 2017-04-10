///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// NOTE
//
// 같은 개념을 dijkstra를 이용하여 최적화 해보자.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
int C;
void solve() {
    int m;
    cin >> m;
    int t[2][500];
    for (int i=0; i<m; i++)
        scanf("%d%d", &t[0][i], &t[1][i]);
    // -200~200
    vector<pair<int, int> > a[401];
    for (int i=0; i<m; i++) {
        int sub = t[0][i] - t[1][i];
        for (int j=0; j<401; j++) {
            if (j+sub >=0 && j+sub <=400)
                a[j].push_back(make_pair(j+sub,t[0][i]));
        }
    }

    // dijkstra
    vector<int> dist(401, INF);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 200));
    while(!pq.empty()) {
        int curDist = -pq.top().first, here = pq.top().second;
        pq.pop();
        if (dist[here] < curDist) continue;
        for (int i=0; i<a[here].size(); i++) {
            int there = a[here][i].first, w = a[here][i].second;
            if (curDist+w < dist[there]) {
                dist[there] = curDist + w;
                pq.push(make_pair(-dist[there],there));
            }
        }

    }
    int ans = dist[200];
    if (ans >= INF) cout << "IMPOSSIBLE" << endl;
    else    cout << ans << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
