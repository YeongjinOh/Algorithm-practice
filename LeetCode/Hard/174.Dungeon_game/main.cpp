class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dg) {
        int m = dg.size(), n = dg[0].size();
        vector<int> dp(n+1, numeric_limits<int>::max());
        dp[n-1] = 1;
        for (int r=m-1; r>=0; r--) {
            for (int c=n-1; c>=0; c--) {
                dp[c] = max(1, min(dp[c], dp[c+1])-dg[r][c]);
            }
        }
        return dp[0];
    }
};
