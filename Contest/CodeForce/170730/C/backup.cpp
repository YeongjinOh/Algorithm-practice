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

int n;
vector<int> primes;
typedef unordered_map<int,int> mii;

mii div(int num) {
    mii res;
    for (int i=0; i<primes.size(); i++) {
        int p = primes[i];
        if (num%p != 0) continue;
        int k = 0;
        while (num%p == 0) {
            num /= p;
            k++;
        }
        res[p] = k;
    }
    if (num > 1)
        res[num] = 1;
    return res;
}
bool checkPow (int a, int b) {
    if ((a+b)%3 != 0) return false;
    if (a < b) return checkPow(b, a);
    // now a >= b
    if (a > 2*b) return false;
    return true;
}

bool check(int a, int b) {
    ll la = a, lb = b;
    if (la*la < lb || lb*lb < la) return false;
    mii da = div(a), db = div(b);
    for (auto it = da.begin(); it != da.end(); ++it) {
        int div = it->fi, k = it->se;
        if (checkPow(k, db[div]))
            db[div] = 0;
        else return false;
    }
    for (auto it = db.begin(); it != db.end(); ++it) {
        if (it->se != 0)
            return false;
    }
    return true;
}
int main() {
    scanf("%d", &n);
    int k = 33000;
    vector<bool> isPrime(k, true);
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<k; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<k; j+=i)
                isPrime[j] = false;
            primes.pb(i);
        }
    }
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (check(a,b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
