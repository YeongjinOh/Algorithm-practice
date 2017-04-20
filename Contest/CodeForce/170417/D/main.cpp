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
int n;
int x[1000], y[1000];

double getD (int center) {
    long long x0 = x[center], y0 = y[center];
    long long x1 = x[(center-1+n)%n], y1 = y[(center-1+n)%n];
    long long x2 = x[(center+1)%n], y2 = y[(center+1)%n];
    long long a, b, c; // ax + by + c;
    if (x1 == x2) {
        a = 1;
        b = 0;
        c = -x1;
    } else {
        a = y1 - y2;
        b = x2 - x1;
        c = x1*y2 - x2*y1;
    }
    double D = abs(a*x0+b*y0+c) / sqrt(a*a+b*b);
    return D/2;
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d%d", &x[i], &y[i]);
    double D = 1e30;
    for (int i=0; i<n; i++) D = min<double>(D,getD(i));
    printf("%.10lf\n", D);
    return 0;
}
