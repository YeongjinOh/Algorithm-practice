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
ll n, k, l, r, a, b;

struct ds {
    vector<int> parent, rk, size;
    ds(int n) : parent(n), rk(n, 1), size(n, 1) {
        for (int i=0; i<n; i++)
            parent[i] = i;
    }
    int find(int u) const {
        if (u == parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v= find(v);
        if (u == v) return;
        if (rk[u] > rk[v]) swap(u,v);
        parent[u] = v;
        if (rk[u] == rk[v]) ++rk[v];
        size[v] += size[u];
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    ds d(n+1);
    int a, b;
    for (int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        d.merge(a,b);
    }
    ll cnt = 0;
    for (int i=1; i<=n; i++) {
        if (i == d.parent[i] && d.size[i] > 1) {
            ll sz = (ll)d.size[i];
            cnt += (sz-1)*sz/2;
        }
    }
    if (cnt == m)
        printf("YES\n");
    else
        printf("NO\n");


    return 0;
}
