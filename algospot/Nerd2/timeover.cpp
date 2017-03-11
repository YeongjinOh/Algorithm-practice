#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

//////////////////////////////////////////////////////
// I implemented binary search tree, but not balanced
// so, it's timeover
// TODO : implement balanced binary search tree to overcome timeover
//////////////////////////////////////////////////////

using namespace std;
int C, n, cnt, sum, p, q;

struct TreeNode {
    int p, q;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int p, int q) : p(p), q(q), left(NULL), right(NULL) { }
};

TreeNode * del (TreeNode * root) {
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;
    TreeNode * tmp = root->right;
    if (tmp->left == NULL) {
        tmp->left = root->left;
        return tmp;
    }
    while(tmp->left->left != NULL) { tmp = tmp->left;}
    root->p = tmp->left->p;
    root->q = tmp->left->q;
    tmp->left = del(tmp->left);
    return root;
}

TreeNode * insert (TreeNode * root, int p, int q) {
    if (root == NULL) {
        root = new TreeNode(p,q);
        cnt++;
        return root;
    }
    if (root->p > p && root->q > q) return root;
    if (root->p < p && root->q < q) {
        root = del(root);
        cnt--;
        root = insert (root, p, q);
        return root;
    }
    if (root->p < p) { // && root->q > q
        root->right = insert(root->right, p, q);
    } else {
        root->left = insert(root->left, p, q);
    }
    return root;
}


int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        cnt = 0;
        sum = 0;
        TreeNode * root = NULL;
        for (int i=0; i<n; i++) {
            scanf("%d%d",&p,&q);
            root = insert(root, p, q);
            sum += cnt;
        }
        cout << sum << endl;
    }
}
