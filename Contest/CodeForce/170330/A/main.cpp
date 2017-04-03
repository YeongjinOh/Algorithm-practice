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

int main() {
    scanf("%lld%lld", &n, &k);
    for (int i=0; i<n; ++i)
        scanf("%lld",&num[i]);
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        sum += (num[i]-1)/k + 1;
    }
    printf("%lld\n", (sum+1)/2);

    return 0;
}
