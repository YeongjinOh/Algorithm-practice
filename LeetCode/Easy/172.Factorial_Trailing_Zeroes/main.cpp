class Solution {
	public:
		int trailingZeroes(int num) {
			int res = 0;
			for (int div = 5; num >= 5; num /= div)
				res += num/div;
			return res;

		}
};
