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

int n, m;
string a[1005];
int main() {
    scanf("%d%d", &n, &m);
    rep(i,0,n) cin >> a[i];
    int xs, ys, xt, yt;
    rep(i,0,n) rep(j,0,m) {
        if (a[i][j] == 'S') {
            xs = j; ys = i;
        } else if (a[i][j] == 'T') {
            xt = j; yt = i;
        }
    }
    int minX = min<int>(xs, xt), maxX = max<int>(xs, xt);
    int minY = min<int>(ys, yt), maxY = max<int>(ys, yt);
    vector<int> vert, hori;
    // vertical
    rep(j, 0, m) {
        bool has = false;
        for (int i = minY; i <= maxY; i++) {
            if (a[i][j] == '*') has = true;
        }
        if (!has) vert.pb(j);
    }
    rep(i, 0, n) {
        bool has = false;
        for (int j = minX; j <= maxX; j++) {
            if (a[i][j] == '*') has = true;
        }
        if (!has) hori.pb(i);
    }
    for (int i=0; i<vert.size(); i++) {
        int stop = vert[i];
        bool has = false;
        for (int x = min<int>(xs, stop); x<= max<int>(xs, stop); x++) if (a[ys][x] == '*') has = true;
        for (int x = min<int>(xt, stop); x<= max<int>(xt, stop); x++) if (a[yt][x] == '*') has = true;
        if (!has) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i=0; i<hori.size(); i++) {
        int stop = hori[i];
        bool has = false;
        for (int y = min<int>(ys, stop); y<= max<int>(ys, stop); y++) if (a[y][xs] == '*') has = true;
        for (int y = min<int>(yt, stop); y<= max<int>(yt, stop); y++) if (a[y][xt] == '*') has = true;
        if (!has) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
