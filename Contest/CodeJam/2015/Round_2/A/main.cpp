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

/*
   . period = no arrow
   ^ caret = up arrow
   > greater than = right arrow
   v lowercase v = down arrow
   < less than = left arrow
   */


int t, R, C;
string road[105];

void solve () {
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        cin >> road[i];
    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (road[i][j] != '.') {
                int cnt = 0;
                for (int k=0; k<R; k++) if (road[k][j] != '.') cnt++;
                for (int k=0; k<C; k++) if (road[i][k] != '.') cnt++;
                if (cnt == 2) {
                    cout << "IMPOSSIBLE";
                    return;
                }
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cnt++;
            switch(road[i][j]) {
                case '^':
                    for (int k=0; k<i; k++) {
                        if (road[k][j] != '.') { cnt--; break; }
                    }
                    break;
                case '>':
                    for (int k=j+1; k<C; k++)
                        if (road[i][k] != '.') { cnt--; break; }
                    break;
                case '<':
                    for (int k=0; k<j; k++)
                        if (road[i][k] != '.') { cnt--; break; }
                    break;
                case 'v':
                    for (int k=i+1; k<R; k++)
                        if (road[k][j] != '.') { cnt--; break; }
                    break;
                default:
                    cnt--;
            }
        }
    }
    cout << cnt;
    return;
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
