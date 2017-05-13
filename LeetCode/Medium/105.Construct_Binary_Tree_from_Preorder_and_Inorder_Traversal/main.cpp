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
        ///////////////////////////////////////////////////////////////
        // Solutionn 1) preorder recursion
        ///////////////////////////////////////////////////////////////
        TreeNode* buildTree(vector<int>& preorder, unordered_map<int,int>& hs, int pl, int pr, int il, int ir) {
            if (pl > pr) return NULL;
            int val = preorder[pl];
            TreeNode *root = new TreeNode(val);
            int mid = hs[val];
            int leftLen = mid-il;
            root->left = buildTree(preorder, hs, pl+1, pl+leftLen, il, mid-1);
            root->right = buildTree(preorder, hs, pl+leftLen+1, pr, mid+1, ir);
            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> hs; // inorder (value, idx);
            for (int i=0; i<inorder.size(); i++) hs[inorder[i]] = i;
            return buildTree(preorder, hs, 0, preorder.size()-1, 0, inorder.size()-1);
        }

        ///////////////////////////////////////////////////////////////
        // Solution 2) BFS (implement iteratively)
        ///////////////////////////////////////////////////////////////
        typedef pair<pair<TreeNode*,int>, pair<int, int> > tp;
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int n = preorder.size();
            if (n==0) return NULL;

            unordered_map<int, int> hs; // inorder (value, idx);
            for (int i=0; i<n; i++) hs[inorder[i]] = i;
            queue<tp> q;
            TreeNode *root = new TreeNode(preorder[0]);
            q.push(make_pair(make_pair(root,n), make_pair(0, 0)));
            while (!q.empty()) {
                tp cur = q.front();
                q.pop();
                TreeNode* curNode = cur.first.first;
                int len = cur.first.second, preStart = cur.second.first, inStart = cur.second.second;
                int mid = hs[preorder[preStart]]; // index of median in inorder
                int leftLen = mid-inStart, rightLen = len - leftLen - 1;
                if (rightLen > 0) {
                    curNode->right = new TreeNode(preorder[preStart+1+leftLen]);
                    q.push(make_pair(make_pair(curNode->right,rightLen),make_pair(preStart+1+leftLen, mid+1)));
                }
                if (leftLen > 0) {
                    curNode->left = new TreeNode(preorder[preStart+1]);
                    q.push(make_pair(make_pair(curNode->left,leftLen),make_pair(preStart+1, inStart)));
                }

            }
            return root;
        }

};
