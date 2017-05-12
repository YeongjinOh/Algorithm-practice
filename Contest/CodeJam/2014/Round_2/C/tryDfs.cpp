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
#define INF 987654321
#define double long double // use long double when using bisection

int t;
int W, H, B;
vector<vector<bool> > cell;

int dfs(int i, int j) {
    if (i<0 || j<0 || j>=W || !cell[i][j]) return 0;
    cell[i][j] = false; // visit
    if (i == H-1) return 1;
    if (dfs(i, j-1)) return 1;
    if (dfs(i+1,j)) return 1;
    if (dfs(i, j+1)) return 1;
    if (dfs(i-1, j)) return 1;
    return 0;
}

void draw() {
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            printf("%d", cell[i][j]?0:1);
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int tc) {
    cin >> W >> H >> B;
    cell = vector<vector<bool> > (H, vector<bool> (W, true));
    for (int i=0; i<B; i++) {
        int X0, Y0, X1, Y1;
        cin >> X0 >> Y0 >> X1 >> Y1;
        for (int row=min(Y0,Y1); row<=max(Y0,Y1); row++) {
            for (int col=min(X0,X1); col<=max(X0,X1); col++) {
                cell[row][col] = false;
            }
        }
    }
    int res = 0;
    for (int i=0; i<W; i++) {
        if (dfs(0,i))
            res++;
    }
    cout << res << endl;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
