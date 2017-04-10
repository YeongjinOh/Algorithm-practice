#include <iostream>
using namespace std;
struct Node {
    Node * left, *right;
    int key, size, priority;
    Node(int k) : key(k), size(1), priority(rand()), left(NULL), right(NULL) { }
    void setSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
    void setLeft(Node * l) {
        left = l;
        setSize();
    }
    void setRight (Node * r) {
        right = r;
        setSize();
    }
};

typedef pair<Node*,Node*> NodePair;

NodePair split (Node * root, int key) {
    if (root==NULL) return NodePair(NULL,NULL);
    if (root->key < key) {
        NodePair np = split(root->right,key);
        root->setRight(np.first);
        return NodePair(root, np.second);
    }
    NodePair np = split(root->left,key);
    root->setLeft (np.second);
    return NodePair(np.first, root);

}

Node * insert (Node * root, Node * node) {
    if (root == NULL) return node;
    if (root->priority < node->priority) {
        NodePair np = split(root, node->key);
        node->setLeft(np.first);
        node->setRight(np.second);
        return node;
    }
    if (root->key > node->key)
        root->setLeft(insert(root->left, node));
    else
        root->setRight(insert(root->right, node));
    return root;
}


int main () {
    Node * root;
    for (int i=0; i<100; i++) {
        root = insert(root, new Node(i));
    }
    printf("size:%d\n",root->size);
}
