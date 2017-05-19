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
int n, m;
int w[LEN], c[LEN];

int main() {
    scanf("%d%d", &n, &m);
    vector<int> pwc[4];
    int wSum = 0;
    long long cSum = 0;
    for (int i=0; i<n; i++) {
        scanf("%d%d", &w[i], &c[i]);
        pwc[w[i]].pb(c[i]);
        wSum += w[i];
        cSum += c[i];
    }
    if (wSum <= m) {
        cout << cSum << endl;
        return 0;
    }
    vector<pair<ll, int> > sixSums;
    for (int k=1; k<=3; k++) {
        sort(all(pwc[k]));
////////////////////////////////////////////////////////////////
// NOTE
//
// do not use last 6 numbers
// ex)  1 2
//      1 2
//      1 2
//      1 2
//      1 2
//      1 2
//      3 5
//      3 5
//      -> make 9
////////////////////////////////////////////////////////////////
//        for (int i=pwc[k].size()-1; i>=(6/k)-1; i-=(6/k)) {
        for (int i=pwc[k].size()-1; i>=(6/k*2)-1; i-=(6/k)) {
            ll curSum = 0;
            for (int j=0; j<6/k; j++) curSum += pwc[k][i-j];
            sixSums.pb(mp(curSum, k));
        }
    }
    sort(all(sixSums));
    cSum = 0;
    while(sixSums.size() > 0 && m > 100) {
        ll curSum = sixSums.back().fi;
        int k = sixSums.back().se;
        m -= 6;
        cSum += curSum;
        sixSums.pop_back();
        for (int j=0; j<6/k; j++) pwc[k].pop_back();
    }
    vector<ll> dp(m+1, -1);
    dp[0] = 0;
    ll maxDp = 0;
    for (int k=3; k>=1; k--) {
        for (int i=pwc[k].size()-1; i>=0; i--) {
            for (int j=m; j>=k; j--) {
                if (dp[j-k] != -1 && (dp[j] == -1 || dp[j-k] + pwc[k][i] > dp[j])) {
                    dp[j] = dp[j-k] + pwc[k][i];
                    maxDp = max(maxDp, dp[j]);
                }
            }
        }
    }
    cSum += maxDp;
    cout << cSum << endl;
    return 0;
}
