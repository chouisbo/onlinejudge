/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. 
 * You may not modify the values in the list, only nodes itself can be changed.
 **/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head);
void destroyList(ListNode *head);

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next) return head;
        ListNode *pHeadOdd = head, *pHeadEven = head->next;
        ListNode *p1 = pHeadOdd;
        ListNode *p2 = pHeadEven;
        ListNode *p  = head->next->next; 
        bool bFlip = true;
        while (p != NULL) {
            if (bFlip) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
            bFlip = ! bFlip;
        }
        p1->next = NULL;
        p2->next = NULL;
        /* cout << "### "; printList(pHeadOdd); */
        /* cout << "### "; printList(pHeadEven); */
        p1 = pHeadOdd; p2 = pHeadEven;
        bFlip = false;
        while (p1 != NULL && p2 != NULL) {
            if (bFlip) {
                p = p1->next;
                p1->next = p2;
                p1 = p;
            } else {
                p = p2->next;
                p2->next = p1;
                p2 = p;
            }
            bFlip = !bFlip;
        }
        return pHeadEven;
    }
};

void printList(ListNode *head) {
    ListNode *p = head;
    while (p != NULL) {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
}

void destroyList(ListNode *head) {
    ListNode *p = head, *pNext;
    while (p != NULL) {
        pNext = p->next;
        delete p;
        p = pNext;
    }
}

int main(void) {

    // * Given 1->2->3->4, you should return the list as 2->1->4->3.
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2); p = p->next;
    p->next = new ListNode(3); p = p->next;
    p->next = new ListNode(4); p = p->next;
    p->next = new ListNode(5);
    printList(head);

    Solution s;
    head = s.swapPairs(head);
    printList(head);

    destroyList(head);

    return 0;
}


