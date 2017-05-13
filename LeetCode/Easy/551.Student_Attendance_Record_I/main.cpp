class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        for (int i=2; i<s.size(); i++) {
            if (s[i] == 'A') cnt++;
            else if (s[i-2] == 'L' && s[i-1] == 'L' && s[i] == 'L') return false;
        }
        if (s.size()>1 && s[1] == 'A') cnt++;
        if (s[0] == 'A') cnt++;
        return cnt<2;
    }
};
