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
int T[LEN], L[LEN];
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

// LCA simple (just follow up parent)
// Time : O(h) - Time over for this problem
int LCA(int x, int y) {
    if (x == y) return x;
    if (L[x] == L[y]) {
        return LCA(T[x], T[y]);
    } else if (L[x] < L[y]) return LCA(x, T[y]);
    return LCA(T[x], y);
}

int main() {
    scanf("%d%d", &n, &q);
    T[1] = 1;
    for (int i=2; i<=n; i++) {
        scanf("%d", &T[i]);
        son[T[i]].pb(i);
    }
    build_level();
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
