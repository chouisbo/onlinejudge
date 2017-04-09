/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *pd = head;
    while (pd != NULL && p != NULL) {
        p = p->next;
        if (NULL == pd->next) return NULL;
        pd = pd->next->next;
        if (p == pd) {
            p = head;
            while (p != pd) {
                p = p->next;
                pd = pd->next;
            }
            return p;
        }
    }
    return NULL;
}