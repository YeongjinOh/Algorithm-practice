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
    TreeNode* sortedArrayToBSTRange(vector<int>& nums, int l, int r) {
        if (l>r) return NULL;
        if (l==r) return new TreeNode(nums[l]);
        int mid = (l+r)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTRange(nums,l,mid-1);
        root->right = sortedArrayToBSTRange(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTRange(nums, 0, nums.size()-1);
    }
};
