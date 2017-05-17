#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
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
#define double long double // use long double when using bisection

int Agroup[1005], Bgroup[1005];
bool visit[1005];

bool dfs (vector<vector<int> >& g, int here) {
    if (visit[here]) return false;
    visit[here] = true;
    for (int i=0; i<g[here].size(); i++) {
        int there = g[here][i];
        if (Bgroup[there] == -1 || dfs(g, Bgroup[there])) {
            Agroup[here] = there;
            Bgroup[there] = here;
            return true;
        }
    }
    return false;
}


int t;
#define LEN 1005
vector<int> ticket[LEN];
void solve () {
    int n, m, c; cin >> n >> c >> m;
    for (int i=0; i<=c; i++) ticket[i].clear();
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        ticket[b].pb(a);
    }
    for (int i=1; i<=c; i++) sort(all(ticket[i]));
    int sz1 = ticket[1].size(), sz2 = ticket[2].size();

    vector<vector<int> > g(sz1);
    for (int i=0; i<ticket[1].size(); i++) {
        for (int j=0; j<ticket[2].size(); j++) {
            if (ticket[1][i] != ticket[2][j])
                g[i].pb(j);
        }
    }

    int size = 0;
    memset(Agroup, -1, sizeof(Agroup));
    memset(Bgroup, -1, sizeof(Bgroup));
    for (int i=0; i<sz1; i++) {
        memset(visit, false, sizeof(visit));
        if(dfs(g, i))
            size++;
    }
    vector<int> rem1, rem2;
    for (int i=0; i<sz1; i++) if (Agroup[i] == -1) rem1.pb(ticket[1][i]);
    for (int i=0; i<sz2; i++) if (Bgroup[i] == -1) rem2.pb(ticket[2][i]);
    int rsz1 = rem1.size(), rsz2 = rem2.size();
    if (rsz1 > 0 && rsz2 > 0) {
        if (rem1.back() == 1) {
            printf("%d %d", size + rsz1 + rsz2, 0);
        } else {
            printf("%d %d", size + max(rsz1, rsz2), min(rsz1, rsz2));
        }
    } else {
        printf("%d %d", size + max(rsz1, rsz2), 0);
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
        //        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
