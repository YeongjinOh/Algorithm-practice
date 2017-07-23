#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, na, nb;
bool pos[10][10];
int nodeId[2][10][10];
// bipartite graph
vector<vector<int> > bp;
int dx[2] = {1, -1}, dy[2] = {1, 1};
vector<int> Agroup, Bgroup;

// visit
vector<bool> visit;
// here에서 시작하는 증가 경로를 찾을 수 있는지 여부를 리턴
bool dfs(int here) {
    // 이번 cycle에서 이미 here를 방문했으면 -> 무한 루프
    if (visit[here]) return false;
    visit[here] = true;
    for (int i=0; i<bp[here].size(); i++) {
        int there = bp[here][i];
        if (Bgroup[there] == -1 || dfs(Bgroup[there])) {
            Agroup[here] = there;
            Bgroup[there] = here;
            return true;
        }
    }
    return false;
}

void solve () {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        char c;
        cin >> c;
        pos[i][j] = c == '.';
    }
    memset(nodeId,-1,sizeof(nodeId));
    int cnt[2] = {0,0};
    for (int k=0; k<2; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int x=j, y=i;
                while(x>=0 && x<=n && y>=0 && y<=n && pos[y][x] && nodeId[k][y][x] == -1) {
                    nodeId[k][y][x] = cnt[k];
                    x += dx[k];
                    y += dy[k];
                }
                if (x != j) {
                    cnt[k]++;
                }
            }
        }
    }
    na = cnt[0], nb = cnt[1];
    // build bipartite graph
    bp.clear(); bp.resize(na);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (nodeId[0][i][j] != -1)
                bp[nodeId[0][i][j]].push_back(nodeId[1][i][j]);
        }
    }

    Agroup = vector<int>(na,-1);
    Bgroup = vector<int> (nb, -1);
    int res = 0;
    for (int i=0; i<na; i++) {
        visit = vector<bool>(na,false);
        if (dfs(i))
            res++;
    }
    cout << res << endl;
}
int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
