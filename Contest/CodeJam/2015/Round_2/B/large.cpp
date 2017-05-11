#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
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
#define double long double
int t;
double r[105], c[105];
double V, X;
int n;

bool isPossibleUpperBound (double m) {
    double minVX = 0.0, remV = V;
    for (int i=0; i<n; i++) {
        if (r[i]*m > remV) {
            minVX += c[i] * remV; // set t_i as r_i * t_i = remaining V
            remV = 0.0;
            break;
        }
        remV-= r[i]*m;
        minVX += c[i]*r[i]*m;
    }
    if (remV != 0 || V*X < minVX) return false;
    double maxVX = 0.0;
    remV = V;
    for (int i=n-1; i>=0; i--) {
        if (r[i]*m > remV) {
            maxVX += c[i] * remV; // set t_i as r_i * t_i = remaining V
            remV = 0.0;
            break;
        }
        remV-= r[i]*m;
        maxVX += c[i]*r[i]*m;
    }
    return V*X <= maxVX;
}

void solve (int tc) {
    scanf("%d%LF%LF", &n, &V, &X);
    for (int i=0; i<n; i++)
        scanf("%LF%LF", &r[i], &c[i]);
    // sort
    double rSum = 0.0;
    for (int i=0; i<n; i++) {
        for (int j=i; j>0 && c[j] <= c[j-1]; j--) {
            swap(r[j],r[j-1]);
            swap(c[j],c[j-1]);
        }
    }

    // exceptional case
    for (int i=0; i<n; i++) rSum += r[i];
    if (c[0] == c[n-1]) {
        if (c[0] == X) {
            printf("%.9LF", V/rSum);
        } else {
            printf("IMPOSSIBLE");
        }
        return;
    }

    // find upper bound M
    double lo = 0, hi = 1e20;
    for (int i=0; i<200; i++) {
        double mid = (lo + hi)/2;
        if (isPossibleUpperBound(mid))
            hi = mid;
        else
            lo = mid;
    }
    if (lo > 1e19) printf("IMPOSSIBLE");
    else printf("%.9LF", lo);
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
        cout << endl;
        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
