#include <stdlib.h>
#include <time.h>
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    int r;
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    /** Returns a random node's value. */
    int getRandom() {
        int n = 1; r = head->val;
        ListNode *p = head->next;
        while (p != NULL) {
            if (0 == (rand() % (++n))) {
                r = p->val;
            }
            p = p->next;
        }
        return r;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
