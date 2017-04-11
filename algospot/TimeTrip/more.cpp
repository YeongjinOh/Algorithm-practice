////////////////////////////////////////////////////////////////////
// NOTE
//
// negative cycle이 있어도, start->end 상의 경로에 포함되지 않으면,
// path의 길이는 INFINITY가 아니다.
// -> reachable 을 구하여 해결.
// /////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
#define BIGENOUGH INF-1000000
using namespace std;
int C, n, m;
// get reachable indices
void dfs(int here, vector<bool>& reach, vector<vector<pair<int, int> > >& g) {
    reach[here] = true;
    for (int i=0; i<g[here].size(); i++) {
        int there = g[here][i].first;
        if (!reach[there])
            dfs(there, reach, g);
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n), gback(n);
    int a, b, c;
    for (int i=0; i<m; i++) {
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(make_pair(b,c));
        gback[b].push_back(make_pair(a,c));
    }
    vector<int> upper(n, INF), lower(n, -INF);
    upper[0] = 0; lower[0] = 0;
    // build reach
    vector<bool> reach0(n), reach1(n);
    dfs(0, reach0, g);
    dfs(1, reach1, gback);
    for (int i=0; i<n-1; i++) {
        // for all edges
        for (int here=0; here<n; here++) {
            for (int j=0; j<g[here].size(); j++) {
                int there = g[here][j].first, w = g[here][j].second;
                if (upper[here] + w < upper[there]) {
                    upper[there] = upper[here] + w;
                }
                if (lower[here] + w > lower[there]) {
                    lower[there] = lower[here] + w;
                }
            }
        }
    }
    bool updatedUpper = false, updatedLower = false;
    for (int here=0; here<n; here++) {
        for (int j=0; j<g[here].size(); j++) {
            int there = g[here][j].first, w = g[here][j].second;
            if (upper[here] + w < upper[there] && reach0[here] && reach1[there]) {
                updatedUpper = true;
            }
            if (lower[here] + w > lower[there] && reach0[here] && reach1[there]) {
                updatedLower = true;
            }
        }
    }

    if (upper[1] > BIGENOUGH) {
        cout << "UNREACHABLE" << endl;
        return;
    }
    if (updatedUpper) cout << "INFINITY ";
    else cout << upper[1] << " ";
    if (updatedLower) cout << "INFINITY" << endl;
    else cout << lower[1] << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
