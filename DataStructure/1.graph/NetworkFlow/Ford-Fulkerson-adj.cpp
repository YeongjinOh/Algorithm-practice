#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define LEN 1000
#define INF 987654321

// vector<pair<int, int> > g[LEN];
// capacity, flow
// int c[LEN][LEN], f[LEN][LEN];
vector<pair<int, int> > c[LEN];
map<pair<int,int>, int> cHash, f;
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
            for (int i=0; i<c[here].size(); i++) {
                int there = c[here][i].first;
                int capacity = c[here][i].second;
                if (!visit[there] && capacity - f[make_pair(here,there)] > 0) {
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
            minFlow = min<int>(minFlow, cHash[make_pair(parent[here],here)]-f[make_pair(parent[here],here)]);
        }
        // update
        totalFlow += minFlow;
        for(int here =t; here!= s; here = parent[here]) {
            f[make_pair(parent[here],here)] += minFlow;
            f[make_pair(here,parent[here])] -= minFlow; // IMPORTANT 유랑의 대칭성
        }
    }
    return totalFlow;
}

int main() {
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        c[a].push_back(make_pair(b,w));
        cHash[make_pair(a,b)] = w;
    }
    int res = maxFlow(0, v-1);
    cout << res << endl;
    return 0;
}
