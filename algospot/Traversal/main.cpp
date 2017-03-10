#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 100
using namespace std;
int C, n;
int preorder[MAX], inorder[MAX];
struct TreeNode {
    int num;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int num) : num(num) { }
};

// [preL,preR] : preorder range
// [inL, inR] : inorder range
TreeNode * buildTree (int preL, int preR, int inL, int inR) {
    int inIdx;
    for (inIdx=inL; inIdx<=inR; inIdx++) {
        if (preorder[preL] == inorder[inIdx])
            break;
    }
    TreeNode * root = new TreeNode(preorder[preL]);
    if (inL < inIdx)
        root->left = buildTree(preL+1, preL+inIdx-inL, inL, inIdx-1);
    if (inIdx < inR)
        root->right = buildTree(preL+inIdx-inL+1, preR, inIdx+1, inR);

    return root;
}

void postOrder(TreeNode * root) {
    if (root->left)
        postOrder(root->left);
    if (root->right)
        postOrder(root->right);
    printf("%d ", root->num);
}
int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; i++)
            scanf("%d",preorder+i);
        for (int i=0; i<n; i++)
            scanf("%d",inorder+i);
        TreeNode * root = buildTree (0, n-1, 0, n-1);
        postOrder(root);
        cout << endl;
    }
}
