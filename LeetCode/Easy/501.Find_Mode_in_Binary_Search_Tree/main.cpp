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
    void inOrder(TreeNode* root, int& curVal, int& curCnt, int& maxCnt, vector<int>& MODS) {
        if (root == NULL) return;
        inOrder(root->left, curVal, curCnt, maxCnt, MODS);
        if (curVal == root->val)
            curCnt++;
        else {
            curVal = root->val;
            curCnt = 1;
        }
        if (curCnt > maxCnt) {
            MODS.clear();
            MODS.push_back(curVal);
            maxCnt = curCnt;
        } else if (curCnt == maxCnt) {
            MODS.push_back(curVal);
        }
        inOrder(root->right, curVal, curCnt, maxCnt, MODS);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int curVal = 0, curCnt = 0, maxCnt = 0;
        inOrder(root, curVal, curCnt, maxCnt, res);
        return res;
    }
};
