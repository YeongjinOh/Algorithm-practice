class Solution {
    public:
        int findLastIndex (const string& str) {
            int n = str.size();
            vector<int> kmp(n, 0);
            int begin=1, matched=0;
            while(begin+matched < n) {
                if (str[begin+matched] == str[matched]) {
                    kmp[begin+matched] = matched+1;
                    matched++;
                } else if (matched > 0) {
                    begin += matched - kmp[matched - 1];
                    matched = kmp[matched - 1];
                } else {
                    begin++;
                }
            }
            begin = 0;
            matched = 0;
            while (begin + matched <= n) {
                if (begin+matched == n)
                    return n-1-begin;
                if (str[n-(begin+matched)-1] == str[matched]) {
                    matched++;
                } else if (matched > 0) {
                    begin += matched - kmp[matched - 1];
                    matched = kmp[matched - 1];
                } else {
                    begin++;
                }
            }
            return -1;
        }

        string shortestPalindrome(string str) {
            int lastIdx = findLastIndex(str);
            string substr = str.substr(lastIdx+1, str.size()-lastIdx-1);
            reverse(substr.begin(), substr.end());

            return substr+str;
        }
};
