#include <iostream>

using namespace std;

struct List {
    int val;
    List * nxt;
    List() : val(-1), nxt(NULL) { }
    List(int val) : val(val), nxt(NULL) { }
    void setNext (List * node) { nxt = node; }
    void append (List * node) {
        if (nxt == NULL) {
            nxt = node;
            return;
        }
        List *cur = nxt;
        while (cur->nxt != NULL) { cur = cur->nxt; }
        cur->nxt = node;
    }
    void printAllChild() {
        List * cur = nxt;
        while (cur != NULL) {
            printf("%d ", cur->val);
            cur = cur->nxt;
        }
        printf("\n");
    }
    void remove (int num) {
        if (nxt == NULL) return;
        if (nxt->val == num)
            nxt = nxt->nxt;
        else
            nxt->remove(num);
    }
};

int main () {
    List * head = new List();
    List * add = new List(1);
    head->append(add);
    head->append(new List(2));
    head->append(new List(3));
    head->append(new List(4));
    head->printAllChild();
    head->remove(3);
    head->printAllChild();
}
