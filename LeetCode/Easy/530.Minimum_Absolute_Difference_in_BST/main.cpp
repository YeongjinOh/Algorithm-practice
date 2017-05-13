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
    void inorder(TreeNode * root, int& lastVal, int& minDiff, bool& firstVisit) {
        if (root == NULL) return;
        inorder(root->left, lastVal, minDiff, firstVisit);
        // visit
        if (firstVisit) {
            lastVal = root->val;
            firstVisit = false;
        } else {
            int curDiff = abs(lastVal - root->val);
            if (minDiff == -1 || curDiff < minDiff) minDiff = curDiff;
            lastVal = root->val;
        }
        inorder(root->right, lastVal, minDiff, firstVisit);
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = -1;
        int lastVal = 0;
        bool firstVisit = true;
        inorder(root, lastVal, minDiff, firstVisit);
        return minDiff;
    }
};

// Solution 2 using bound
class Solution2 {
public:
    int getMinDiffUsingBound(TreeNode* root, int lb, int ub) {
        int res = INT_MAX;
        if (lb != -INT_MAX) res = root->val-lb;
        if (ub != INT_MAX) res = min(res, ub-root->val);
        if (root->left) res = min(res, getMinDiffUsingBound(root->left,lb,root->val));
        if (root->right) res = min(res, getMinDiffUsingBound(root->right,root->val,ub));
        return res;
    }
    int getMinimumDifference(TreeNode* root) {
        return getMinDiffUsingBound(root, -INT_MAX, INT_MAX);
    }
};
