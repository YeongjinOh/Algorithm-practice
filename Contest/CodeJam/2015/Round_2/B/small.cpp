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
void solve () {
    int n;
    double V, X;
    double v[105], x[105];
    cin >> n >> V >> X;
    for (int i=0; i<n; i++)
        cin >> v[i] >> x[i];
    if (n == 1) {
        if (X == x[0]) {
            printf("%.9lf", V/v[0]);
            return;
        } else {
            printf("IMPOSSIBLE");
            return;
        }
    } else if (n == 2) {
        if (x[0] > x[1]) {
            swap(v[0],v[1]);
            swap(x[0],x[1]);
        }
        if (X < x[0] || x[1] < X) {
            printf("IMPOSSIBLE");
            return;
        }
        if (x[0] == x[1]) {
            printf("%.9lf", V/(v[0]+v[1]));
            return;
        }
        x[0] *= v[0];
        x[1] *= v[1];
        X *= V;
        double a, b;
        a = (v[1]*X - V*x[1]) / (v[1]*x[0] - v[0]*x[1]);
        b = (v[0]*X - V*x[0]) / (v[0]*x[1] - v[1]*x[0]);
        printf("%.9lf", max(a,b));

    }
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
