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

// read string parsed by white space
void readStrings() {
    int n; cin >> n;
    char buffer[10000];
    gets(buffer);
    vector<vector<string> > sentances(n);
    for (int i=0; i<n; i++) {
        gets(buffer);
        string word = buffer;
        istringstream ss(word);
        while (ss >> word) sentances[i].push_back(word);
    }
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
    int rol = 0, pro = 0;
    while (true) {
        priority_queue<pair<pii, pair<int, bool> > > pq; // ( (maxTicket, cnt), (idx, promoted) )
        // push maximal tickets
        for (int i=1; i<=c; i++) {
            int sz = ticket[i].size();
            if (sz > 0) {
                pq.push(mp(mp(ticket[i].back(), sz), mp(i,false)));
            }
        }
        if (pq.empty()) break;
        int maxVal = 999999;
        while (!pq.empty()) {
            int curTicket = pq.top().fi.fi, sz = pq.top().fi.se, idx = pq.top().se.fi;
            bool promoted = pq.top().se.se;
            printf("( (%d,%d), (%d,%d) )\n", curTicket, sz, idx, promoted?1:0);
            pq.pop();
            if (curTicket == 0) break;
            if (curTicket >= maxVal) {
                curTicket = maxVal-1;
                promoted = true;
                pq.push(mp(mp(curTicket, sz), mp(idx, promoted)));
                continue;
            }
            maxVal = curTicket;
            ticket[idx].pop_back();
            if (promoted) pro++;
        }
        rol++;
    }
    vector<vector<bool> > ck(rol, vector<bool> (n+1, false));
    int res = 0;
    for (int i=1; i<=c; i++) {
        for (int j=0; j<ticket[i].size(); j++) {
            for (int k=0; k<rol; k++) {
                if (ck[k][ticket[i][j]] == false) {
                    ck[k][ticket[i][j]] = true;
                    res++;
                    break;
                }
            }
        }
    }
    printf("%d %d", rol, m-res);
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
