class Solution {
public:
    bool isCapital(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool detectCapitalUse(string word) {
        if (isCapital(word[0])) {
            for (int i=1; i<word.size()-1; i++)
                if (isCapital(word[i]) != isCapital(word[i+1])) return false;
        } else {
            for (int i=0; i<word.size()-1; i++)
                if (isCapital(word[i]) != isCapital(word[i+1])) return false;
        }
        return true;
    }
};
