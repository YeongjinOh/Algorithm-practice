#include <iostream>
#include <cstring>
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


int t;
int r, c;
bool done;

/* p :
 *      0
 * 3 [(i,j)] 1
 *      2
 */
bool reach(int p, int i, int j) {
    return (i==-1 && p==2) || (j==c && p==3) || (i==r && p==0) || (j==-1 && p==1);
}

pair<int,pii> getPos(int idx) {
    if (idx <= c) {
        return mp(0, mp(0, idx-1));
    } else if (idx <= c+r) {
        return mp(1, mp(idx-c-1, c-1));
    } else if (idx <= 2*c+r) {
        return mp(2, mp(r-1,2*c+r-idx));
    } else {
        return mp(3, mp(2*c+2*r-idx ,0));
    }
}

bool check(vector<vector<char> > &cur, vector<int> &love) {
    for (int l=1; l<love.size(); l++) {
        int a = l, b = love[l];
        pair<int,pii> curPos = getPos(a);
        int p = curPos.fi, i = curPos.se.fi, j = curPos.se.se;
        do {
//            printf("%d (%d,%d)\n", p, i, j);
            if (cur[i][j] == '/') {
                if (p == 0) {
                    p = 1; j--;
                } else if (p == 1) {
                    p = 0; i++;
                } else if (p == 2) {
                    p = 3; j++;
                } else {
                    p = 2; i--;
                }
            } else {
                if (p == 0) {
                    p = 3; j++;
                } else if (p == 1) {
                    p = 2; i--;
                } else if (p == 2) {
                    p = 1; j--;
                } else {
                    p = 0; i++;
                }
            }
//            printf("after %d (%d,%d)\n", p, i, j);
        } while (!reach(p, i, j));
//        printf("end of while\n");
        pair<int,pii> lastPos = getPos(b);
        if (p == 0) {
            p = 2; i--;
        } else if (p == 1) {
            p = 3; j++;
        } else if (p == 2) {
            p = 0; i++;
        } else {
            p = 1; j--;
        }
//        printf("a:%d b:%d (%d,(%d,%d)) -> (%d,(%d,%d)) but (%d,(%d,%d)) \n", a, b, curPos.fi, curPos.se.fi, curPos.se.se, lastPos.fi, lastPos.se.fi, lastPos.se.se, p, i, j);
        if (p != lastPos.fi || i != lastPos.se.fi || j != lastPos.se.se) return false;
    }
    return true;
}

void backtrack(vector<vector<char> > &cur, vector<vector<char> > &res, int i, int j, vector<int> &love) {
    if (done) return;
    if (j == c) {
        backtrack(cur, res, i+1, 0, love);
        return;
    }
    if (i == r) {
        if (check(cur, love)) {
            done = true;
            res = cur;
        }
        return;
    }
    cur[i][j] = '/';
    backtrack(cur, res, i, j+1, love);
    cur[i][j] = '\\';
    backtrack(cur, res, i, j+1, love);
}

void solve () {
    cin >> r >> c;
    int n = 2*(r+c);
    vector<int> love(n+1,0);
    for (int i=1; i<=n/2; i++) {
        int a, b;
        cin >> a >> b;
        love[a] = b;
        love[b] = a;
    }
    vector<vector<char> > res(r, vector<char>(c));
    vector<vector<char> > cur(r, vector<char>(c));
    done = false;
    backtrack(cur, res, 0, 0, love);
    if (done) {
        for (int i=0; i<res.size(); i++) {
            for (int j=0; j<res[i].size(); j++) {
                printf("%c", res[i][j]);
            }
            printf("\n");
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":" << endl;
        solve();
    }
    return 0;
}
