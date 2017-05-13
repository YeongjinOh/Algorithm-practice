class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26];
        for (int i=0; i<26; i++) cnt[i] = -1;
        for (int i=0; i<s.size(); i++) {
            int &curCnt = cnt[s[i]-'a'];
            if (curCnt >= 0) curCnt = -2;
            if (curCnt == -1) curCnt = i;
        }
        int res = -1;
        for (int i=0; i<26; i++) {
            if (cnt[i] >= 0 && (res == -1 || res > cnt[i]))
                res = cnt[i];
        }
        return res;
    }
};
