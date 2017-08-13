#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
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
#define INF 5e18

int n;
vector<int> g[100005];
void dfs (int parent, int cur, double &res, double p) {
//    printf("parent:%d cur:%d res:%.2lf p:%.2lf\n", parent, cur, res, p);
    res += p;
    int numOfChild = g[cur].size()-1;
    p /= numOfChild;
    for (int i=0; i<g[cur].size(); i++) {
        int child = g[cur][i];
        if (child == parent) continue;
        dfs(cur, child, res, p);
    }
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    g[1].pb(0);
    double res = 0.0;
    dfs (0, 1, res, 1.0);
    printf("%.20lf\n",  res - 1.0);
    return 0;
}
