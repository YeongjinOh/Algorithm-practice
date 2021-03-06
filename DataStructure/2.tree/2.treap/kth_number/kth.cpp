#include <iostream>
#include <fstream>
using namespace std;

///// implement treap to get k-th number in O(log n)

struct TreeNode {
    int key, priority, size;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int key) : key(key), priority(rand()), size(1), left(NULL), right(NULL) { }
    void setSize () {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
    void setLeft (TreeNode * l) {
        left = l;
        setSize();
    }
    void setRight (TreeNode * r) {
        right = r;
        setSize();
    }
};

typedef pair<TreeNode*,TreeNode*> NodePair;

NodePair split (TreeNode * root, int key) {
    if (root == NULL) return NodePair(NULL,NULL);
    if (root->key < key) {
        NodePair np = split(root->right, key);
        root->setRight(np.first);
        return NodePair(root, np.second);
    }
    NodePair np = split(root->left, key);
    root->setLeft(np.second);
    return NodePair(np.first, root);
}

TreeNode * insert (TreeNode * root, TreeNode * node) {
    if (root == NULL) return node;
    if (root->priority < node->priority) {
        NodePair np = split(root, node->key);
        node->setLeft(np.first);
        node->setRight(np.second);
        return node;
    } else if (root->key < node->key) {
        root->setRight(insert(root->right,node));
    } else {
        root->setLeft(insert(root->left,node));
    }
    return root;
}

TreeNode * merge (TreeNode * left, TreeNode * right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    if (left->priority < right->priority) {
        right->setLeft(merge(left,right->left));
        return right;
    }
    left->setRight(merge(left->right,right));
    return left;
}

TreeNode * del (TreeNode * root, int key) {
    if (root == NULL) return root;
    if (root->key < key) {
        root->setRight(del(root->right,key));
        return root;
    } else if (root->key > key) {
        root->setLeft(del(root->left,key));
        return root;
    }
    return merge(root->left, root->right);
}

void inorder(TreeNode * root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
int find(TreeNode * root, int k) {
    int leftSize = 0;
    if (root->left != NULL)
        leftSize = root->left->size;
    if (k <= leftSize)
        return find(root->left, k);
    else if (k == leftSize + 1)
        return root->key;
    else
        return find(root->right, k-leftSize-1);
}


int main() {
    int n, k, key;
//    cin >> n >> k;
    n = 50;
    k = 35;
    TreeNode * root;
    while(n--) {
//        cin >> key;
        key = n;
        root = insert(root, new TreeNode(key));
    }
    root = del(root,11);
    root = del(root,8);
    printf("root:%d\n",root->key);
    int kth = find (root, k);
    cout << kth << endl;

    return 0;
}

