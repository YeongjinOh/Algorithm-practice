class Solution {
	public:

		// My complicate answer
		int maxProfit(vector<int>& nums) {
			int n = nums.size();
			if (n <= 1) return 0;
			int res[3][n];
			res[0][0] = res[1][0] = res[2][0] = 0;
			for (int i=1; i<n; i++) {
				res[0][i] = max(res[0][i-1], res[1][i-1]);
				res[1][i] = res[2][i-1];
				if (nums[i-1] < nums[i]) {
					res[2][i] = max(res[0][i-1], res[2][i-1]) + nums[i] - nums[i-1];
				} else {
					res[2][i] = 0;
				}
				if (i>=3)
					res[2][i] = max(res[2][i], max(res[0][i-3], res[2][i-3]) + nums[i] - nums[i-3]);
			}
			return max(res[0][n-1], max(res[1][n-1],res[2][n-1]));
		}
		// clear solution
		// buy[i]: Max profit till index i. The series of transaction is ending with a buy. (buy may not occur at i, may occur 1, 2, ... ,i-1)
		// sell[i]: Max profit till index i. The series of transaction is ending with a sell.
		int maxProfit(vector<int>& nums) {
			int n = nums.size();
			if (n <= 1) return 0;
			vector<int> buy(n,0), sell(n,0);
			buy[0] = -nums[0];
			for (int i=1; i<n; i++) {
				buy[i] = max(buy[i-1], (i>1?sell[i-2]:0)-nums[i]);
				sell[i] = max(sell[i-1], buy[i-1]+nums[i]);
			}
			return sell[n-1];
		}
};
