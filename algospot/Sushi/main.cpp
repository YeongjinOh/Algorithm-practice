#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 20

// price, value
int p[LEN], v[LEN];
using namespace std;
int C, n, m;
// i is price / dp[i] is value
long long dp[200];
int max (long long a, long long b) { return a>b?a:b; }
int main() {
    cin >> C;
    while (C--) {
        cin >> n >> m;
        int idxMax = -1;
        double pv = 987654321;
        for (int i=0; i<n; ++i) {
            cin >> p[i] >> v[i];
            double cur = p[i]/v[i];
            if (pv > cur) {
                pv = cur;
                idxMax = i;
            }
            p[i] /= 100;
        }
        m/=100;

        // maximum sum of prices which not idxMax elements can make
        int maxSum = 0;
        for (int i=0; i<n; i++) {
            if (i == idxMax) continue;
            maxSum += p[i] * p[idxMax];
        }

        int r = m-maxSum;
        int minNumOfMax = r/p[idxMax];
        long long res = 0;
        if (r > 0) {
            res = (long long)v[idxMax] * minNumOfMax;
            m -= p[idxMax] * minNumOfMax;
        }

        // set dp
        dp[0] = 0;
        long long res2 = 0;
        for (int i=1; i<=m; i++) {
            dp[i%200] = -1;
            for (int j=0; j<n; j++) {
                if (p[j] > i || dp[(i-p[j])%200] < 0) continue;
                dp[i%200] = max(dp[i%200], dp[(i-p[j])%200] + (long long)v[j]);
            }
            res2 = max(res2, dp[i%200]);
        }
        cout << res + res2 << endl;
    }
}
