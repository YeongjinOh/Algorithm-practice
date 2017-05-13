class Solution {
    public:
        //////////////////////////////////////////////////////////////
        // Solution 1) Bottom-up DP
        //////////////////////////////////////////////////////////////
        int getMoneyAmount(int n) {
            vector<vector<int> > a(n+1, vector<int>(n+1, INT_MAX/2));
            for (int start=1; start<=n; start++) {
                a[0][start] = 0;
                a[1][start] = 0;
            }
            for (int len = 2; len <= n; len++) {
                for (int start = 1; start + len -1 <= n; start++) {
                    for(int i=1; i<=len; i++) {
                        a[len][start] = min(a[len][start], (start+i-1) + max(a[len-i][start+i], a[i-1][start]));
                    }
                }
            }
            return a[n][1];
        }

        //////////////////////////////////////////////////////////////
        // Solution 2) Top-down DP
        //////////////////////////////////////////////////////////////
        int findMinimumCost(vector<vector<int> > &cache, int l, int r) {
            if (l >= r) return 0;
            int &res = cache[l][r];
            if (res != -1) return res;
            res = INT_MAX;
            for (int m=l; m<=r; m++) {
                res = min(res, m + max(findMinimumCost(cache, l,m-1), findMinimumCost(cache, m+1, r)));
            }
            return res;
        }
        int getMoneyAmount(int n) {
            vector<vector<int> > cache(n+1, vector<int> (n+1, -1));
            return findMinimumCost(cache, 1, n);
        }
};
