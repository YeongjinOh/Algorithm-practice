class Solution {
	public:
		int longestPalindromeSubseq(string str) {

			int n = str.size();
			if (n==0) return 0;
			int dp[n][n];
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					dp[i][j] = 0;
				}
			}
			// base cases
			for (int i=0; i<n; i++)
				dp[i][i] = 1;
			for (int i=0; i<n-1; i++) {
				if (str[i] == str[i+1])
					dp[i][i+1] = 2;
				else
					dp[i][i+1] = 1;
			}
			for (int m=2; m<n; m++) {
				for (int i=0; i+m<n; i++) {
					if (str[i] == str[i+m])
						dp[i][i+m] = dp[i+1][i+m-1] + 2;
					else
						dp[i][i+m] = max(dp[i][i+m-1], dp[i+1][i+m]);
				}
			}
			return dp[0][n-1];
		}
};
