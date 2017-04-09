#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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


ll n, k;

void read() {
    cin >> n >> k;
}


void solve () {
    queue<pll> q;
    ll l = 0, r = n+1, mid;
    q.push(mp(l,r));
    while(!q.empty() && k > 0) {
        pll t = q.front(); q.pop();
        l = t.fi, r=t.se;
        mid = (l+r)/2;
        if (l < mid && mid < r) {
            if (r-mid > mid-l) {
                q.push(mp(mid,r));
                q.push(mp(l,mid));
            } else {
                q.push(mp(l,mid));
                q.push(mp(mid,r));
            }
            k--; // visit mid
        }
    }
    ll s = (r-l-2);
    cout << s-s/2 << " " <<  s/2;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        read();
        solve();
        cout << endl;
    }
    return 0;
}
