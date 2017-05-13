class Solution {
    public:
        string licenseKeyFormatting(string s, int k) {
            int n = s.size();
            int m = n; // n - # of dashes
            for (int i=0; i<n; i++) {
                if (s[i] == '-') m--;
            }
            int d = (m-1)/k; // k = 3 -> m=6
            string res(m+d,'-');
            int offset = k-1-(m-1)%k;
            for (int i=0, j=0; i<n; i++) {
                char c = s[i];
                if (('0' <= c && c <= '9' )|| ('A' <= c && c <= 'Z'))
                    res[j++] = c;
                else if ('a' <= c && c <= 'z')
                    res[j++] = c+'A'-'a';
                if ((j+offset)%(k+1) == k) j++;
            }
            return res;
        }

};
