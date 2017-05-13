class Solution {
	public:
		int numSquares(int n) {
			vector<int> ps;
			vector<int> dp(n+1, -1);
			for (int i=1; i*i<=n; i++) {
				ps.push_back(i*i);
			}
			dp[0] = 0;
			for (int i=0; i<ps.size(); i++) {
				for (int j=1; j<=n; j++) {
					if (j - ps[i] >= 0 && dp[j-ps[i]] != -1)  {
						if (dp[j] == -1 || dp[j] > dp[j-ps[i]] +1)
							dp[j] = dp[j-ps[i]] + 1;
					}
				}
			}
			return dp[n];
		}
};

