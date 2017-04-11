#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int C, n, m;
void solve() {
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n);
    int a, b, c;
    for (int i=0; i<m; i++) {
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(make_pair(b,c));
//        g[b].push_back(make_pair(a,c));
    }
    vector<int> upper(n, INF), lower(n, -INF);
    upper[0] = 0; lower[0] = 0;
    bool updatedUpper = true, updatedLower = true;;
    for (int i=0; i<n; i++) {
        updatedUpper = false;
        updatedLower = false;

        // for all edges
        for (int here=0; here<n; here++) {
            for (int j=0; j<g[here].size(); j++) {
                int there = g[here][j].first, w = g[here][j].second;
                if (upper[here] + w < upper[there]) {
                    upper[there] = upper[here] + w;
                    updatedUpper = true;
                }
                if (lower[here] + w > lower[there]) {
                    lower[there] = lower[here] + w;
                    updatedLower = true;
                }
            }
        }
        if (!updatedUpper && !updatedLower)
            break;
    }
    if (upper[1] > INF-1000000) {
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
