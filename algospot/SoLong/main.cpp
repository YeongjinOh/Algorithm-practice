#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;

#define LEN 26

struct Trie {
    Trie * children[LEN];
    int curFreq; // current frequency between 1 and 10 // 0 if not leaf
    int maxFreq; // maximal frequency of subtree whilc rooted on this node
    Trie () : curFreq(0), maxFreq(0) {
        memset(children, 0, sizeof(children));
    }
    ~ Trie () {
        for (int i=0; i<LEN; i++) if (children[i]) delete children[i];
    }
    void insert (char * str, int freq) {
        if (*str == 0) {
            curFreq = freq;
            maxFreq = freq;
            return;
        }
        Trie * &child = children[*str - 'A'];
        if (child == NULL)
            child = new Trie();
        maxFreq = max(maxFreq, freq);
        child->insert(str+1, freq);
    }
    // len = length of passed characters
    // num = num pressed
    int find (char * str, int len, int num) {
        if (*str == 0) {
            ////////////////////////////////////////////////////
            // important
            // if (curFreq < maxFreq) it can be wrong
            // ///////////////////////////////////////////////
            // if (curFreq == 0)
            if (curFreq == 0 || curFreq != maxFreq)
                return len;
            return min(len, num+1);
        }
        Trie * child = children[*str - 'A'];
        if (child == NULL) {
            return strlen(str) + len;
        }
        bool flag = false;
        for (int i=0; i<*str-'A'; i++) {
            if (children[i] && maxFreq == children[i]->maxFreq)
                flag = true;
        }
        if (flag || maxFreq > child->maxFreq || maxFreq == curFreq)
            num = len + 1;
        return child->find(str+1, len+1, num);
    }

};

int main() {
    cin >> C;
    while (C--) {
        int n, m, freq;
        char word[15];
        cin >> n >> m;

        Trie * root = new Trie();
        root->maxFreq = 987654321;

        for (int i=0; i<n; i++) {
            scanf("%s%d",word,&freq);
            root->insert(word, freq);
        }
        int res = 0;
        for (int i=0; i<m; i++) {
            scanf("%s",word);
            int cur = root->find(word, 0, 0);
            res += cur;
        }
        cout << res + m - 1 << endl;
    }
}
