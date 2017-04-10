#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

queue<int> q;
vector<vector<pair<int,int> > > adj;
vector<bool> visit, edge; // visit node, visit edge
int n, k, d;
vector<int> cut;
void bfs () {
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        // visit
        for (int i=0; i<adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int e = adj[here][i].second;
            if (!visit[there]) {
                q.push(there);
                visit[there] = true; // 여기서 visit
                edge[e] = true;
            } else {
                if (!edge[e]) {
                    cut.push_back(e);
                    edge[e] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> k >> d;
    adj.resize(n+1);
    visit = vector<bool> (n+1, false);
    edge = vector<bool> (n+1, false);
    for (int i=0; i<k; i++) {
        int a;
        scanf("%d", &a);
        q.push(a);
        visit[a] = true;
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(make_pair(b,i+1));
        adj[b].push_back(make_pair(a,i+1));
    }
    bfs();
    cout << cut.size() << endl;
    for (int i=0; i<cut.size(); i++)
        printf("%d ", cut[i]);
    cout << endl;
}
