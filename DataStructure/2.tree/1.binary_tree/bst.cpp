#include <iostream>
using namespace std;

struct TreeNode {
    int num;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int n):num(n), left(NULL), right(NULL) { }
};

TreeNode * insert(TreeNode * root, int num) {
    if (root == NULL)
        root = new TreeNode(num);
    else if (root->num > num)
        root->left = insert(root->left, num);
    else
        root->right = insert(root->right, num);
    return root;
}

void inorder (TreeNode * root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->num);
    inorder(root->right);
}

TreeNode * del (TreeNode * root, int num) {
    if (root == NULL) return root;

    if (root->num < num)
        root->right = del(root->right, num);
    else if (root->num > num)
        root->left = del(root->left, num);

    // if root->num == num
    else {
        if (root->left == NULL) {
            TreeNode * ret = root->right;
            free(root);
            return ret;
        }

        // get rightMost node of left subtree
        TreeNode * candidate = root->left;
        if (candidate->right == NULL) {
            candidate->right = root->right;
            free(root);
            return candidate;
        }
        while (candidate->right != NULL) {
            // change key
            root->num = candidate->num;
            root->left = del(root->left, root->num);
            return root;
        }
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
        insert(root, num);
    }

    cout << " - inorder - " << endl;
    inorder(root);
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
    return 0;
}
