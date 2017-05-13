class Solution {
public:
    string reverseStr(string s, int k) {
        for (int begin=0; begin<s.size(); begin += 2*k)
            for (int i=begin, j=min(begin+k-1, (int)s.size()-1); i<j; i++, j--)
                swap(s[i],s[j]);
        return s;
    }
};
