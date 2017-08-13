#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <unordered_map>
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
const ll MOD = 1000000007;

int n;

vector<int> primes;
unordered_map<int, ll> sum;
unordered_map<int, ll> num; // number of groups
unordered_map<int, set<int> > mult; // prime -> multiples used of prim
ll res = 0;

int gcd (int a, int b) {
    if (b > a) return gcd(b,a);
    if (a%b == 0) return b;
    return gcd(b, a%b);
}
vector<pair<int, pair<ll,ll> > > lazy; // (g, (sumPlus, numPlus) );
void checkAllMultiple (int p, int aa, set<int> &used) {
    set<int> lazyadd;
    for (auto it = mult[p].begin(); it != mult[p].end(); ++it) {
        int m = *it; // multiple
        if (used.find(m) == used.end()) {
            used.insert(m);
            ll g = gcd(m, aa)%MOD;
  //          printf("gcd(%d,%d) = %d\n", m, aa, g);
            lazyadd.insert(g);
            ll kk = (sum[m] + num[m]) % MOD;
            res += (kk*g)%MOD;
            res %= MOD;
            lazy.pb(mp(g, mp(kk, num[m])));
        }
    }
    for (auto it = lazyadd.begin(); it != lazyadd.end(); ++it) {
        int a = *it;
        for (int j=0; j<primes.size() && a>1; j++) {
            int p = primes[j];
            if (a%p != 0) continue; // skip non divisor
            while (a%p == 0) { a/=p; }
            mult[p].insert(*it);
        }
        if (a > 1) mult[a].insert(*it);
    }
}

int main() {
    scanf("%d", &n);
    // build prime
    vector<bool> isPrime(1003, true);
    int k = isPrime.size();
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<k; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<k; j+=i)
                isPrime[j] = false;
            primes.pb(i);
        }
    }
    for (int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        if (a < 2) continue;
        int aa = a; // backup a
        set<int> used;
        for (int j=0; j<primes.size() && a>1; j++) {
            int p = primes[j];
            if (a%p != 0) continue; // skip non divisor
            while (a%p == 0) { a/=p; }
            mult[p].insert(aa);
            checkAllMultiple(p, aa, used);
        }
        if (a > 1) {
            int p = a;
            mult[p].insert(aa);
            checkAllMultiple(p, aa, used);
        }
        for (int i=0; i<lazy.size(); i++) {
            int g = lazy[i].fi;
            sum[g] = (sum[g] + lazy[i].se.fi)%MOD;
            num[g] = (num[g] + lazy[i].se.se)%MOD;
//            printf("g:%d sum[g]:%d num[g]:%d\n", g, sum[g], num[g]);
        }
        lazy.clear();
        res = (res + aa)%MOD;
        sum[aa]++;
        num[aa]++;
//        printf("aa:%d res:%d sum[aa]:%d num[aa]:%d\n", aa, res, sum[aa], num[aa]);
    }
    cout << res << endl;
    return 0;
}
