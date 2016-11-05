/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     struct ListNode *next;
 *      * };
 *       */
void deleteNode(struct ListNode* node) {
    if (NULL == node) return;
    struct ListNode *prev = NULL;
    while (node->next != NULL) {
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
}


