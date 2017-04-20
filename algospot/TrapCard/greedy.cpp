#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;
string t[25];
int tId[25][25];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    memset(tId, -1, sizeof(tId));
    int id = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if(t[i][j] == '.') tId[i][j] = id++;
    vector<vector<int> > g(id);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (tId[i][j] >= 0) {
                if (tId[i+1][j] >= 0) {
                    g[tId[i][j]].push_back(tId[i+1][j]);
                    g[tId[i+1][j]].push_back(tId[i][j]);
                }
                if (tId[i][j+1] >= 0) {
                    g[tId[i][j]].push_back(tId[i][j+1]);
                    g[tId[i][j+1]].push_back(tId[i][j]);
                }
            }
        }
    for (int i=0; i<id; i++)
        sort(g[i].begin(), g[i].end());
    int cnt = 0;
    vector<bool> alive (id, true);
    while (true) {
        int maxSize = 0, maxIdx= -1;
        for (int i=0; i<id; i++) {
            if (g[i].size() > maxSize) {
                maxSize = g[i].size();
                maxIdx = i;
            }
        }
        if (maxSize == 0)
            break;
        cnt++;
        alive[maxIdx] = false;
        for (int i=0; i<g[maxIdx].size(); i++) {
            int there = g[maxIdx][i];
            g[there].erase(find(g[there].begin(), g[there].end(), maxIdx));
        }
        g[maxIdx].clear();
   }
    printf("%d\n", id-cnt);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (tId[i][j] >= 0 && alive[tId[i][j]])
                t[i][j] = '^';
            printf("%c",t[i][j]);
        }
        cout << endl;
    }
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
