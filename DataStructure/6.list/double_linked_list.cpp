#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next, *prev;
    Node() : val(-1), next(NULL), prev(NULL) { }
    Node(int val) : val(val), next(NULL), prev(NULL) { }
    void setNext (Node * node) { next = node; }
    void setPrev (Node * node) { prev = node; }
};

// double linked list
class DLL {
    private:
        Node *head, *tail;
    public:
        DLL() {
            head = new Node();
            tail = new Node();
            head->setNext(tail);
            tail->setPrev(head);
        }
        void insert(int val) {
            Node * node = new Node(val);
            tail->prev->setNext(node);
            node->setPrev(tail->prev);
            tail->setPrev(node);
            node->setNext(tail);
        }
        void remove(int val) {
            Node * cur = head;
            while (cur->next != NULL && cur->val != val) {
                cur = cur->next;
            }
            if (cur->val == val) {
                cur->prev->setNext(cur->next);
                cur->next->setPrev(cur->prev);
            }
        }
        void printAll() {
            Node * cur = head->next;
            while (cur->next != NULL) {
                printf("%d ", cur->val);
                cur = cur->next;
            }
            printf("\n");
        }
};

int main () {
    DLL dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.printAll();
    dll.remove(3);
    dll.printAll();
}
