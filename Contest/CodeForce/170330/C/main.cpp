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
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
ll n, k, l, r, a, b;
ll num[100005];
ll max (ll a, ll b) { return a>b?a:b; }
ll min (ll a, ll b) { return a<b?a:b; }
int main() {
    scanf("%lld", &n);
    for (int i=0; i<n; ++i)
        scanf("%lld", &num[i]);
    for (int i=0; i<n-1; ++i) {
        num[i] = abs(num[i+1]-num[i]);
        if (i%2 == 1) num[i] = -1*num[i];
    }
    ll maxsum = 0, minsum = 10000000000000000, psum = 0, nsum = 0;
    for (int i=0; i<n-1; ++i) {
        psum = max(psum, 0) + num[i];
        nsum = min(nsum, 0) + num[i];
        maxsum = max(psum, maxsum);
        minsum = min(nsum, minsum);
    }
    printf("%lld\n", max(maxsum, -1*minsum));

    return 0;
}
