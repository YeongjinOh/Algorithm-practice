#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int C;
void solve() {
    int v, n, m;
    cin >> v >> n >> m;
    vector<vector<pair<int, int> > > g(v);
    for (int i=0; i<n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }
    // Floyd-warshall
    vector<vector<int> > fw(v, vector<int> (v, INF));
    for (int i=0; i<v; i++) {
        for (int j=0; j<g[i].size(); j++) {
            int there = g[i][j].first, w = g[i][j].second;
            fw[i][there] = min<int>(fw[i][there], w);
        }
        fw[i][i] = 0;
    }
    for (int p=0; p<v; p++) {
        for (int f=0; f<v; f++) {
            for (int t=0; t<v; t++) {
                if (fw[f][t] > fw[f][p] + fw[p][t])
                    fw[f][t] = fw[f][p] + fw[p][t];
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        // if useful, use and update fw
        if (fw[a][b] > w) {
            fw[a][b] = w;
            fw[b][a] = w;
            for (int f=0; f<v; f++) {
                for (int t=0; t<v; t++) {
                    if (fw[f][t] > fw[f][a] + fw[a][t])
                        fw[f][t] = fw[f][a] + fw[a][t];
                    if (fw[f][t] > fw[f][b] + fw[b][t])
                        fw[f][t] = fw[f][b] + fw[b][t];
                }
            }
        } else {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
