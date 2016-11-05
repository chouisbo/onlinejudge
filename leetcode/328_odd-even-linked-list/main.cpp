/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Example:
 * Given  1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 */

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (NULL == head) return head;
        if (NULL == head->next) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *head2 = head->next;
        bool qAtOdd = true;
        while (q->next != NULL) {
            p->next = q->next;
            p = q;
            q = p->next;
            qAtOdd = ! qAtOdd;
        }
        if (qAtOdd) {
            p->next = head2;
        } else {
            p->next = NULL;
            q->next = head2;
        }
        return head;
    }
};

