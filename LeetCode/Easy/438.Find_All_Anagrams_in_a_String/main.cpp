class Solution {
	public:

		bool checkAllZeros(unordered_map<char, int> count) {
			for (unordered_map<char,int> :: iterator it = count.begin(); it != count.end(); it++) {
				if (it->second != 0) return false;
			}
			return true;
		}
		vector<int> findAnagrams(string s, string p) {
			int n = s.size(), m = p.size();
			unordered_map<char, int> count;
			for (int i=0; i<m; i++) {
				count[p[i]]++;
				count[s[i]]--;
			}
			vector<int> res;
			if (checkAllZeros(count))
				res.push_back(0);
			for (int i=0; i+m<n; i++) {
				count[s[i]]++;
				count[s[i+m]]--;
				if (checkAllZeros(count))
					res.push_back(i+1);
			}

			return res;
		}
};
