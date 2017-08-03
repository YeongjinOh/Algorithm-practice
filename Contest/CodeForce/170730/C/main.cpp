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

unordered_map<ll,bool> ump;
int n;
vector<int> primes;
vector<bool> isPrime(1005, true);

bool checkPow (int a, int b) {
    if ((a+b)%3 != 0) return false;
    if (a < b) return checkPow(b, a);
    // now a >= b
    if (a > 2*b) return false;
    return true;
}

bool check(ll a, ll b) {
    if (a*a < b || b*b < a) return false;
    if (!ump[a*b]) return false;
    for (int i=0; i<primes.size() /* & primes[i] < 1000 */; i++) {
        int p = primes[i];
        if (a%p != 0 && b%p != 0) continue;
        if (a%p == 0 && b%p == 0) {
            int ka = 0, kb = 0;
            while (a%p == 0) {
                a /= p;
                ka++;
            }
            while (b%p == 0) {
                b /= p;
                kb++;
            }
            if (!checkPow(ka, kb)) return false;
            if (a*a == b || b*b == a) return true;
            if (a*a < b || b*b < a) return false;
            if (a == 1 || b == 1) return false;
        } else {
            return false;
        }
    }
    if (a*a == b || b*b == a) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    int k = isPrime.size();
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<k; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<k; j+=i)
                isPrime[j] = false;
            primes.pb(i);
        }
    }
    // build ump
    for (ll i=1; i<=1000000; ++i)
        ump[i*i*i] = true;
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (check((ll)a,(ll)b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
