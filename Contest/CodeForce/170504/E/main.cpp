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
#define LEN 300005
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    vector<set<int> > g(m+1);
    for (int v=1; v<=n; v++) {
        int s, t;
        scanf("%d", &s);
        vector<int> ice;
        for (int j=0; j<s; j++) {
            scanf("%d", &t);
            ice.push_back(t);
        }
        for (int i=0; i<ice.size(); i++) {
            for (int j=0; j<ice.size(); j++) {
                g[ice[i]].insert(ice[j]);
            }
        }
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
    }
    vector<int> res(m+1,-1);
    int maxCol = 0;
    for (int v = 1; v <= m; v++) {
        vector<bool> used(m+1,false);
        for (auto it = g[v].begin(); it != g[v].end(); it++) {
            int u = *it;
            if (res[u] != -1)
                used[res[u]] = true;
        }
        int cr;
        for (cr = 1; cr <= m; cr++)
            if (used[cr] == false)
                break;

        res[v] = cr;
        maxCol = max<int>(maxCol, cr);
    }

    printf("%d\n", maxCol);
    for (int v=1; v<=m; v++)
        printf("%d ", res[v]);
    return 0;
}
