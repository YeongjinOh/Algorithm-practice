class Solution {
public:
    void reverseWordsAfterIdx(string& s, int idx) {
        if (s.size() <= idx) return;
        int spaceIdx = idx;
        while (spaceIdx < s.size() && s[spaceIdx] != ' ') { spaceIdx++; }
        reverse(s.begin()+idx, s.begin() + spaceIdx);
        reverseWordsAfterIdx(s, spaceIdx+1);
    }
    string reverseWords(string s) {
        reverseWordsAfterIdx(s,0);
        return s;
    }
};
