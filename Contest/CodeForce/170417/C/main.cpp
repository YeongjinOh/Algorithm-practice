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
typedef int ll;
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
ll n, k, l, r, p;
double asum = 0, bsum = 0;;
ll a[100005], b[100005];

bool check (double x) {
    double maxSum = 0;
    for (ll i=0; i<n; i++) {
        double s = max<double>(0, a[i]*x-b[i]);
        maxSum += s;
    }
    return maxSum <= (double)p*x;
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i=0; i<n; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i=0; i<n; i++) {
        asum += a[i];
        bsum += b[i];
    }
    if (asum <= p) {
        cout << -1 << endl;
        return 0;
    }
   double l = 0.0, r = bsum / (asum - p) + 100;
    for (int i=0; i<100; i++) {
        double mid = (l+r)/2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.10lf\n", l);

    return 0;
}
