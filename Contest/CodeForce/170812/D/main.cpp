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
#define MAX 1000005
#define LEN 200005
const ll MOD = 1000000007;

int num[MAX];
int val[LEN];
ll comb[MAX]; // number of combinations
ll dpow[LEN];

int n;
int main() {
    cin >> n;
    int ub = 0;
    // build pow
    dpow[0] = 1;
    for (int i=1; i<LEN; ++i) dpow[i] = (2*dpow[i-1])%MOD;
    for (int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        num[a]++;
        val[i]=a;
        ub = max(ub, a);
    }
    ll res = 0;
    for (int i=2; i<=ub; ++i) {
        for (int j=i*2; j<=ub; j+=i) {
            num[i] += num[j];
        }
        comb[i] = (dpow[num[i]-1]*num[i])%MOD;
    }
    for (int i=ub; i>1; i--) {
        ll sub = 0;
        for (int j=i*2; j<=ub; j+=i)
            comb[i] = (comb[i] - comb[j] + MOD)%MOD;
        res += (comb[i]*i)%MOD;
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
