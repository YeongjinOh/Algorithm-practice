#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 501 // start from 1
#define ll long long
vector<pair<int, int> > g[MAX];
// drunken, max drunken in path i to j
ll d[MAX], sol[MAX][MAX], fw[MAX][MAX]; // fw is shortest path from i to j

void build() {
    int v, e;
    cin >> v >> e;
    vector<pair<int, int> > order;
    for (int i=1; i<=v; i++) {
        scanf("%lld", d+i);
        order.push_back(make_pair(d[i], i));
    }
    sort(order.begin(), order.end());
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
            sol[i][j] = INF;
        }
        for (int j=0; j<g[i].size(); j++) {
            int there = g[i][j].first, w = g[i][j].second;
            fw[i][there] = w;
            sol[i][there] = w;
        }
    }

    for (int i=1; i<=v; i++) {
        fw[i][i] = 0;
        sol[i][i] = 0;
    }

   /////////////////////////////////////////////////////////////
   //
   // pass의 순서를 바꿔도 Floyd-warshall 은 성립
   // d[pass]가 작은 순서대로 방문한다! -> Increasing order
   //
   //////////////////////////////////////////////////////////////
   for (int k=0; k<v; k++) {
       int pass = order[k].second;
        for (int from=1; from<=v; from++) {
            for (int to=1; to<=v; to++) {
//                int md = max<int>(max<int>(maxd[from][pass], maxd[pass][to]), d[pass]);
                fw[from][to] = min<ll>(fw[from][to], fw[from][pass]+fw[pass][to]);
                sol[from][to] = min<ll>(sol[from][to], fw[from][to] + d[pass]);
//                    maxd[from][to] = md;
            }
        }
    }
}

void solve() {
    int from, to;
    cin >> from >> to;
    cout << sol[from][to] << endl;
}

int main() {
    build();
    int tc;
    cin >> tc;
    for (int c=1; c<=tc; c++) {
        solve();
    }
}
