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
int P[LEN], T[LEN], L[LEN];
vector<int> son[LEN];
void dfsL(int i, vector<bool> &visit) {
    if (!visit[T[i]]) {
        dfsL(T[i], visit);
    }
    visit[i] = true;
    L[i] = L[T[i]]+1;
}

void dfs(int node, int n, int nr)  {
    if (L[node] < nr)
        P[node] = 1;
    else
        if(!(L[node] % nr))
            P[node] = T[node];
        else
            P[node] = P[T[node]];
    for (int i=0; i<son[node].size(); i++) {
        int k = son[node][i];
        dfs(k, n, nr);
    }
}

int LCA(int x, int y) {
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
    scanf("%d%d", &n, &q);
    P[1] = 1;
    for (int i=2; i<=n; i++) {
        scanf("%d", &P[i]);
        son[P[i]].pb(i);
    }
    for (int i=1; i<=n; i++) {
        T[i] = P[i];
    }
    L[1] = 0;
    vector<bool> visit(n, false);
    visit[1] = true;
    for (int i=2; i<=n; i++) {
        if (!visit[i]) {
            visit[i] = true;
            dfsL(i, visit);
        }
    }
    int nr = 0, h=0;
    for (int i=2; i<=n; i++)
        h = max(h, L[i]);
    while (nr*nr < h) {nr++;}
    dfs(1,n,nr);
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
