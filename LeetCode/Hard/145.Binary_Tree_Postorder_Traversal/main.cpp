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

        // void postorder(TreeNode* root) {
        //    if (root == NULL) // 0
        //        return;
        //    postorder(root->left); // 1
        //    postorder(root->right); // 2
        //    visit(root);
        //}
        // Iterative postorder traversal
        // This function mainly focus on how recursive call stacked
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> trace;
            stack<pair<TreeNode*, int> > st;
            st.push(make_pair(root,0));
            while (!st.empty()) {
                TreeNode * cur = st.top().first;
                int opt = st.top().second;
                st.pop();
                if (cur == NULL)
                    continue;
                switch (opt) {
                    case 0:
                        st.push(make_pair(cur, opt+1));
                        st.push(make_pair(cur->left,0));
                        break;
                    case 1:
                        st.push(make_pair(cur, opt+1));
                        st.push(make_pair(cur->right,0));
                        break;
                    case 2:
                        // visit
                        trace.push_back(cur->val);
                        break;
                }
            }
            return trace;
        }

        // use simple preorder (visit - right - left) solution,
        // and then reverse. (left - right - visit)
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> trace;
            stack<TreeNode*> st;
            if (root != NULL)
                st.push(root);
            while (!st.empty()) {
                TreeNode * cur = st.top();
                st.pop();
                trace.push_back(cur->val);
                if (cur->left != NULL)
                    st.push(cur->left);
                if (cur->right != NULL)
                    st.push(cur->right);
            }
            reverse(trace.begin(), trace.end());
            return trace;
        }
};
