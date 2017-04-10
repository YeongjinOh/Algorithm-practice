#include <iostream>
using namespace std;

struct TreeNode {
    int num;
    int priority, size;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int n):num(n), priority(rand()%1000), size(1), left(NULL), right(NULL) { }
    void setSize() {
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

NodePair split(TreeNode * root, int key) {
    if (root == NULL) return NodePair(NULL, NULL);
    if (root->num > key) {
        NodePair np = split(root->left, key);
        root->setLeft(np.second);
        return make_pair(np.first, root);
    } else {
        NodePair np = split(root->right, key);
        root->setRight(np.first);
        return make_pair(root, np.second);
    }
}

TreeNode * merge (TreeNode * left, TreeNode * right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    if (left->priority < right->priority) {
        right->setLeft(merge(left, right->left));
        return right;
    } else {
        left->setRight(merge(left->right, right));
        return left;
    }
}

TreeNode * insert(TreeNode * root, TreeNode * node) {
    if (root == NULL)
        root = node;
    else if (root->priority < node->priority) {
        NodePair np = split(root, node->num);
        node->setLeft(np.first);
        node->setRight(np.second);
        return node;
    }
    else if (root->num > node->num)
        root->setLeft(insert(root->left, node));
    else
        root->setRight(insert(root->right, node));
    return root;
}

void inorder (TreeNode * root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("key:%d priority:%d\n", root->num, root->priority);
    inorder(root->right);
}

void preorder (TreeNode * root, int h) {
    if (root == NULL) return;
    printf("key:%d h:%d priority:%d\n", root->num, h, root->priority);
    preorder(root->left, h+1);
    preorder(root->right, h+1);
}

TreeNode * del (TreeNode * root, int num) {
    if (root == NULL) return root;

    if (root->num < num)
        root->setRight(del(root->right, num));
    else if (root->num > num)
        root->setLeft(del(root->left, num));

    // if root->num == num
    else {
        return merge(root->left, root->right);
    }
   return root;
}

int main() {
    cout << "number of inputs:" ;
    int n;
    cin >> n;
    int num;
    cin >> num;
    TreeNode * root = new TreeNode(num);
    while(--n) {
        cin >> num;
        root = insert(root, new TreeNode(num));
    }

    cout << " - inorder - " << endl;
    inorder(root);
    cout << endl;

    cout << " - preorder - " << endl;
    preorder(root, 0);
    cout << endl;

    cout << "delete : ";
    cin >> n;
    while(n--) {
        cin >> num;
        root = del(root ,num);
    }

    cout << " - inorder after delete - " << endl;
    inorder(root);
    cout << endl;

    cout << " - preorder - " << endl;
    preorder(root, 0);
    cout << endl;

    return 0;
}
