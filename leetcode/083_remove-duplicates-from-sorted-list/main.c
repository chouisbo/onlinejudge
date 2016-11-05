/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (NULL == head) return NULL;
    struct ListNode *prev = head;
    struct ListNode *p    = head;
    while ((p = p->next) != NULL) {
        if (prev->val == p->val) {
            continue;
        }
        prev->next = p;
        prev       = p;
    }
    prev->next = NULL;
    return head;
}
