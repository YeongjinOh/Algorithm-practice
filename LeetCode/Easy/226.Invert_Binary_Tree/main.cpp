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
	// dfs
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        TreeNode * tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }

	TreeNode* invertTreeBFS(TreeNode* root) {
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            TreeNode * cur = q.front(); q.pop();
            TreeNode * tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return root;
    }
};
