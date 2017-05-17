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

int t, r, c;
int house[5][50];

void backtrack(vector<pii> &und, int pos);
// dir : left, up, right, down
int find (int i, int j, int dir) {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int res = 1; // 1 means wall, 2 measn beam
    while(true) {
        i += dy[dir];
        j += dx[dir];
        if (i < 0 || i >= r || j < 0 || j >= c) break;
        if (house[i][j] == 1) return 1;
        else if (house[i][j] >= 2) return 2;
    }
    return res;
}

pii findBeam (int i, int j, int dir) {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    pii res = mp(-1,-1);
    while(true) {
        i += dy[dir];
        j += dx[dir];
  //      if (i < 0 || i >= r || j < 0 || j >= c) break;
        if (house[i][j] >= 2) {
            res = mp(i,j);
            break;
        }
    }
    return res;
}

bool done;

void solve () {
    cin >> r >> c;
    vector<string> strs(r);
    for (int i=0; i<r; i++) cin >> strs[i];
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (strs[i][j] == '.') house[i][j] = 0;
            else if (strs[i][j] == '#') house[i][j] = 1;
            else house[i][j] = 2; // 2 undefined, 3 horizontal, 4 vertical
        }
    }
    int cnt = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (house[i][j] != 0) continue;
            int left = find(i,j,0);
            int up = find(i,j,1);
            int right = find(i,j,2);
            int down = find(i,j,3);
            if (left == right && up == down) {
                cout << "IMPOSSIBLE"; return;
            } else if (left != right) {
                pii p;
                if (left == 2)
                    p = findBeam(i,j,0);
                else
                    p = findBeam(i,j,2);
                if (house[p.fi][p.se] == 4) {
                    cout << "IMPOSSIBLE"; return;
                }
                house[p.fi][p.se] = 3;
            } else if (up != down) {
                pii p;
                if (up == 2)
                    p = findBeam(i,j,1);
                else
                    p = findBeam(i,j,3);
                if (house[p.fi][p.se] == 3) {
                    cout << "IMPOSSIBLE"; return;
                }
                house[p.fi][p.se] = 4;
            }
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (house[i][j] < 2) continue;
            int left = find(i,j,0);
            int up = find(i,j,1);
            int right = find(i,j,2);
            int down = find(i,j,3);
            bool vert = (up == 2 || down == 2), hori = (left == 2 || right == 2);
            if (vert && hori) {
                cout << "IMPOSSIBLE"; return;
            }
            if (house[i][j] == 3 && hori) {
                cout << "IMPOSSIBLE"; return;
            }
            if (house[i][j] == 4 && vert) {
                cout << "IMPOSSIBLE"; return;
            }
        }
    }
    vector<pii> und; // undefined
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (house[i][j] == 2) {
                und.pb(mp(i,j));
            }
        }
    }
    done = false;
    backtrack(und, 0);
    if (!done)
        cout << "IMPOSSIBLE";
}

char getChar (int n) {
    if (n == 0) return '.';
    if (n == 1) return '#';
    if (n == 3) return '-';
    return '|';
}
void backtrack(vector<pii> &und, int pos) {
    if (done) return;
    if (und.size() == pos) {
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (house[i][j] == 1) continue;
                int left = find(i,j,0);
                int up = find(i,j,1);
                int right = find(i,j,2);
                int down = find(i,j,3);
                if (house[i][j] == 0)
                    if (left != 2 && up != 2 && right != 2 && down != 2) return;
                if (house[i][j] == 3)
                    if (left == 2 || right == 2) return;
                if (house[i][j] == 4)
                    if (up == 2 || down == 2) return;
            }
        }
        done = true;
        cout << "POSSIBLE";
        for (int i=0; i<r; i++) {
            cout << endl;
            for (int j=0; j<c; j++) {
                printf("%c", getChar(house[i][j]));
            }
        }
        return;
    }
    pii cur = und[pos];
    int &curHouse = house[cur.fi][cur.se];
    curHouse = 3;
    backtrack(und, pos+1);
    curHouse = 4;
    backtrack(und, pos+1);
    curHouse = 2;
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
