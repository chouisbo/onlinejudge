/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {

    if (NULL == head || NULL == head->next) return false;

    struct ListNode *p  = head;
    struct ListNode *p2 = (head->next)->next;

    while (p != NULL && p2 != NULL) {
        if (p == p2) return true;
        p  = p->next;
        p2 = p2->next;
        if (NULL == p2) break;
        p2 = p2->next;
    }

    return false;

}
