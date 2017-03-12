#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 50000
using namespace std;
int C, n;
int swaps[MAX];

// 1. structure
// 2. method
// build
// find

struct Node {
    int key, priority, size;
    Node * left;
    Node * right;
    Node(int key) : key(key), priority(rand()), size(1), left(NULL), right(NULL) { }
    void setSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
    void setLeft(Node * l) {
        left = l;
        setSize();
    }
    void setRight(Node * r) {
        right = r;
        setSize();
    }
};

typedef pair<Node*,Node*> NodePair;

NodePair split (Node * root, int key) {
    if (root == NULL) return NodePair(NULL,NULL);
    if (root->key < key) {
        NodePair np = split(root->right ,key);
        root->setRight(np.first);
        return NodePair(root, np.second);
    }
    NodePair np = split(root->left, key);
    root->setLeft(np.second);
    return NodePair(np.first,root);
}

Node * insert (Node * root, Node * node) {
    if (root == NULL) return node;
    if (root->priority < node->priority) {
        NodePair np = split(root, node->key);
        node->setLeft(np.first);
        node->setRight(np.second);
        return node;
    }
    if (root->key < node->key)
        root->setRight(insert(root->right,node));
    else
        root->setLeft(insert(root->left,node));

    return root;
}

Node * merge (Node * left, Node * right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    if (left->priority < right->priority) {
        right->setLeft(merge(left,right->left));
        return right;
    }
    left->setRight(merge(left->right,right));
    return left;
}

Node * del (Node * root, int key) {
    if (root == NULL) return root;
    if (root->key == key)
        return merge(root->left, root->right);
    if (root->key < key)
        root->setRight(del(root->right, key));
    else
        root->setLeft(del(root->left, key));
    return root;
}
Node * build (int n) {
    Node * root;
    for (int i=1; i<=n; i++) {
        root = insert(root, new Node(i));
    }
    return root;
}

// find k-th element from right
int find(Node * root, int sw) {
    if (root == NULL) {
        printf("root is null with sw = %d\n",sw);
        return 0;
    }
    int rightSize = 0;
    if (root->right)
        rightSize += root->right->size;
    if (rightSize >= sw) return find(root->right, sw);
    if (rightSize + 1== sw) return root->key;
    return find(root->left, sw-rightSize-1);
}

void inorder (Node * root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder (Node * root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        Node * root = build(n);

        for (int i=0; i<n; i++)
            scanf("%d",&swaps[i]);
        for (int i=n-1; i>=0; i--) {
            swaps[i] = find(root, swaps[i]+1);
            root = del(root, swaps[i]);
        }
        for (int i=0; i<n; i++)
            printf("%d ", swaps[i]);
        cout << endl;
    }

    return 0;
}
