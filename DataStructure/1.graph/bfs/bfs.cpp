#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<vector<int> > adj;
vector<bool> visit;
int n, m;

vector<int> bfs (int start) {
    vector<int> order;
    visit[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        // visit
        order.push_back(here);
        for (int i=0; i<adj[here].size(); ++i) {
            int there = adj[here][i];
            if (!visit[there]) {
                q.push(there);
                visit[there] = true; // 여기서 visit
            }
        }
    }
    return order;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int> >(n);
    visit = vector<bool> (n, false);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> order = bfs(0);
    for (int i=0; i<order.size(); i++)
        printf("%d ", order[i]);
    cout << endl;
}
