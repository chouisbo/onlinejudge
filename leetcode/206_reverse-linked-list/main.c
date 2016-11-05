
#include <stdio.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (NULL == head) {
    	return NULL;
    }
    struct ListNode* pHead    = head;
    struct ListNode* pNext;
    struct ListNode* pNewHead = NULL;
    while (pHead != NULL) {
    	pNext       = pHead->next;
    	pHead->next = pNewHead;
    	pNewHead    = pHead;
    	pHead       = pNext;
    }
    return pNewHead;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}

