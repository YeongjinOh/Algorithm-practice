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
        ////////////////////////////////////////
        // First way using recursion.
        // Extra space : O(n) (recursive stack)
        ////////////////////////////////////////
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL) return head;
            ListNode * cur = head;
            if (cur->next) {
                head = cur->next;
                cur->next = swapPairs(head->next);
                head->next = cur;
            }
            return head;
        }

        ////////////////////////////////////////
        // Second way without using recursion
        // Extra space : O(1)
        ////////////////////////////////////////
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL) return head;
            ListNode *cur = head, *last = head;
            if (cur->next) {
                head = cur->next;
            }
            while (cur && cur->next) {
                last->next = cur->next;
                last = last->next;
                cur->next = last->next;
                last->next= cur;
                last = cur;
                cur = cur->next;
            }
            return head;
        }
};
