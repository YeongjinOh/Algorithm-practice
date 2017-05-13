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
		// using BFS
		int findBottomLeftValue(TreeNode* root) {
			if (root == NULL)
				return 0;
			int leftMost = 0;
			queue<TreeNode *> q;
			q.push(root);
			while (!q.empty()) {
				for (int i=0, n=q.size(); i<n; i++) {
					TreeNode * cur = q.front();
					q.pop();
					if (i==0)
						leftMost = cur->val;
					if (cur->left) q.push(cur->left);
					if (cur->right) q.push(cur->right);
				}
			}
			return leftMost;
		}

		// using DFS
		void preorder (TreeNode * root, int level, int& lowestLevel, int& leftMostValue) {
			if (root == NULL) return;
			preorder(root->left, level+1, lowestLevel, leftMostValue);
			if (level > lowestLevel) {
				lowestLevel = level;
				leftMostValue = root->val;
			}
			preorder(root->right, level+1, lowestLevel, leftMostValue);
		}
		int findBottomLeftValueDFS(TreeNode* root) {
			int lowestLevel = 0, leftMostValue = 0;
			preorder(root, 1, lowestLevel, leftMostValue);
			return leftMostValue;
		}
};
