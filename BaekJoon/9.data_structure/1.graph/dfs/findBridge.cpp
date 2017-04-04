/////////////////////////////////////////////////
//
// find bridge (p. 857)
//
/////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > adj;
vector<pair<int, int> > bridge;
vector<int> visit, cutVertex;
int n, m, cnt = 1;

// find cut vertex
// return minimal visit of ancestor (except parent)
// parent로 곧장 올라가는 간선을 제외하고, minimal visit을 구한다.
int findBridge (int here, int parent = -1) {
    visit[here] = cnt++;
    int ret = visit[here];
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visit[there]) {
            int cur = findBridge(there, here);
            ret = min<int>(ret, cur);
            if (cur > visit[here]) {
                bridge.push_back(make_pair(here,there));
            }
        } else if (there != parent) {
            ret = min<int>(ret, visit[there]);
        }
    }
    return ret;
}

void dfsAll() {
    visit = vector<int>(n,0);
    for (int i=0; i<n; i++)
        if (!visit[i])
            findBridge(i);
}


int main() {
    cin >> n >> m;
    adj = vector<vector<int> >(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsAll();

    // print all bridges
    for (int i=0; i<bridge.size(); i++)
        printf("(%d,%d)\n", bridge[i].first, bridge[i].second);
}
