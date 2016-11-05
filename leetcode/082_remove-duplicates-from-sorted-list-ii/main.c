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
    int dupFlag = 0;
    while ((p = p->next) != NULL) {
        if (prev->val == p->val) {
            dupFlag = 1;
            continue;
        }
        if (1 == dupFlag) {
            prev->val = p->val;
            prev->next = p->next;
            p = prev;
            dupFlag = 0;
        } else {
            prev = prev->next;
        }
    }
    prev->next = NULL;
    if (1 == dupFlag) {
        if (NULL == head->next) head = NULL;
        else {
            p = head->next;
            prev = head;
            while (p->next != NULL) {
                p = p->next;
                prev = prev->next;
            }
            prev->next = NULL;
        }
    }
    return head;
}
