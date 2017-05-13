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
        // iterative preorder using stack
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> trace;
            stack<TreeNode*> st;
            if (root != NULL)
                st.push(root);
            while (!st.empty()) {
                TreeNode * cur = st.top();
                st.pop();
                trace.push_back(cur->val);
                if (cur->right)
                    st.push(cur->right);
                if (cur->left)
                    st.push(cur->left);
            }
            return trace;
        }


        // This iteration shows how real recursive call to be stacked
        vector<int> preorderTraversal2(TreeNode* root) {
            vector<int> trace;
            // (node, num) num=0 before visit, num=1 if only left visited, num=2 if both visited
            stack<pair<TreeNode*,int> > st;
            if (root != NULL)
                st.push(make_pair(root,0));
            while (!st.empty()) {
                TreeNode * cur = st.top().first;
                int opt = st.top().second;
                st.pop();
                if (opt == 0) {
                    trace.push_back(cur->val);
                    st.push(make_pair(cur,opt+1));
                    if (cur->left)
                        st.push(make_pair(cur->left,0));
                } else if (opt == 1) {
                    st.push(make_pair(cur,opt+1));
                    if (cur->right)
                        st.push(make_pair(cur->right,0));
                } else {
                    //printf("%d returned\n", cur->val);
                }
            }
            return trace;
        }
};
