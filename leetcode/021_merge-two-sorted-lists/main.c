/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (NULL == l1) return l2;
    if (NULL == l2) return l1;
    
    struct ListNode *head, *p, *p1, *p2;
    p1 = l1; p2 = l2;
    if (l1->val <= l2->val) {
        head = p1;
        p1   = p1->next;
    } else {
        head = p2;
        p2   = p2->next;
    }
    p = head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            p->next = p1; p1 = p1->next;
        } else {
            p->next = p2; p2 = p2->next;
        }
        p = p->next;
    }

    if (NULL == p1) p->next = p2;
    if (NULL == p2) p->next = p1;

    return head;
}
