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

        // void inorder(TreeNode* root) { <- 0
        //    if (root == NULL)
        //        return;
        //    inorder(root->left); <- 1
        //    visit(root);
        //    inorder(root->right); <- 2
        // }
        // This function focused on how recursive function works
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> trace;
            stack<pair<TreeNode*, int> > st;
            st.push(make_pair(root,0));
            while (!st.empty()) {
                TreeNode *cur = st.top().first;
                int opt = st.top().second;
                st.pop();
                if (cur == NULL)
                    continue;
                switch (opt) {
                    case 0:
                        st.push(make_pair(cur,opt+1));
                        st.push(make_pair(cur->left,0));
                        break;
                    case 1:
                        // visit
                        trace.push_back(cur->val);
                        st.push(make_pair(cur,opt+1));
                        st.push(make_pair(cur->right,0));
                        break;
                    case 2:
                        // return;
                        break;
                }
            }
            return trace;
        }

        // simple solution using stack
        vector<int> inorderTraversal2(TreeNode* root) {
            vector<int> trace;
            stack<TreeNode*> st;
            TreeNode * cur = root;
            while (!st.empty() || cur != NULL) {
                if (cur == NULL) {
                    cur = st.top();
                    st.pop();
                    trace.push_back(cur->val);
                    cur = cur->right;
                } else {
                    st.push(cur);
                    cur = cur->left;
                }
            }
            return trace;
        }
};
