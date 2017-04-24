#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INFDB 1e30
#define INF (long long)9876543210

int n, q;
double dw[105][105];
int s[105], e[105]; // constant speed s, maximal distance e
int w[105][105];

// return false if there exists negative cycle
bool BellmanFord(int source) {
    long long upper[105];
    for (int i=0; i<n; i++)
        upper[i] = INF;
    upper[source] = 0;

    // relax |V|-1 times
    // 먼저 최단거리
    for (int i=0; i<n; i++) {
        for (int v=0; v<n; v++) {
            for (int u=0; u<n; u++) {
                if (w[v][u] > 0 && upper[u] > upper[v] + w[v][u]) {
                    upper[u] = upper[v] + w[v][u];
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (upper[i] <= e[source]) {
            dw[source][i] = (double)upper[i]/(double)s[source];
        }
    }
    return true;
}

void solve () {
    cin >> n >> q;
    for (int i=0; i<n; i++) scanf("%d%d", &e[i], &s[i]);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", &w[i][j]);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) dw[i][j] = 1e20;
    for (int i=0; i<n; i++) BellmanFord(i);

    // floyd-warshall array
    for (int i=0; i<n; i++)
        dw[i][i] = 0;
    // build
    for (int pass=0; pass<n; pass++) {
        for (int from=0; from<n; from++) {
            for (int to=0; to<n; to++) {
                if (dw[from][to] > dw[from][pass] + dw[pass][to]) {
                    dw[from][to] = dw[from][pass] + dw[pass][to];
                }
            }
        }
    }
   while(q--) {
        int u, v;
        cin >> u >> v;
        printf("%.9lf ", dw[u-1][v-1]);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
