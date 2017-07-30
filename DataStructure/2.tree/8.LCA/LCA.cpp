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

int n, q;
int P[LEN], T[LEN], L[LEN]; // preprocessing, father, level
vector<int> son[LEN];

void build_level() {
    // start from 1
    int lv = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int n = q.size();
        for (int i=0; i<n; i++) {
            int node = q.front(); q.pop();
            L[node] = lv;
            for (int j=0; j<son[node].size(); j++) {
                int child = son[node][j];
                q.push(child);
            }
        }
        lv++;
    }
}

// 1. LCA simple (just follow up parent)
// Time(query) : O(h) = O(n) (in worst)
int LCA_simple(int x, int y) {
    if (x == y) return x;
    if (L[x] == L[y]) {
        return LCA_simple(T[x], T[y]);
    } else if (L[x] < L[y]) return LCA_simple(x, T[y]);
    return LCA_simple(T[x], y);
}

// 2. Squre Root Decomposition
// Time(build) : O(n)
// Time(query) : O(sqrt(n))
int nr = 0;
void dfs_sq(int node)  {
    if (node == 1) P[node] = 1;
    else if (L[node] % nr == 0) {
        // To avoid loop, set parents instead of itself
        P[node] = T[node];
    } else {
        P[node] = P[T[node]];
    }
    for (int i=0; i<son[node].size(); i++) {
        dfs_sq(son[node][i]);
    }
}
void build_sq() {
    int maxh = 0;
    for (int i=1; i<=n; i++) maxh = max(maxh, L[i]);
    while (nr*nr < maxh) { nr++; }
    dfs_sq(1);
}
int LCA_sq(int x, int y) {
    while (P[x] != P[y]) {
        if (L[x] < L[y])
            y = P[y];
        else
            x = P[x];
    }
    while (x != y) {
        if (L[x] < L[y])
            y = T[y];
        else
            x = T[x];
    }
    return x;
}
// 3. Sparse Table
// Time(build) : O(nlogn)
// Time(query) : O(logn)
// Space : O(nlogn)
vector<vector<int> > dp; // dp[i][j] =  2^j-th ancestor of i.
void build_st() {
    int logn = 0;
    while (1<<logn < n) {logn++;}
    dp = vector<vector<int> > (n+1, vector<int> (logn));
    for (int i=1; i<=n; i++) dp[i][0] = T[i];
    for (int j=1; j<=logn; j++) {
        for (int i=1; i<=n; i++) {
//            if (dp[i][j-1] != -1) // *** IMPORTANT
                dp[i][j] = dp[ dp[i][j-1] ][j-1];
        }
    }
}

int LCA_st(int x, int y) {
    // suppose that L[x] >= L[y]
    if (L[x] < L[y]) return LCA_st(y, x);

    // set the same level
    int diff = L[x] - L[y];
    for (int j=0; diff; j++, diff>>=1) {
        if (diff&1) {
            x = dp[x][j];
        }
    }
    if (x == y) return x;

    int bitCnt = 0;
    for (int i = L[x]; i; i >>= 1)
        bitCnt++;

    for (int i = bitCnt - 1; i >= 0; i--) {
        if (dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return T[x];
}


int main() {
    //get input
    scanf("%d", &n);
    // Assumption : number 1 is root. so we get the number of parent of each node from number 2
    T[1] = P[1] = 1;
    for (int i=2; i<=n; i++) {
        scanf("%d", &T[i]);
        son[T[i]].pb(i);
    }

    // build
    build_level();
    build_sq();
    build_st();

    // find LCA
    for (int l=1; l<n; l++) {
        for (int r=l+1; r<=n; r++) {
            int lca = LCA_simple(l, r);
            int lca_sq = LCA_sq(l,r);
            if (lca != lca_sq) printf("Wrong : LCA_sq(%d,%d) = %d not %d\n", l, r, lca_sq, lca);
            int lca_st = LCA_st(l,r);
            if (lca != lca_st) printf("Wrong : LCA_st(%d,%d) = %d not %d\n", l, r, lca_st, lca);
        }
    }
    return 0;
}
