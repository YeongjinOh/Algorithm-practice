class Solution {
private:
    int getRow (char c) {
        if (c>='A' && c<='Z') c-= 'A'-'a';
        switch(c) {
            case 'q':
            case 'w':
            case 'e':
            case 'r':
            case 't':
            case 'y':
            case 'u':
            case 'i':
            case 'o':
            case 'p':
                return 0;
            case 'a':
            case 's':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
                return 1;
            default:
                return 2;
        }
    }
    bool check(string word) {
        int row = getRow(word[0]);
        for (int i=1; i<word.size(); i++)
            if (row != getRow(word[i])) return false;
        return true;
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (int i=0; i<words.size(); i++)
            if (check(words[i]))
                res.push_back(words[i]);
        return res;
    }
};
