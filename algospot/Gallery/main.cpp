#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, n, m, ans;
vector<bool> visit, done;
vector<vector<int> > adj;

bool dfs (int here) {
    visit[here] = true;
    bool hasFalseChild = false;
    for (int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visit[there]) {
            if(dfs(there))
                done[here] = true;
            if (!done[there])
                hasFalseChild = true;
        }
    }
    if (hasFalseChild) {
        done[here] = true;
        ans++;
        return true;
    }
    return false;
}

void solve() {
    ans = 0;
    for (int i=0; i<n; i++)
        if (!visit[i]) {
            dfs(i);
            if (!done[i]) ans++;
        }
    cout << ans << endl;
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n >> m;
        adj = vector<vector<int> >(n);
        done = visit = vector<bool>(n, false);
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        solve();
    }
}
