class Solution {
	public:
		string addBinary(string a, string b) {
			if (a.size() < b.size()) return addBinary(b,a);
			if (b.size() == 0) return a;
			int n = a.size(), m = b.size();
			int carry = 0;
			for (int i=1; i<=n; i++) {
				int add = a[n-i]-'0' + (m-i>=0?b[m-i]-'0':0) + carry;
				carry = add/2;
				a[n-i] = add%2 + '0';
			}
			return carry? "1" + a : a;
		}
};
