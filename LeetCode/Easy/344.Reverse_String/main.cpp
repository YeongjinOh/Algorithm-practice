class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        for (int i=0; 2*i+1<n; i++) {
            char tmp = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = tmp;
        }
        return s;
    }
};
