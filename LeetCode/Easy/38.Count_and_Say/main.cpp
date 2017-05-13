class Solution {
	public:
		string getNext(string str, map<string, string>& dp) {
			if (dp.find(str) != dp.end()) return dp[str];
			string &res = dp[str];
			res = std::to_string((int)str.size()) + std::to_string((int)str[0]-'0');
			return res;
		}
		string countAndSay(int n) {
			string cur = "1";
			map<string, string> dp;
			for (int i=1; i<n; i++) {
				int l=0, r=0;
				string next = "";
				while (l < cur.size()) {
					while(r < cur.size() && cur[l] == cur[r]) { r++; }
					next += getNext(cur.substr(l,r-l),dp);
					l = r;
				}
				cur = next;
			}
			return cur;


		}
};
