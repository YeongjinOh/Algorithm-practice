#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define LEN 1000
#define INF 987654321

// vector<pair<int, int> > g[LEN];
// capacity, flow
int c[LEN][LEN], f[LEN][LEN];
int v, e;

// Ford-Fulkerson algorithm to calculate maxFlow
int maxFlow (int s, int t) {
    int totalFlow = 0;
    while(true) {
        // implement bfs from source to target
        queue<int> q;
        vector<bool> visit(v, false);
        vector<int> parent(v, -1);
        parent[s] = s;
        q.push(s);
        visit[s] = true;
        while(!q.empty() && !visit[t]) {
            int here = q.front(); q.pop();
            if (here == t) break;
            for (int there=0; there<v; there++) {
                if (!visit[there] && c[here][there]-f[here][there] > 0) {
                    parent[there] = here;
                    visit[there] = true;
                    q.push(there);
                }
            }
        }
        if (!visit[t]) break;
        // follow path to get minFlow
        int minFlow = INF;
        for(int here =t; here!= s; here = parent[here]) {
            minFlow = min<int>(minFlow, c[parent[here]][here]-f[parent[here]][here]);
        }
        // update
        totalFlow += minFlow;
        for(int here =t; here!= s; here = parent[here]) {
            f[parent[here]][here] += minFlow;
            f[here][parent[here]] -= minFlow; // IMPORTANT 유랑의 대칭성
        }
    }
    return totalFlow;
}

int main() {
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        c[a][b] = w;
    }
    int res = maxFlow(0, v-1);
    cout << res << endl;
    return 0;
}
