/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseWithLength(struct ListNode* head, int len) {
    if (len <= 1) return head;
    struct ListNode *s = head, *p = s->next, *pn = NULL;
    while (--len) {
        pn = p->next;
        p->next = s;
        s = p;
        p = pn;
    }
    head->next = p;
    return s;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (n <= m) return head;
    if (1 == m) return reverseWithLength(head, n);
    struct ListNode *s = head;
    for (int i=1; i<m-1; i++) {
        s = s->next;
    }
    s->next = reverseWithLength(s->next, n-m+1);
    return head;
}
