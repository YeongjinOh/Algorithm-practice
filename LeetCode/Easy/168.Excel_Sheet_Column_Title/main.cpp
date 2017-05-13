class Solution {
	public:
		string convertToTitle(int n) {
			if (n <= 0) return "";
			if (n <= 26) {
				return string(1, (char)n-1+'A');
			}
			return convertToTitle((n-1)/26) + convertToTitle((n-1)%26+1);
		}
};
