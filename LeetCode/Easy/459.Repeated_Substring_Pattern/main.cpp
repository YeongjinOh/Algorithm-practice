class Solution {
public:
	// simple iteration
	// Time : O(n^2)
	// Extra Space : O(1)
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int len=1; len<=n/2; len++) {
            if (n%len != 0) continue;
            int matched;
            for (matched = len; matched<n; matched++) {
                if (s[matched%len] != s[matched]) {
                    break;
                }
            }
            if (matched == n) return true;
        }
        return false;
    }

	// using suffix array (KMP)
	// Time : O(n)
	// Extra Space : O(n)
    bool repeatedSubstringPattern2(string s) {
        int n = s.size();
        vector<int> pi(n,0); // partial match
        int begin = 1, matched = 0;
        while (begin+matched < n) {
            if (s[begin+matched] == s[matched]) {
                pi[begin+matched] = matched+1;
                matched++;
            } else if (matched == 0) {
                begin++;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
        int len = n - pi[n-1];
        // NOTE
        /*
        if (2*len > n || n%len != 0) return false;
        // NOTE
        // This part is guaranteed true!
        for (int i=2*len-1, mult=1; i<n; mult++, i+=len)
            if (pi[i] != mult*len) return false;
        return true;
        */
        return (2*len <= n && n%len == 0);
    }
};
