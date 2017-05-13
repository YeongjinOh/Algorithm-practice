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
        int maxDepth(TreeNode* root) {
            // if (root == NULL) return 0;
            // return max(maxDepth(root->left), maxDepth(root->right)) + 1;
            // Let's use BFS
            queue<TreeNode*> q;
            if (root)
                q.push(root);
            int depth = 0;
            int curLevelCnt = 0, nextLevelCnt = 1;
            while (!q.empty()) {
                TreeNode* cur = q.front(); q.pop();
                if (curLevelCnt == 0) {
                    curLevelCnt = nextLevelCnt;
                    nextLevelCnt = 0;
                    depth++;
                }
                if (cur->left) {
                    q.push(cur->left);
                    nextLevelCnt++;
                }
                if (cur->right) {
                    q.push(cur->right);
                    nextLevelCnt++;
                }
                curLevelCnt--;
            }
            return depth;
        }
        // a little different implementation of BFS
        int maxDepth2(TreeNode* root) {
            queue<TreeNode*> q;
            if (root)
                q.push(root);
            int depth = 0;
            while (!q.empty()) {
                depth++;
                for (int i=0, n=q.size(); i<n; i++) {
                    TreeNode * cur = q.front(); q.pop();
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }
            }
            return depth;
        }
};
