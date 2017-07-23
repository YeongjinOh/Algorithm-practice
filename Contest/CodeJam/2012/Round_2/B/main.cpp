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

int t;
void solve () {
    ll n, w, l; cin >> n >> w >> l;
    vector<ll> r(n), x(n), y(n);
    for (int i=0; i<n; i++) cin >> r[i];
    sort(all(r));
    reverse(all(r));
    for (int i=0; i<n; i++) {
        while (true) {
            x[i] = rand()%(w+1);
            y[i] = rand()%(l+1);
            bool isOverlapped = false;
            for (int j=0; j<i; j++) {
                ll xDiff = x[i]-x[j], yDiff = y[i]-y[j], rSum = r[i]+r[j];
                if (xDiff*xDiff + yDiff*yDiff <= rSum*rSum) {
                    isOverlapped = true;
                    break;
                }
            }
            if (!isOverlapped)
                break;
        }
    }
    for (int i=0; i<n; i++) printf("%lld.0 %lld.0 ", x[i], y[i]);
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
