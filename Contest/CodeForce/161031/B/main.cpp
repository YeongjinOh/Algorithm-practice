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

ll ls[100100], rs[100100];
ll absll (ll num) {
    if (num<0)
        return -1*num;
    return num;
}
int main() {
    scanf("%lld", &n);
    ll lsum = 0, rsum = 0;
    for (int i=1; i<=n; i++) {
        scanf("%lld%lld", &ls[i], &rs[i]);
        lsum += ls[i];
        rsum += rs[i];
    }
    ll cur = 0, maxsum = absll(lsum-rsum);
    ll cursum;
    for (int i=1; i<=n; i++) {
        cursum = absll(lsum-rsum -2*ls[i]+2*rs[i]);
        if (cursum > maxsum) {
            maxsum = cursum;
            cur = i;
        }
    }

    printf("%lld\n",cur);
    return 0;
}
