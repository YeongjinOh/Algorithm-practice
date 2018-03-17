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

    int postorder(TreeNode * root, int parentVal, int & lup) {
        if (root == NULL) return 0;
        int llup = postorder(root->left, root->val, lup);
        int rlup = postorder(root->right, root->val, lup);
        lup = max(lup, 1+llup+rlup);
        int res = 0;
        if (parentVal == root->val) {
            res = 1 + max(llup, rlup);
        }
        return res;
    }
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        int lup = 1;
        postorder(root, root->val, lup);
        return lup-1;
    }
};
