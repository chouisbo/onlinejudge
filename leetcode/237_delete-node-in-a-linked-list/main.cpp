#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (NULL == node) return;
        ListNode *prev = NULL;
        while (node->next != NULL) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
};

void printLinkedList(ListNode *pHead) {
    ListNode *p = pHead;
    while (p != NULL) {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
}

void test_01() {
    ListNode *pFirst  = new ListNode(0);
    ListNode *pSecond = new ListNode(1);
    pFirst->next = pSecond;

    printLinkedList(pFirst);
    Solution c;
    c.deleteNode(pFirst);
    printLinkedList(pFirst);
}


int main(int argc, char const *argv[])
{
    test_01();
	return 0;
}

