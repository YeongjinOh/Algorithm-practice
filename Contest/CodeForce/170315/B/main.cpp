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
ll n, m, k, l, r, a, b;


int main() {
    scanf("%lld", &n);
    long long l1 = 0, l2 = 0, r1 = 1e10, r2 = 1e10, a, b;
    rep(i, 0, n) {
        scanf("%lld%lld", &a, &b);
        l1 = max(l1, a);
        r1 = min(r1, b);
    }


    scanf("%lld", &m);
    rep(i, 0, m) {
         scanf("%lld%lld", &a, &b);
        l2 = max(l2, a);
        r2 = min(r2, b);
    }
    printf("%lld\n", max((long long)0, max(l1-r2, l2-r1)));

    return 0;
}
