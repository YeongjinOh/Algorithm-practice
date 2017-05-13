class Solution {
	public:
		int convertStringToInt (string s) {
			if (s.size() == 0) return 0;
			if (s[0] == '-') return -convertStringToInt(s.substr(1));
			int res = 0;
			for (int i=0; i<s.size(); i++) {
				res = 10*res + s[i]-'0';
			}
			return res;
		}

		string complexNumberMultiply(string a, string b) {
			if (a.size() < 4 || b.size() < 4) return "";
			int pos1 = 0, pos2 = 0; // find the position of plus
			while (pos1 < a.size() && a[pos1] != '+') { pos1++; }
			while (pos2 < b.size() && b[pos2] != '+') { pos2++; }
			int real1 = convertStringToInt(a.substr(0,pos1)), comp1 = convertStringToInt(a.substr(pos1+1, a.size()-pos1-2));
			int real2 = convertStringToInt(b.substr(0,pos2)), comp2 = convertStringToInt(b.substr(pos2+1, b.size()-pos2-2));
			printf("%d %d %d %d\n", real1, comp1, real2, comp2);
			int real = real1 * real2 - comp1 * comp2; // overflow?
			int comp = real1 * comp2 + real2 * comp1;
			return std::to_string(real) + "+" + std::to_string(comp) + "i";
		}
};
