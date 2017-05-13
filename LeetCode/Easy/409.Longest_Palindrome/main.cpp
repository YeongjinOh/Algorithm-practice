class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52];
        for (int i=0; i<52; i++) cnt[i] = 0;
        for (int i=0; i<s.size(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') cnt[s[i]-'A']++;
            else if ('a' <= s[i] && s[i] <= 'z') cnt[26+s[i]-'a']++;
        }
        int res = 0;
        bool odd = false;
        for (int i=0; i<52; i++) {
            res += cnt[i]-(cnt[i]%2);
            if (cnt[i]%2) odd=true;
        }
        if (odd) res++;
        return res;
    }
};
