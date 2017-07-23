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

#define MAX 60005
ll x[MAX], v[MAX];

double calc(double pos) {
    double res = 0;
    rep(i, 0, n)
        res = max(res, abs(pos-x[i])/v[i]);
    return res;
}

int main() {
    scanf("%lld", &n);
    rep(i, 0, n)
        scanf("%lld,", x+i);
    rep(i, 0, n)
        scanf("%lld,", v+i);
    double l = 0, r = 1e9;
    rep(i, 0, 200) {
        double l1 = (2*l+r)/3, l2 = (l+2*r)/3;
        if (calc(l1) > calc(l2))
            l = l1;
        else
            r = l2;
    }
    printf("%.10lf\n", calc(l));

    return 0;
}
