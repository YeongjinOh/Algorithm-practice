class Solution {
	public:
		int strStr(string haystack, string needle) {

			int n = haystack.size(), m = needle.size();
			if (n<m) return -1;
			if (m == 0) return 0;

			vector<int> pi(m,0);
			int begin = 1, matched = 0;
			while (begin+matched < m) {
				if (needle[begin+matched] == needle[matched]) {
					pi[begin+matched] = ++matched;
				} else if (matched == 0) {
					begin++;
				} else {
					begin += matched - pi[matched-1];
					matched = pi[matched-1];
				}
			}

			begin = 0, matched = 0;
			while (begin+matched < n) {
				if (haystack[begin+matched] == needle[matched]) {
					matched++;
					if (matched == m)
						return begin;
				} else if (matched == 0) {
					begin++;
				} else {
					begin += matched - pi[matched-1];
					matched = pi[matched-1];
				}

			}
			return -1;

		}
};
