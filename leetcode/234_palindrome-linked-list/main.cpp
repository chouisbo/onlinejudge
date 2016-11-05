#include <vector>
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
    bool isPalindrome(ListNode* head) {
        if (NULL == head) return true;
        int len = 1;
        ListNode *p=head, *q=NULL;
        while ((p=p->next) != NULL) len++;
        if (1 == len) return true;
        ListNode *pHalfHead=head;
        for (int i=0; i<(len+1)/2; ++i) {
            pHalfHead = pHalfHead->next;
        }
        ListNode *pRHalfHead = reverseList(pHalfHead);
        bool rtCode = true;
        for (p=head, q=pRHalfHead; q != NULL;) {
            if (p->val != q->val) {
                rtCode = false;
                break;
            }
            p=p->next;
            q=q->next;
        }
        reverseList(pRHalfHead);
        return rtCode;
    }

    static ListNode* reverseList(ListNode* head) {
        if (NULL == head) {
            return NULL;
        }
        ListNode* pHead    = head;
        ListNode* pNext;
        ListNode* pNewHead = NULL;
        while (pHead != NULL) {
            pNext       = pHead->next;
            pHead->next = pNewHead;
            pNewHead    = pHead;
            pHead       = pNext;
        }
        return pNewHead;
    }

    static void printLinkedList(ListNode *head) {
        ListNode *p = head;
        while (p!= NULL) {
            cout << p->val << ", ";
            p = p->next;
        }
        cout << endl;
    
    }

    static ListNode* createLinkedListByVector(const vector<int> &v) {
        if (v.size() <= 0) return NULL;
        ListNode *head = new ListNode(v[0]);
        ListNode *pc   = head;
        for (size_t i=1; i<v.size(); ++i) {
            ListNode *p = new ListNode(v[i]);
            pc->next = p;
            pc = p;
        }
        return head;
    }

    static void destroyLinkedList(ListNode *head) {
        if (NULL == head) return;
        ListNode *p = head, *pc;
        while (p != NULL) {
            pc = p;
            p  = p->next;
            delete pc;
        }
    }

};

int main(int argc, const char *argv[]) {
//    vector<int> v {1, 2, 3, 4, 5, 6};
    vector<int> v {1, 2, 3, 3, 2, 1};
    Solution s;
    ListNode *head  = Solution::createLinkedListByVector(v);
    cout << "isPalindrome = " << s.isPalindrome(head) << endl;
    Solution::destroyLinkedList(head);
    return 0;
}

