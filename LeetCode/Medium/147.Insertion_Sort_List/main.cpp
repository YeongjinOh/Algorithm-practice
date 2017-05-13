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
        //////////////////////////////////////////////////
        // Solution 1) insertion sort using recursion
        // Time : O(n^2)
        //////////////////////////////////////////////////
        ListNode* insertionSortList(ListNode* head) {
            if (head == NULL) return head;
            ListNode* nxt = insertionSortList(head->next), *cur = nxt, *prev = NULL;
            while (cur && head->val > cur->val) {
                prev = cur;
                cur = cur->next;
            }
            if (prev) {
                prev->next = head;
                head->next = cur;
                return nxt;
            }
            head->next = nxt;
            return head;
        }

        //////////////////////////////////////////////////
        // Solution 2) insertion sort using iteration
        // Time : O(n^2)
        //////////////////////////////////////////////////
        ListNode* insertionSortList2(ListNode* head) {
            ListNode *bound = head;
            head = NULL;
            while (bound) {
                ListNode *nxt = bound->next;
                ListNode *cur = head, *prev = NULL;
                while (cur && cur->val < bound->val) {
                    prev = cur;
                    cur = cur->next;
                }
                if (prev) {
                    bound->next = cur;
                    prev->next = bound;
                } else {
                    bound->next = head;
                    head = bound;
                }
                bound = nxt;
            }
            return head;
        }
};

