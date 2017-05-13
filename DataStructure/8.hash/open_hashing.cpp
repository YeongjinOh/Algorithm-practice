#include <iostream>
#include <vector>
using namespace std;

struct LinkedList {
    int key, val;
    LinkedList * next;
    LinkedList (int b, int c) : key(b), val(c) { }
};
struct Hash {
    vector<LinkedList*> table;
    int m;
    Hash(int n) : table(n,NULL), m(n) { }
    void insert (int b, int c) {
        LinkedList * node = new LinkedList(b,c);
        node->next = table[b%m];
        table[b%m] = node;
    }
    int find (int b) {
        LinkedList * cur = table[b%m];
        while (cur != NULL && cur->key != b) { cur = cur->next; }
        if (cur == NULL) return -1;
        return cur->val;
    }

};

int main() {

    Hash hs(17);
    while (true) {
        int a, b, c;
        cin >> a;
        if (a==1) {
            cin >> b >> c;
            hs.insert(b,c);
        } else {
            cin >> b;
            cout << hs.find(b) << endl;
        }
    }
    return 0;
}
