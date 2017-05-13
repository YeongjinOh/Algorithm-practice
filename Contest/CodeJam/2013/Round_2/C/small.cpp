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

int t, n;
int a[25], b[25];
bool done;
void backtrack(vector<int> &cur, vector<bool> &visit, vector<int> &res) {
    int idx = cur.size();
    if (done) return;
    for (int i=0; i<idx-1; i++) {
        if (cur[i] > cur[idx-1] && b[i] <= b[idx-1]) return;
    }
    if (idx == n) {
        // check b
        for (int i=n-1; i>=0; i--) {
            int dis = 1;
            for (int j=n-1; j>i; j--) {
                if (cur[i] > cur[j])
                    dis = max(dis, b[j]+1);
            }
            if (dis != b[i]) return;
        }
        res = cur;
        done = true;
    }
    for (int i=max(0,b[idx]-1); i<n; i++) {
        if (!visit[i]) {
            int lis = 1;
            for (int j=0; j<idx; j++) {
                if (cur[j] < i)
                    lis = max(lis, a[j]+1);
            }
            if (a[idx] == lis) {
                visit[i] = true;
                cur.pb(i);
                backtrack(cur,visit,res);
                cur.pop_back();
                visit[i] = false;
            }
            if (b[idx] == 1) return;
        }
    }
}

void solve () {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    vector<int> cur, res(n,0);
    vector<bool> visit(n, false);
    done = false;
    backtrack(cur, visit, res);
    for (int i=0; i<n; i++) cout << (res[i]+1) << " ";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
