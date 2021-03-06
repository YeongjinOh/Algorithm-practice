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
    scanf("%lld%lld", &n, &k);
    l = 0, r = 1e10;
    while(l != r) {
        m = (l+r)/2;
        if (2*(n-k) <= m*(m+1))
            r = m;
        else
            l = m+1;
    }

    printf("%lld\n", min(n, k+l));
    return 0;
}
