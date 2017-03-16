#include <iostream>
using namespace std;

#define LEN 26
struct Trie {
    Trie * children[LEN];
    bool node;
    Trie () {
        for (int i=0; i<LEN; ++i) children[i] = NULL;
        node = false;
    }
    ~ Trie () {
        for (int i=0; i<LEN; ++i)
            if (children[i]) delete children[i];
    }
    void insert (string s) {
        if (s.size() == 0) {
            node = true;
            return;
        }
        int child = s[0]-'A';
        if (children[child] == NULL)
            children[child] = new Trie();
        children[child]->insert(s.substr(1));
    }

    bool find (string s) {
        if (s.size() == 0) return node;
        int child = s[0]-'A';
        if (children[child] == NULL) return false;
        return children[child]->find(s.substr(1));
    }
};

int main() {
    cout << "number of string inputs:";
    int n;
    cin >> n;
    Trie * root = new Trie();
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        root->insert(str);
    }

    cout << "number of strings to find:";
    cin >> n;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        if (root->find(str)) cout << "Find" << endl;
        else cout << "NOT FOUND" << endl;
    }
    return 0;
}
