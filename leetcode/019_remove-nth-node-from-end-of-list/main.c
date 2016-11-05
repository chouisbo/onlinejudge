/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *prev = head;
    struct ListNode *p    = head;
    while (n-- > 0) {
        prev = prev->next;
    }
    if (NULL == prev) return head->next; 
    while (prev->next != NULL) {
        prev = prev->next;
        p = p->next;
    }
    struct ListNode *d = p->next;
    p->next = p->next->next;
    free(d);
    return head;
}
