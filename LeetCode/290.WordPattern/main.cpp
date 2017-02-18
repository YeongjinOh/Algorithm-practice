#include <iostream>
#include <cstring>
using namespace std;

class PtTree {
    public:
        char pattern;
        char * word;
        PtTree *left;
        PtTree *right;
        PtTree(char pt, char * wd) : pattern(pt), word(wd), left(NULL), right(NULL) {}
        bool insert(char pt, char * wd) {
            if (pt == pattern) {
                if (strcmp(word,wd) == 0)
                    return true;
                else
                    return false;
            } else if (pt > pattern) {
                if (right == NULL) {
                    right = new PtTree(pt, wd);
                    return true;
                } else {
                    return right->insert(pt,wd);
                }
            } else if (pt < pattern) {
                if (left == NULL) {
                    left = new PtTree(pt, wd);
                    return true;
                } else {
                    return left->insert(pt,wd);
                }
            }
            return true;
        }
};

class WordTree {
    public:
        char pattern;
        char * word;
        WordTree *left;
        WordTree *right;
        WordTree(char pt, char * wd) : pattern(pt), word(wd), left(NULL), right(NULL) {}
        bool insert(char pt, char * wd) {
            if (strcmp(word,wd) == 0) {
                return pt == pattern;
            } else if (strcmp(word,wd) > 0) {
                if (right == NULL) {
                    right = new WordTree(pt, wd);
                    return true;
                } else {
                    return right->insert(pt,wd);
                }
            } else if (strcmp(word,wd) < 0) {
                if (left == NULL) {
                    left = new WordTree(pt, wd);
                    return true;
                } else {
                    return left->insert(pt,wd);
                }
            }
            return true;
        }
};


class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            char *cstr = new char[str.length() + 1];
            strcpy(cstr, str.c_str());
            char *word = strtok(cstr," ");
            int idx = 0;
            char pt = pattern[idx];
            PtTree ptRoot(pt, word);
            WordTree wdRoot(pt, word);

            int sz = pattern.size();
            while (word != NULL)
            {
                if (sz <= idx)
                    return false;
                pt = pattern[idx];
                if (!ptRoot.insert(pt, word))
                    return false;
                if (!wdRoot.insert(pt, word))
                    return false;
                // prepare next
                word = strtok(NULL," ");
                idx++;
            }
            if (sz > idx)
                return false;
            return true;
        }
};

int main() {
    Solution s;
    cout << s.wordPattern("abba", "cat dog dog cat") << endl;
}
