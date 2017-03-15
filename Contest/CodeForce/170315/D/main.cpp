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
ll MOD = 1000000007;

char par[200010];
bool check[200010];

int len;
ll f[200010];

ll mypow(ll a, ll b) {
    ll x=1,y=a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

ll InverseEuler(ll n, ll MOD) {
    return mypow(n,MOD-2);
}

ll combi (ll n, ll r) {
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}


int main() {
    scanf("%s", par);
    len = strlen(par);

    // build pow
    f[0] = 1;
    for(int i = 1 ; i <= 200005 ; i++)
          f[i] = (f[i-1]*i)%MOD;
    int cntLeft=0, cntRight = 0;
    rep (i, 0, len) {
        if (par[i] == ')')
            cntRight++;
    }
    ll res = 0;
    rep (i, 0, len) {
        if (par[i] == ')')
            cntRight--;
        else {
            cntLeft++;
            res += combi(cntLeft-1+cntRight, cntRight-1);
            /*
            for (int j=0; j<min(cntLeft, cntRight); j++) {
                ll c = (combi(cntLeft-1,j) * combi(cntRight, j+1))%MOD;
                res += c;
                res = res%MOD;
            }
            */
            res = res % MOD;
        }
    }

    cout << res << endl;


    return 0;
}
