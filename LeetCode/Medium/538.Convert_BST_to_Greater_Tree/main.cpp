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
    void reverseInorder(TreeNode *root, int &sum) {
        if (root == NULL) return;
        reverseInorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        reverseInorder(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
};
