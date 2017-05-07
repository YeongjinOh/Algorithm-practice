#include <iostream>
using namespace std;

struct TreeNode {
    int num, height;
    TreeNode *left, *right;
    TreeNode(int num) : num(num), height(1), left(NULL), right(NULL) { }
    void updateHeight() {
        height = 1;
        if (left) height = max<int> (height, left->height+1);
        if (right) height = max<int> (height, right->height+1);
    }
};

int getHeight(TreeNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(TreeNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* rotateLeft(TreeNode* root) {
    if (root == NULL) return root;
    TreeNode* right = root->right;
    root->right = right->left;
    right->left = root;
    root->updateHeight();
    right->updateHeight();
    return right;
}

TreeNode* rotateRight(TreeNode* root) {
    if (root == NULL) return root;
    TreeNode* left = root->left;
    root->left = left->right;
    left->right = root;
    root->updateHeight();
    left->updateHeight();
    return left;
}
TreeNode* insert(TreeNode* root, int num) {
    if (root == NULL) return new TreeNode(num);
    if (root->num < num) {
        root->right = insert(root->right, num);
    } else {
        root->left = insert(root->left, num);
    }

    // update height
    root->updateHeight();

    // rotate
    int balance = getBalance(root);
    if (balance > 1) {
        if (root->left->num < num)
            root->left = rotateLeft(root->left);
        root = rotateRight(root);
    } else if (balance < -1) {
        if (root->right->num > num)
            root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}

TreeNode* minValueNode(TreeNode* root) {
    if (root == NULL) return root;
    while (root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* del(TreeNode* root, int num) {
    if (root == NULL) return root;
    if (root->num == num) {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        TreeNode* minVal = minValueNode(root->right);
        root->num = minVal->num;
        root->right = del(root->right, minVal->num);
    }
    if (root->num > num) {
        root->left = del(root->left, num);
    } else {
        root->right = del(root->right, num);
    }

    // update
    root->updateHeight();

    // check balance
    int balance = getBalance(root);
    if (balance > 1) {
        if (getBalance(root->left) < 0)
            root->left = rotateLeft(root->left);
        root = rotateRight(root);
    } else if (balance < -1) {
        if (getBalance(root->right) > 0)
            root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}

void inorder (TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->num);
    inorder(root->right);
}

int depth(TreeNode* root) {
    if (root == NULL) return -1;
    int d = max<int> (depth(root->left), depth(root->right)) + 1;
    if (d+1 != root->height) printf("d:%d height:%d\n", d, root->height);
    return d;
}

int count(TreeNode* root) {
    if (root == NULL) return 0;
    return count(root->left) + count(root->right) + 1;
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
        root = insert(root, num);
    }

    cout << " - inorder - " << endl;
    inorder(root);
    cout << endl;
    printf("depth :%d \n", depth(root));
    cin >> n;
    printf("delete %d elements\n", n);
    printf("cur count:%d\n", count(root));
    while(n--) {
        cin >> num;
        root = del(root ,num);
        printf("delete %d \t cnt %d\n", num, count(root));
        inorder(root);
        cout << endl;
    }

    cout << " - inorder after delete - " << endl;
    inorder(root);
    cout << endl;
    printf("depth :%d \n", depth(root));
    return 0;
}
