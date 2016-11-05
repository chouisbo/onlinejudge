/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getListLength(struct ListNode *head) {
    struct ListNode *p = head;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (NULL == headA || NULL == headB) return NULL;
    int lenA = getListLength(headA); 
    int lenB = getListLength(headB);
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    while (lenA > lenB) {
        pA = pA->next;
        lenA--;
    }
    while (lenB > lenA) {
        pB = pB->next;
        lenB--;
    }
    while (lenA > 0) {
        if (pA == pB) {
            return pA;
        } else {
            pA = pA->next;
            pB = pB->next;
            lenA--;
        }
    }
    return NULL;
}
