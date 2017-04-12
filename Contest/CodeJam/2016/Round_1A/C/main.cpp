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
#define INF 5e18

#define LEN 1005
int parent[LEN], scc[LEN];
vector<int> child[LEN], scclist[LEN];
int sccId;
ll t, n, a, b, c;
///////////////////////////////////////////////////////////////
// solution은
// 1. length가 3 이상인 하나의 cycle로 이루어져있거나,
// 2. (length가2인 cycle과 그들의 longest path)의 합(모든 cycle(len=2)에 대해서)
//
///////////////////////////////////////////////////////////////

// cycle을 찾아 번호를 부여한다.
void dfs(int here) {
    // assume that scc[here] == -1
    scc[here] = 0;
    int nextScc = scc[parent[here]];
    if (nextScc == -1)
        dfs(parent[here]);
    else if (nextScc == 0) {
        sccId++;
        int cur = parent[here];
        while(scc[cur] == 0) {
            scc[cur] = sccId;
            scclist[sccId].pb(cur);
            cur = parent[cur];
        }
    }
    if (scc[here] == 0)
        scc[here] = -1;
}

// here를 root로 하는 maximal depth를 dfs방식으로 찾는다.
int maxLength(int here) {
    int res = 1;
    for (int i=0; i<child[here].size(); i++) {
        if (child[here][i] != parent[here])
            res = max<int> (res, 1+maxLength(child[here][i]));
    }
    return res;
}

void solve () {
    int n;
    cin >> n;
    // reset
    sccId = 0;
    for (int i=1; i<=n; i++) {
        child[i].clear();
        scclist[i].clear();
        scc[i] = -1;
    }
    for (int i=1; i<=n; i++) {
        scanf("%d",&parent[i]);
        child[parent[i]].pb(i);
    }
    for (int i=1; i<=n; i++) {
        if (scc[i] == -1)
            dfs(i);
    }
    int res = 0;
    int lengthTwo = 0;
    for (int i=1; i<=sccId; i++) {
        if (scclist[i].size() > 2)
            res = max<int>(res, scclist[i].size());
        else if (scclist[i].size() == 2) {
            lengthTwo += maxLength(scclist[i][0]);
            lengthTwo += maxLength(scclist[i][1]);
        }
    }
    res = max<int> (res, lengthTwo);
    cout << res;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
