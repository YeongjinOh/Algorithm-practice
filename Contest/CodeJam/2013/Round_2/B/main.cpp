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

ll pow(ll n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    ll res = pow(n/2);
    if (n%2 == 0) return res*res;
    return res*res*2;
}
ll getGuaranteed (ll n, ll p) {
    ll sum = 0;
    ll res = 0;
    for (int i=1; i<=n; i++) {
        sum += pow(n-i);
        if (p <= sum) return res;
        res += pow(i);
    }
    return pow(n)-1;
}

ll getCould(ll n, ll p) {
    for (int i=0; i<=n; i++)
        if(p >= pow(n-i)) return pow(n) - pow(i);
    return 0;
}

void solve () {
    ll n, p; cin >> n >> p;
    cout << getGuaranteed(n,p) << " " << getCould(n,p);
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
