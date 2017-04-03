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

bool find(vector<ll> & a, int num) {
    for (int i=0; i<a.size(); i++) {
        if (a[i] == num) return true;
    }
    return false;
}

int main() {
    scanf("%lld%lld%lld%lld", &b, &q, &l, &m);
    vector<ll> a;
    ll tmp;
    for (int i=0; i<m; ++i) {
        scanf("%lld",&tmp);
        a.pb(tmp);
    }
    sort(a.begin(), a.end());

    vector<ll> sol;
    if (q == 0) {
        if (b != 0)
            sol.pb(b);
        sol.pb(0);
    } else if (q == 1) {
        sol.pb(b);
    } else if (q == -1) {
        sol.pb(b);
        if (b != 0)
            sol.pb(-b);
    } else {
        while (abs(b) <= l) {
            sol.pb(b);
            b = b*q;
            if (b==0) break;
        }
    }
    int res = 0;
    for (int i=0; i<sol.size(); i++) {
        if (!find(a, sol[i]) && abs(sol[i]) <= l) res++;
    }
    if (res > 0 && ((abs(q) == 1 || b == 0) || (q == 0 && !find(a,0))))
        printf("inf");
    else
        printf("%d",res);


    return 0;
}
