#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 10
#define vi vector<int>

vi adj[MAX];
vector<bool> visit;
int n, m;

void dfs (int here) {
    visit[here] = true;
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visit[there])
            dfs(there);
    }
    cout << "visit " << here << endl;
}

void dfsAll() {
    visit = vector<bool>(n, false);
    cout << "reverse of topological sort : " << endl;
    for (int i=0; i<n; i++)
        if (!visit[i])
            dfs(i);
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsAll();

}
