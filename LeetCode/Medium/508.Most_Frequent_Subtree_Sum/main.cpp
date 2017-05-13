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
        int postorder(TreeNode* node, unordered_map<int, int>& hash, vector<int>& mfs, int& maxCnt) {
            if (node == NULL) return 0;
            int leftSum = postorder(node->left, hash, mfs, maxCnt);
            int rightSum = postorder(node->right, hash, mfs, maxCnt);
            int sum = leftSum + node->val + rightSum;
            if (hash.find(sum) != hash.end()) {
                ++hash[sum];
            } else {
                hash[sum] = 1;
            }
            int cnt = hash[sum];
            if (cnt == maxCnt) {
                mfs.push_back(sum);
            } else if (cnt > maxCnt) {
                maxCnt = cnt;
                mfs.clear();
                mfs.push_back(sum);
            }
            return sum;
        }
        vector<int> findFrequentTreeSum(TreeNode* root) {
            unordered_map<int, int> hash;
            int maxCnt = 0;
            vector<int> mfs;
            postorder(root,hash,mfs,maxCnt);
            return mfs;
        }
};
