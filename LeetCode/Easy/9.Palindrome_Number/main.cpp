class Solution {
	public:
		// my answer
		bool isPalindrome(int num) {
			if (num < 0) return false;
			int n = 0, m = num;
			while (m > 0) {
				n = n*10 + m%10;
				m/=10;
			}
			return num == n;
		}

		// reverse only half of the number
		bool isPalindrome2(int num) {
			if (num == 0) return true;
			if (num < 0 || num % 10 == 0) return false;
			int sum = 0;
			while (num > sum) {
				sum = sum*10 + num%10;
				num /= 10;
			}
			return num == sum || (num == sum/10);
		}
};
