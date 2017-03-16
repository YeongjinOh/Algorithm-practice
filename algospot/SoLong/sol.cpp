#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;

#define LEN 26

struct TrieNode {
    TrieNode * children[LEN];
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
    int type (char * str, int id) {
        if (*str == 0) return 0;
        if (first == id) return 1;
        int next = *str - 'A';
        return 1 + children[next]->type(str+1, id);
    }

};

int countKeys (TrieNode * trie, char * str) {
    TrieNode * root = trie->find(str);
    if (root == NULL || root->terminal == -1) return strlen(str);
    return trie->type(str, root->terminal);
}

TrieNode * readInput (int words) {
    vector<pair<int,string> > input;
    for (int i=0; i<words; i++) {
        char buf[11];
        int freq;
        scanf("%s %d", buf, &freq);
        input.push_back(make_pair(-freq, buf));;
    }
    sort (input.begin(), input.end());
    TrieNode * trie = new TrieNode();
    for (int i=0; i<input.size(); i++)
        trie->insert(input[i].second.c_str(), i);
    trie->first = -1;
    return trie;
}
int main() {
    cin >> C;
    while (C--) {
        int n, m, freq;
        cin >> n >> m;

        TrieNode * root = readInput(n);
        int res = 0;
        char word[11];
        for (int i=0; i<m; i++) {
            scanf("%s",word);
            int cur = countKeys (root, word);
            res += cur;
        }
        cout << res + m - 1 << endl;
    }
}
