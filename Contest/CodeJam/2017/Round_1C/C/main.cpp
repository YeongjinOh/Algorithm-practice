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
#define INF 5e18

// number of q chosen
double calc (int cur, int chosen, int ub, vector<double>& p) {
    if (chosen > ub) return 0.0;
    if (cur == p.size()) return 1.0;

    return p[cur]*calc(cur+1, chosen, ub, p) + (1.0-p[cur])*calc(cur+1, chosen+1, ub, p);
}
void solve () {
    int n, k;
    cin >> n >> k;
    double u; cin >> u;
    vector<double> p(n);
    for (int i=0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int start = n-k;
    p.push_back(1.0);
    while (u > 0.0 && start >= 0) {
        int i=start;
        while (i<=n && p[i] == p[i+1]) { i++; }
        if (i > n) {
            start--;
            continue;
        }
        double diff = p[i+1] - p[i];
        int len = i-start+1;
        if (diff * len >= u) {
            for (int j=start; j<=i; j++) {
                p[j] += u/len;
            }
            u = 0.0;
            break;
        } else {
            for (int j=start; j<=i; j++)
                p[j] += diff;
            u -= len*diff;
        }
    }
    p.pop_back();
    double res = calc(0, 0, n-k, p);
    printf("%.6lf", res);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
