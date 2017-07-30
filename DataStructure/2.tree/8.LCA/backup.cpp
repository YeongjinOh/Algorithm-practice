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
void dfs_sq(int node, int nr)  {
    if (L[node] < nr)
        P[node] = 1;
    else
        if(!(L[node] % nr))
            P[node] = T[node];
        else
            P[node] = P[T[node]];
    for (int i=0; i<son[node].size(); i++) {
        int k = son[node][i];
        dfs_sq(k, nr);
    }
}
void build_sq() {
    for (int i=1; i<=n; i++)
        P[i] = T[i];
    int nr = 0, h=0;
    for (int i=2; i<=n; i++)
        h = max(h, L[i]);
    while (nr*nr < h) { nr++; }
    dfs_sq(1, nr);
}
int LCA_sq(int x, int y) {
    while (P[x] != P[y])
        if (L[x] > L[y])
            x = P[x];
        else
            y = P[y];
    while (x != y)
        if (L[x] > L[y])
            x = T[x];
        else
            y = T[y];
    return x;
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

    // find LCA
    for (int l=1; l<n; l++) {
        for (int r=l+1; r<=n; r++) {
            int lca = LCA_simple(l, r);
            int lca_sq = LCA_sq(l,r);
            if (lca != lca_sq) printf("Wrong : LCA_sq(%d,%d) = %d not %d\n", l, r, lca_sq, lca);
        }
    }
    return 0;
}
