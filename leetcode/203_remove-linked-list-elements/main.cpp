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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = head;
        while (prev != NULL && prev->val == val) {
            prev = prev->next;
        }
        ListNode *newHead = prev;
        if (NULL == prev) return newHead;

        ListNode *p = prev->next;
        while (p != NULL) {
            if (p->val != val) {
                prev->next = p;
                prev       = p;
            }
            p = p->next;
        }
        prev->next = NULL;
        return newHead;
    }
};
