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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
	queue<TreeNode*> q;
	q.push(root);
	int depth = 0;
	while (!q.empty()) {
		depth++;
		for (int i=0, n = q.size(); i<n; i++) {
			TreeNode * cur = q.front();
			q.pop();
			if (cur->left == NULL && cur->right == NULL)
return depth;
			if (cur->left)
q.push(cur->left);
			if (cur->right)
q.push(cur->right);
		}
	}
    }
};
