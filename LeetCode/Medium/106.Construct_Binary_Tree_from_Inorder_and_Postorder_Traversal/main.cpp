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
    TreeNode* buildTree(vector<int>& postorder, unordered_map<int,int>& hs, int startIn, int startPost, int len) {
        if (len <= 0) return NULL;
        int val = postorder[startPost+len-1];
        TreeNode *root = new TreeNode(val);
        int midIdx = hs[val];
        int leftLen = midIdx-startIn, rightLen = len-leftLen-1;
        root->left = buildTree(postorder, hs, startIn, startPost, leftLen);
        root->right = buildTree(postorder, hs, midIdx+1, startPost+leftLen, rightLen);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return NULL;
        unordered_map<int, int> hs;
        int n = inorder.size();
        for (int i=0; i<n; i++) hs[inorder[i]] = i;
        return buildTree(postorder,hs,0,0,n);
    }
};

