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
        ////////////////////////////////////////////
        // Solution 1) BFS using stack
        // Extra space : O(n)
        ////////////////////////////////////////////
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


        //////////////////////////////////////////////
        // Solution 2) Iteration along left most side
        // Extra space : O(1)
        //////////////////////////////////////////////
        void connect(TreeLinkNode *root) {
            TreeLinkNode *start = root;
            while (start) {
                TreeLinkNode *cur = start, *prev = NULL;
                while(cur) {
                    if (prev) prev->next = cur->left;
                    if (cur->left) cur->left->next = cur->right;
                    prev = cur->right;
                    cur = cur->next;
                }
                start = start->left;
            }
        }
};
