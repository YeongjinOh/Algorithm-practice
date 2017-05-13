/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    public:
        ///////////////////////////////////////////
        // Solution 1) BFS using stack
        // Extra space : O(n)
        ///////////////////////////////////////////
        void connect(TreeLinkNode *root) {
            queue<TreeLinkNode*> q;
            if (root)
                q.push(root);
            while (!q.empty()) {
                TreeLinkNode * last = NULL;
                for (int i=0, n=q.size(); i<n; i++) {
                    TreeLinkNode *cur = q.front();
                    q.pop();
                    if(last)
                        last->next = cur;
                    last = cur;
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);

                }
                //	last->next = NULL;
            }
        }

        //////////////////////////////////////////
        // Solution 2) Iteration
        // Extra space : O(1)
        //////////////////////////////////////////
        void connect2(TreeLinkNode *root) {
            TreeLinkNode* start = root;
            while (start) {
                // find the left most child
                TreeLinkNode* cur = start;
                start = NULL;
                while (cur) {
                    start = cur->left;
                    if (start == NULL) break;
                    start = cur->right;
                    if (start == NULL) break;
                    cur = cur->next;
                }
                TreeLinkNode *prev = start;
                while(cur) {
                    if (cur->left && prev != cur->left) {
                        prev->next = cur->left;
                        prev = cur->left;
                    }
                    if (cur->right && prev != cur->right) {
                        prev->next = cur->right;
                        prev = cur->right;
                    }
                    cur = cur->next;
                }

            }

        }
};
