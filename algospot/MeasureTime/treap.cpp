#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int C, n;

struct Node {
    int key, priority, size;
    Node * left;
    Node * right;
    Node (int key) : key(key), priority(rand()), size(1), left(NULL), right(NULL) { }
    void setSize () {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
    void setLeft (Node * l) {
        left = l;
        setSize();
    }
    void setRight (Node * r) {
        right = r;
        setSize();
    }
};

typedef pair<Node*, Node*> NodePair;

NodePair split (Node * root, int key) {
    if (root == NULL) return NodePair(NULL,NULL);
    if (root->key > key) {
        NodePair np = split(root->left, key);
        root->setLeft(np.second);
        return NodePair(np.first, root);
    }
    NodePair np = split(root->right, key);
    root->setRight(np.first);
    return NodePair(root, np.second);
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
        root->setLeft(insert(root->left,node));
    else
        root->setRight(insert(root->right,node));
    return root;
}


// count less than num
int countLessThan (Node * root, int num) {
    if (root == NULL) return 0;
    if (root->key >= num)
        return countLessThan(root->left, num);
    int leftSize = 0;
    if (root->left)
        leftSize += root->left->size;
    return leftSize + 1 + countLessThan(root->right, num);
}


int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        int k, num;
        long long sum = 0;
        Node * root = NULL;
        for (int i=1; i<=n; i++) {
            scanf("%d",&num);
            root = insert(root, new Node(num));
            k = countLessThan(root, num+1);
            sum += (i-k);
        }
        cout << sum << endl;
    }
}
