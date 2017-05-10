#include <iostream>
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


int t;

double calc(vector<double> &cur, int k) {
    double dp[k+1][k/2+1]; // dp idx, cnt
    memset(dp,0.0,sizeof(dp));
    dp[0][0] = 1.0;
    for (int idx=1; idx<=k; idx++) {
        for (int cnt=0; cnt<=k/2; cnt++) {
            if (cnt > 0)
                dp[idx][cnt] += dp[idx-1][cnt-1] * cur[idx-1];
            dp[idx][cnt] += dp[idx-1][cnt] * (1.0 - cur[idx-1]);

        }
    }
    return dp[k][k/2];
}
/*
void calc(vector<double> &cur, double mult, int k, int numUse, int pos, double &sum) {
    if (pos == cur.size()) {
        if (numUse == k/2)
            sum += mult;
        return;
    }
    calc(cur, mult*cur[pos], k, numUse+1, pos+1, sum);
    calc(cur, mult*(1.0-cur[pos]), k, numUse, pos+1, sum);
}
void backtrack(vector<double> &p, vector<double> &cur, int pos, int k, double &res) {
    if (cur.size() == k) {
        double sum = 0.0;
        calc(cur, 1.0, k, 0, 0, sum);
        res = max(res, sum);
        return;
    }
    if (pos >= p.size()) return;
    backtrack(p,cur,pos+1,k,res);
    cur.push_back(p[pos]);
    backtrack(p,cur,pos+1,k,res);
    cur.pop_back();
}
*/

void solve (int tc) {
    int n, k;
    cin >> n >> k;
    vector<double> p(n,0);
    for (int i=0; i<n; i++) cin >> p[i];
    double res = 0.0;
    sort(p.begin(),p.end());
    for (int numLeft=0; numLeft<=k; numLeft++) {
        int numRight = k-numLeft;
        vector<double> cur;
        for (int j=0; j<numLeft; j++)
            cur.pb(p[j]);
        for (int j=0; j<numRight; j++)
            cur.pb(p[n-1-j]);
        res = max(res, calc(cur,k));
    }
//    backtrack(p, cur, 0, k, res);
    printf("%.8lf", res);
    fprintf(stderr, "case %d: %d %d\n", tc, n, k);
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
        cout << endl;
    }
    return 0;
}
