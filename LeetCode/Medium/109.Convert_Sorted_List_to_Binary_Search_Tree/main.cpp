/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
        ////////////////////////////////////////////////////////////////
        // Solution 1) build array list, and then convert array to BST
        // Time : O(n)
        // Extra Space : O(n)
        ////////////////////////////////////////////////////////////////
        TreeNode* sortedArrayToBST (vector<int> &nums, int l, int r) {
            if (l >= r) return NULL;
            int mid = (l+r)/2;
            TreeNode * root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBST(nums, l, mid);
            root->right = sortedArrayToBST(nums, mid+1, r);
            return root;
        }
        TreeNode* sortedListToBST(ListNode* head) {
            vector<int> nums;
            while (head) {
                nums.push_back(head->val);
                head = head->next;
            }
            return sortedArrayToBST(nums, 0, nums.size());
        }

        ////////////////////////////////////////////////////////////////
        // Solution 2) Inorder
        // Time : O(n)
        // Extra Space : O(n) (only for building tree, recursive stack O(logn))
        ////////////////////////////////////////////////////////////////
        TreeNode* sortedListToBST(ListNode *&head, int start, int end) { // [start, end)
            if (start >= end) return NULL;
            int mid = (start+end)/2;
            TreeNode *left = sortedListToBST(head, start, mid);
            TreeNode *root = new TreeNode (head->val);
            head = head->next;
            TreeNode *right = sortedListToBST(head, mid+1, end);
            root->left = left;
            root->right = right;
            return root;
        }
        TreeNode* sortedListToBST(ListNode* head) {
            int len = 0;
            ListNode *cur = head;
            while (cur) {
                len++;
                cur = cur->next;
            }
            return sortedListToBST(head, 0, len);
        }

};
