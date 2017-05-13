class Solution {
	public:
		bool isPerfectSquare(int num) {
			if (num <= 0) return 0;
			// use bisection
			int l=0, r=num;
			while (l<r) {
				int mid = (l+r)/2;
				if (mid > 0 && mid >= num/mid) { // to avoid overflow
					r = mid;
				} else {
					l = mid+1;
				}
			}
			// now l == r and it indicates the minimal integer such that n*n >= num;
			return l*l == num;
		}
};
