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
#define LEN 10005
int d[LEN], l[LEN];
void solve () {
    int n, goal;
    cin >> n;
    for (int i=0; i<n; i++) cin >> d[i] >> l[i];
    cin >> goal;
    d[n] = goal;
    l[n] = 1;
    vector<int> maxReach(n+1, 0);
    maxReach[0] = d[0];
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (d[j]-d[i] <= maxReach[i])
                maxReach[j] = max(maxReach[j], min(d[j]-d[i], l[j]));
        }
    }
    if (maxReach[n] > 0) cout << "YES";
    else cout << "NO";
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
