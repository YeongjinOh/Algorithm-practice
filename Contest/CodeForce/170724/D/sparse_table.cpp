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
#define LEN 100005
#define LOGLEN 333
int n, q;
vector<int> son[LEN];
int L[LEN], P[LEN];
int dp[LEN][LOGLEN];

void build_level() {
    int lv = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int n = q.size();
        for (int i=0; i<n; i++) {
            int node = q.front(); q.pop();
            L[node] = lv;
            for (int j=0; j<son[node].size(); j++) {
                q.push(son[node][j]);
            }
        }
        lv++;
    }
}

void build() {
    for (int i=1; i<=n; i++)
        dp[i][0] = P[i];
    for (int j=1; (1<<j)<=n; j++) {
        for (int i=1; i<=n; i++) {
            dp[i][j] = dp[ dp[i][j-1] ][j-1];
        }
    }
}

int LCA (int x, int y) {
    if (L[x] < L[y]) return LCA(y, x);

    // set same level
    int diff = L[x] - L[y];
    for (int i=0; diff; i++, diff>>=1) {
        if (diff & 1) {
            x = dp[x][i];
        }
    }
    if (x == y) return x;

    int bitCnt = 0;
    for (int i=L[x]; i>0; i>>=1) bitCnt++;
    for (int i=bitCnt-1; i>=0; i--) {
        if (dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

int main() {
    scanf("%d%d", &n, &q);
    P[1] = 1;
    for (int i=2; i<=n; i++) {
        scanf("%d", &P[i]);
        son[P[i]].pb(i);
    }
    build_level();
    build();
    while(q--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int res = 0;
        int a = LCA(x,y), b = LCA(y,z), c = LCA(z,x);
        if (a == b && b == c) {
            res = max(L[x], L[y]);
            res = max (res, L[z]);
            res = res-L[a]+1;
        } else {
            if (a==b) {
                res = max(L[x]-L[c]+1, L[z]-L[c]+1);
                res = max(res, L[c]-L[a]+L[y]-L[a]+1);
            } else if (b==c) {
                res = max(L[y]-L[a]+1, L[x]-L[a]+1);
                res = max(res, L[a]-L[b]+L[z]-L[b]+1);
            } else {
                res = max(L[z]-L[b]+1, L[y]-L[b]+1);
                res = max(res, L[b]-L[c]+L[x]-L[c]+1);
            }
        }
        cout << res<< endl;
    }
    return 0;
}
