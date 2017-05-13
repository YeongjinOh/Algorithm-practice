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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root != NULL)
            q.push(root);
        while (!q.empty()) {
            TreeNode * cur;
            for (int i=0, n=q.size(); i<n; i++) {
                cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(cur->val);
        }
        return res;
    }
};

