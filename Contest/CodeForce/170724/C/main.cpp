#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
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
#define LEN 100005
int n, s;
double x[LEN], v[LEN];
int t[LEN];

double calcT(double m, int i) {
    if (t[i] == 1) {
        if (m < x[i]) {
            return x[i]/v[i];
        }
        double dx = m - x[i];
        double dv = s - v[i];
        double t0 = dx/dv;
        double x0 = m - t0*s;
        double t1 = x0 /(v[i]+s);
        return t0 + t1;
    } else {
        if (m > x[i]) {
            return (1e6 - x[i])/v[i];
        }
        double dx = x[i] - m;
        double dv = s - v[i];
        double t0 = dx/dv;
        double x0 = (1e6 - m) - t0*s; // remaining distance
        double t1 = x0 /(v[i]+s);
        return t0 + t1;
    }

}
double calc(int m) {
    double maxT = 0.0;
    for (int i=0; i<n; i++) {
        maxT = max(maxT, calcT((double)m, i));
    }
    return maxT;
}
int main() {
    scanf("%d%d", &n, &s);
    for (int i=0; i<n; i++) scanf("%lf%lf%d", &x[i], &v[i], &t[i]);
    int lo = 0, hi = 1000000;
    while (hi - lo > 100) {
        int m1 = (2*lo+hi)/3, m2 = (lo+2*hi)/3;
        if (calc(m1) > calc(m2)) lo = m1;
        else hi = m2;
    }
    double ans = 1e20;
    for (int i=lo; i<=hi; i++) {
        ans = min(ans, calc(i));
    }
    printf("%.30lf\n", ans);
    return 0;
}
