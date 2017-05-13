class Solution {
    public:
        int numTrees(int num) {
            vector<int> dp(num+1, 0);
            dp[0] = 1;
            for (int i=1; i<=num; i++) {
                for (int j=1; j<=i; j++) { // j means root index
                    dp[i] += dp[j-1]*dp[i-j];
                }
            }
            return dp[num];
        }
};
