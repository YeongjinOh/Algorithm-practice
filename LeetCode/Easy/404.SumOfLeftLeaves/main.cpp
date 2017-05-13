/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum (TreeNode * root, bool isLeft) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL && isLeft) return root->val;
        return sum(root->left,true) + sum(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root,false);
    }
};
