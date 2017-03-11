#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

//////////////////////////////////////////////////////
// I implemented binary search tree, but not balanced
// so, it's timeover
// TODO : implement balanced binary search tree to overcome timeover
// DONE : overcame timeover using treap
//////////////////////////////////////////////////////

using namespace std;
int C, n, cnt, sum, p, q;
bool check;

struct TreeNode {
    int p, q;
    int priority, size;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int p, int q) : p(p), q(q), priority(rand()), size(1), left(NULL), right(NULL) { }
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
    void setLeft (TreeNode * l) {
        left = l;
        calcSize();
    }
    void setRight (TreeNode * r) {
        right = r;
        calcSize();
    }
};
typedef pair<TreeNode*,TreeNode*> NodePair;

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

NodePair split (TreeNode * root, TreeNode * node) {
    if (root == NULL) return NodePair(NULL, NULL);
    if (root->p < node->p && root->q < node->q) {
        root = merge(root->left, root->right);
        return split(root, node);
    }
    if (root->p > node->p && root->q > node->q) {
        check = false;
    }
    if (root->p < node->p) {
        NodePair np = split(root->right, node);
        root->setRight(np.first);
        return NodePair(root, np.second);
    }
    NodePair np = split(root->left, node);
    root->setLeft(np.second);
    return NodePair(np.first, root);
}


TreeNode * insert (TreeNode * root, TreeNode * node) {
    if (root == NULL) return node;
    // keep heap property
    if (root->priority < node->priority) {
        check = true;
        NodePair np = split(root, node);
        if (check)  {
            node->setLeft(np.first);
            node->setRight(np.second);
            return node;
        }
        return merge(np.first, np.second);
    }
    // remove root
    if (root->p < node->p && root->q < node->q) {
        TreeNode * ret =  merge(root->left, root->right);
        delete root;
        return insert(ret, node);
    }
    // remove node
    else if (root->p > node->p && root->q > node->q) {
        return root;
    }
   if (root->p < node->p)
        root->setRight(insert(root->right, node));
    else
        root->setLeft(insert(root->left, node));
    return root;
}


int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        sum = 0;
        TreeNode * root = NULL;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&p,&q);
            root = insert(root, new TreeNode(p,q));
            sum += root->size;
        }
        cout << sum << endl;
    }
}
