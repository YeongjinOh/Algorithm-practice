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
#define INF 5e18
ll n, k, l, r, a, b;


#define MOD 1000000007
#define MAX 400000
ll fac[MAX], facinv[MAX], inv[MAX];

inline ll C(ll x,ll y){
    return ((fac[x]*facinv[y])%MOD*facinv[x-y])%MOD;
}

void init(){
    fac[0]=1LL,facinv[0]=1LL;
    inv[1]=1LL;

    for(ll i=2;i<MAX;i++)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;

    for(ll i=1;i<MAX;i++)
        fac[i]=fac[i-1]*i%MOD;

    for(ll i=1;i<MAX;i++)
        facinv[i]=facinv[i-1]*inv[i]%MOD;
}

int main() {
    init();

    scanf("%lld%lld", &n, &r);
    cout << C(n,r) << endl;

    return 0;
}
