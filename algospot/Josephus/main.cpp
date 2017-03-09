#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C;

class node {
public:
    int idx;
    node * prev;
    node * next;
    node(int i):idx(i) { }
    void remove() {
        prev->next = next;
        next->prev = prev;
    }
};
int main() {
    cin >> C;
    while (C--) {
        int n, k;
        cin >> n >> k;
        node * root = new node(1);
        node * last = root;
        for (int i=2; i<=n; i++) {
            node * cur = new node(i);
            cur->prev = last;
            last->next = cur;
            last = cur;
        }
        last->next = root;
        root->prev = last;
        node * cur = root;
        for (int i=0; i<n-2; i++) {
            cur->remove();
            for (int j=0; j<k; j++) {
                cur = cur->next;
            }
        }
        if (cur->idx > cur->next->idx) cur = cur->next;
        printf("%d %d\n", cur->idx, cur->next->idx);
    }
}
