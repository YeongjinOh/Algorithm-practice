#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int C, n, m;

#define LEN 26
#define DEBUG true

//////////////////////////////////////////////////////////
// TODO
// cur1 (main.cpp) is wrong, cur2 (sol.cpp) right
// but, can not find difference
// ///////////////////////////////////////////////////////
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
    void insert (const char * str, int freq) {
        if (*str == 0) {
            curFreq = freq;
            maxFreq = freq;
            return;
        }
        int next = *str - 'A';
        if (children[next] == NULL)
            children[next] = new Trie();
        maxFreq = max(maxFreq, freq);
        children[next]->insert(str+1, freq);
    }
    // len = length of passed characters
    // num = num pressed
    int find (const char * str, int len, int num) {
        if (*str == 0) {
            //            if (curFreq == 0)
            if (curFreq == 0 || curFreq != maxFreq)
                return len;
            return min(len, num+1);
        }
        int next = *str - 'A';
        if (children[next] == NULL) {
            return strlen(str) + len;
        }
        bool flag = false;
        for (int i=0; i< next; i++) {
            if (children[i] && maxFreq == children[i]->maxFreq)
                flag = true;
        }
        if (flag || maxFreq > children[next]->maxFreq || maxFreq == curFreq)
            num = len + 1;
        return children[next]->find(str+1, len+1, num);
    }

};

struct TrieNode {
    TrieNode * children[LEN];
    //    int curFreq; // current frequency between 1 and 10 // 0 if not leaf
    //    int maxFreq; // maximal frequency of subtree whilc rooted on this node
    int terminal, first;
    TrieNode () : terminal(-1), first(-1) {
        memset(children,0,sizeof(children));
    }
    void insert (const char * str, int id) {
        if (first == -1) first = id;

        if (*str == 0) {
            terminal = id;
        } else {
            int next = *str - 'A';
            if (children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(str+1, id);
        }
    }

    TrieNode * find(const char * str) {
        if (*str == 0) {
            return this;
        }
        int next = *str - 'A';
        if (children[next] == NULL) return NULL;
        return children[next]->find(str+1);
    }
    int type (const char * str, int id) {
        if (*str == 0) return 0;
        if (first == id) return 1;
        int next = *str - 'A';
        return 1 + children[next]->type(str+1, id);
    }

};

int countKeys (TrieNode * trie, const char * str) {
    TrieNode * root = trie->find(str);
    if (root == NULL || root->terminal == -1) return strlen(str);
    return trie->type(str, root->terminal);
}

void preorder (string s, Trie * root) {
    if (root->curFreq > 0)
        printf("%s %d\n", s.c_str(), root->curFreq);
    for (int i=0; i<LEN; i++) {
        if (root->children[i])
            preorder((s+ (char)('A'+i)), root->children[i]);
    }
}

int main() {
    if (DEBUG) {
        C = 5;
        n = 1;
        m = 200000;
    }
    else    cin >> C;

    srand(time(0));
    while (C--) {
        int freq;
        char word[15];
        if (DEBUG) {
            n *= 10;
        } else {
            cin >> n >> m;
        }
        TrieNode * trie = new TrieNode();
        Trie * root = new Trie();
        root->maxFreq = 987654321;

        int l = 10;

        vector<pair<int,string> > input;
        if (DEBUG) {
            vector<string> words;
            for (int i=0; i<n; i++) {
                string word = "";
                int num = rand()%l+1;
                for (int j=0; j<num; j++) {
                    word += ('A' + rand()%LEN);
                }
                words.push_back(word);
            }
            sort( words.begin(), words.end() );
            words.erase( unique( words.begin(), words.end() ), words.end() );


            for (int i=0; i<words.size(); i++) {
                int freq = rand()%100000+1;
                input.push_back(make_pair(-freq, words[i].c_str()));
                root->insert(words[i].c_str(), freq);
            }

        } else {

            for (int i=0; i<n; i++) {
                char buf[11];
                int freq;
                scanf("%s %d", buf, &freq);
                input.push_back(make_pair(-freq, buf));
                root->insert(buf, freq);
            }

        }

        sort (input.begin(), input.end());
        for (int i=0; i<input.size(); i++)
            trie->insert(input[i].second.c_str(), i);
        trie->first = -1;

        int res = 0;
        for (int i=0; i<m; i++) {
            string word = "";
            if (DEBUG) {
                int num = rand()%l+1;
                for (int j=0; j<num; j++) {
                    word += ('A' + rand()%LEN);
                }
            } else {
                cin >> word;
            }
            int cur1 = root->find(word.c_str(), 0, 0);
            int cur2 = countKeys(trie, word.c_str());
            if (cur1 != cur2) {
                //preorder("",root);
                printf("i:%d word:%s %d %d\n", i, word.c_str(), cur1, cur2);
            }
            res += cur1;
        }
        cout << res + m - 1 << endl;
    }
}
