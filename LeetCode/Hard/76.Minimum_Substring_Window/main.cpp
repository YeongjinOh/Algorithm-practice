class Solution {
    public:
        string minWindow(string s, string t) {
            map<char,int> cntS, cntT;
            int inValid = 0;
            for (int i=0; i<t.size(); ++i) {
                if (++cntT[t[i]] == 1) {
                    inValid++;
                }
            }
            int l=0, minL=0, minLen=0;
            for (int r=0; r<s.size(); ++r) {
                cntS[s[r]]++;
                if (cntS[s[r]] == cntT[s[r]])
                    inValid--;
                while (l <= r && cntS[s[l]] > cntT[s[l]]) {
                    cntS[s[l++]]--;
                }
                if (inValid == 0 && (minLen==0 || (minLen > 0 && minLen > r-l+1))) {
                    minLen = r-l+1;
                    minL = l;
                }
            }
            return s.substr(minL,minLen);
        }
};
