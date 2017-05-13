/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** Wrong solution.
 * Time : O(n^2)
class Solution {
public:
    int findSum (TreeNode * root) {
        if (root == NULL) return 0;
        return root->val + findSum(root->left) + findSum(root->right);
    }
    int findTilt(TreeNode* root) {
        if (root == NULL) return 0;
        return findTilt(root->left) + findTilt(root->right) + abs(findSum(root->left) - findSum(root->right));
    }
};
*/

// Right Solution use post order
// Time : O(n)
class Solution {
public:
    int postorder(TreeNode* root, int& sum) {
        if (root == NULL) return 0;
        int sumLeft = 0, sumRight = 0;
        int tiltLeft = postorder(root->left, sumLeft);
        int tiltRight = postorder(root->right, sumRight);
        sum = sumLeft + sumRight + root->val;
        return tiltLeft + tiltRight + abs(sumLeft-sumRight);
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        return postorder(root, sum);
    }
};
