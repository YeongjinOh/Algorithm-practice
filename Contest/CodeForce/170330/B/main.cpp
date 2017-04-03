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
ll n, k, l, r, b, q, m;

vector<ll> a;
bool find (vector<ll> & a, ll num) {
    for (int i=0; i<a.size(); i++)
        if (a[i] == num) return true;
    return false;
}
int main() {
    scanf("%lld%lld%lld%lld", &b, &q, &l, &m);
    for (int i=0; i<m; ++i) {
        scanf("%lld",&k);
        a.pb(k);
    }
    sort(a.begin(),a.end());
    vector<ll> sol;
    if (b == 0) {
        sol.pb(0);
        if (find(a,0)) printf("0");
        else printf("inf");
        return 0;
    }
    else {
        if (q == 0) {
            if (find(a,0)) printf("%d",(b==0) || !(abs(b) <= l) ?0:1);
            else printf("inf");
            return 0;
        }
        else if (q == 1) {
            if (abs(b) > l || find(a,b)) printf("0");
            else printf("inf");
            return 0;
        }
        else if (q == -1) {
            if (abs(b) <= l) {
                if (!find(a,b))
                    sol.pb(b);
                if (!find(a,-b))
                    sol.pb(-b);
                if (sol.size() > 0) printf("inf");
                else printf("0");
                return 0;
            }
            printf("0");
            return 0;
        }
        else {
            while(abs(b) <= l) {
                sol.pb(b);
                b *= q;
            }
        }
    }

    ll cnt = 0;
    vector<ll>::iterator it;
    for (int i=0; i<sol.size(); i++) {
        it = find(a.begin(), a.end(), sol[i]);
        if (it != a.end()) {
            cnt++;
        }
    }
    int res = sol.size() - cnt;
    if (res > 0 && abs(q) == 1)
        printf("inf\n");
    else
        printf("%d\n",res);

    return 0;
}
