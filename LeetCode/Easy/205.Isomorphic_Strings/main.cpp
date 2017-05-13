class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			if (s.size() != t.size()) return false;
			char match[256];
			bool occupied[256];
			for (int i=0; i<256; i++) {
				match[i] = 0;
				occupied[i] = 0;
			}
			for (int i=0; i<s.size(); i++) {
				if (match[s[i]] == 0) {
					if (occupied[t[i]]) return false;
					match[s[i]] = t[i];
					occupied[t[i]] = true;
				} else if (match[s[i]] != t[i]) {
					return false;
				}
			}
			return true;
		}
};
