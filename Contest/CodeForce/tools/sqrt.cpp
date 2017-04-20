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

ll fastSqrt (ll n) {
    ll l = 0, r = 1<<30;
    while (l != r) {
        ll mid = (l+r+1)/2;
        if (mid * mid <= n)
            l = mid;
        else
            r = mid-1;
    }
    return l;
}

int main() {
    scanf("%lld", &n);
    cout << fastSqrt (n) << endl;


    return 0;
}
