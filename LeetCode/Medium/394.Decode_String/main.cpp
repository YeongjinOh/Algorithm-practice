class Solution {
	public:
		string decodeString(string s) {
			int n = s.size();
			if (n == 0) return "";
			int i = 0;
			while (i < n && 'a' <= s[i] && s[i]<= 'z') { i++; }
			if (i==n) return s;
			int num = 0;
			string res = s.substr(0,i);
			while ('0' <= s[i] && s[i] <= '9') {
				num = 10*num + s[i++]-'0';
			}
			int cnt = 0;
			int start = i+1;
			do {
				if (s[i] == '[') cnt++;
				else if (s[i] == ']') cnt--;
				i++;
			} while (i<n && cnt > 0);
			string tmp = decodeString(s.substr(start,i-start-1));
			for (int i=0; i<num; i++)
				res += tmp;
			return res + decodeString(s.substr(i));
		}

};
