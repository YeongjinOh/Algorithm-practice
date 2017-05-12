#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
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
#define MOD 1000000007
int t;
int m, n;
void backtrack(vector<string> &strs, vector<vector<string> > &servers, int pos, int &res, int &maxCnt) {
    if (pos == m) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (servers[i].size() == 0) return;
            cnt++;
            unordered_set<string> s;
            for (int j=0; j<servers[i].size(); j++) {
                string &str = servers[i][j];
                for (int len=1; len<=str.size(); len++) {
                    if (s.find(str.substr(0,len)) == s.end()) {
                        cnt++;
                        s.insert(str.substr(0,len));
                    }
                }
            }
        }
        if (cnt == maxCnt) {
            res = (res + 1)%MOD;
        } else if (cnt > maxCnt) {
            maxCnt = cnt;
            res = 1;
        }
        return;
    }
    for (int i=0; i<n; i++) {
        servers[i].push_back(strs[pos]);
        backtrack(strs, servers, pos+1, res, maxCnt);
        servers[i].pop_back();
    }
}

void solve () {
    cin >> m >> n;
    vector<string> strs(m);
    for (int i=0; i<m; i++) cin>>strs[i];
    int res = 0, maxCnt = 0;
    vector<vector<string> > servers(n);
    backtrack(strs, servers, 0, res, maxCnt);
    cout << maxCnt << " " << res;
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
