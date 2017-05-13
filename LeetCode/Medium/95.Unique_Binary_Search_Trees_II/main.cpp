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
        vector<TreeNode*> generateTrees(int start, int end) {
            vector<TreeNode*> res;
            if (start > end) {
                res.push_back(NULL);
                return res;
            }
            for (int mid=start; mid<=end; mid++) {
                vector<TreeNode*> leftSubTrees = generateTrees(start, mid-1);
                vector<TreeNode*> rightSubTrees = generateTrees(mid+1, end);
                for (int l=0; l<leftSubTrees.size(); l++) {
                    for (int r=0; r<rightSubTrees.size(); r++) {
                        TreeNode *cur = new TreeNode(mid);
                        cur->left = leftSubTrees[l];
                        cur->right = rightSubTrees[r];
                        res.push_back(cur);
                    }
                }
            }
            return res;
        }
        vector<TreeNode*> generateTrees(int n) {
            if (n==0) return vector<TreeNode*>();
            return generateTrees(1,n);
        }
};
