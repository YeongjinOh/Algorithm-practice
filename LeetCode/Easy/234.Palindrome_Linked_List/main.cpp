/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:

        // with reversing
        // Time : O(n)
        // Extra Space : O(1)
        bool isPalindrome(ListNode* node) {
            if (node == NULL) return true;
            ListNode * cur = node;
            int len = 0;
            while (cur != NULL) {
                cur = cur->next;
                len++;
            }
            ListNode *leftHalf = NULL, *rightHalf = node;
            for (int i=0; i<len/2; i++) {
                ListNode *tmp = rightHalf;
                rightHalf = rightHalf->next;
                tmp->next = leftHalf;
                leftHalf = tmp;
            }
            cout << len << endl;
            if (len%2 != 0) rightHalf = rightHalf->next;
            while (leftHalf != NULL && rightHalf != NULL) {
                cout << leftHalf->val << " " << rightHalf->val << endl;
                if (leftHalf->val != rightHalf->val) return false;
                leftHalf = leftHalf->next;
                rightHalf = rightHalf->next;
            }
            return true;
        }
        // use slow/fast instead of pre-calculating length
        bool isPalindrome2(ListNode* node) {
            ListNode *slow = node, *fast = node;
            while (fast!= NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *reverse = NULL, *next=node;
            while (next != slow) {
                ListNode *tmp = reverse;
                reverse = next;
                next = next->next;
                reverse->next = tmp;
            }
            if (fast != NULL) next = next->next;
            while (reverse != NULL && next != NULL) {
                if (reverse->val != next->val)
                    return false;

                reverse = reverse->next;
                next = next->next;
            }
            return true;

        }
};
