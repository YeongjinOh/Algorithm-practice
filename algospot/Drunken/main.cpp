#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 501 // start from 1
#define ll long long
vector<pair<int, int> > g[MAX];
// drunken, max drunken in path i to j
ll d[MAX], maxd[MAX][MAX], fw[MAX][MAX]; // fw is shortest path from i to j

void build() {
    int v, e;
    cin >> v >> e;
    for (int i=1; i<=v; i++)
        scanf("%lld", d+i);
    for (int i=0; i<e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }
    ///////////////////////
    // Floyd-Warshall
    // ////////////////////
    long long INF = 1<<30;
    // initialize
    for (int i=1; i<=v; i++) {
        for (int j=1; j<=v; j++) {
            fw[i][j] = INF;
            maxd[i][j] = 0;
        }
        for (int j=0; j<g[i].size(); j++) {
            int there = g[i][j].first, w = g[i][j].second;
            fw[i][there] = w;
        }
    }

    for (int i=1; i<=v; i++)
        fw[i][i] = 0;

   for (int pass=1; pass<=v; pass++) {
        for (int from=1; from<=v; from++) {
            for (int to=1; to<=v; to++) {
                int md = max<int>(max<int>(maxd[from][pass], maxd[pass][to]), d[pass]);
                if (fw[from][to] + maxd[from][to] > fw[from][pass]+fw[pass][to] + md) {
                    fw[from][to] = fw[from][pass]+fw[pass][to];
                    maxd[from][to] = md;
                }
            }
        }
    }
   /////////////////////////////////////////////////////////////
   //
   // 거꾸로 한 번 더 돌렸더니 해결??
   //
   // Why?
   //
   //////////////////////////////////////////////////////////////
   for (int pass=v; pass>=1; pass--) {
        for (int from=1; from<=v; from++) {
            for (int to=1; to<=v; to++) {
                int md = max<int>(max<int>(maxd[from][pass], maxd[pass][to]), d[pass]);
                if (fw[from][to] + maxd[from][to] > fw[from][pass]+fw[pass][to] + md) {
                    fw[from][to] = fw[from][pass]+fw[pass][to];
                    maxd[from][to] = md;
                }
            }
        }
    }
}

void solve() {
    int from, to;
    cin >> from >> to;
    cout << fw[from][to] +  maxd[from][to] << endl;
}

int main() {
    build();
    int tc;
    cin >> tc;
    for (int c=1; c<=tc; c++) {
        solve();
    }
}
