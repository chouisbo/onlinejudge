#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>

using namespace std;


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// 
// You must do this in-place without altering the nodes' values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

class Solution {
public:

    ListNode * createList(const vector<int> &vec) {
        if (vec.size() <=0) { return NULL; }
        ListNode *head = new ListNode(vec[0]);
        ListNode *p = head;
        for (vector<int>::size_type i=1; i<vec.size(); ++i, p=p->next) {
            ListNode *cur = new ListNode(vec[i]);
            p->next = cur;
        }
        return head;
    }

    void destroyList(ListNode *head) {
        ListNode *p = head, *q;
        while (p != NULL) {
            q = p;
            p = p->next;
            delete q;
        }
    }

    void printList(ListNode *head) {
        ListNode *p = head;
        while (p != NULL) {
            cout << p->val << ", ";
            p = p->next;
        }
        cout << endl;
    }

    ListNode * getHalfListNode(ListNode *head) {
        if (NULL == head) return NULL;

        ListNode *p = head;
        ListNode *q = head;

        while ((q = q->next) != NULL) {
            p = p->next;
            q = q->next;
            if (NULL == q) break;
        }

        return p;
    }

    ListNode * reverseList(ListNode *head) {
        if (NULL == head) return NULL;
        ListNode *p = head, *pHead = head, *q;
        while (p->next != NULL) {
            q = p->next;
            p->next = q->next;
            q->next = pHead;
            pHead = q;
        }
        return pHead;
    }

    void reorderList(ListNode* head) {
        ListNode *pHalf = getHalfListNode(head);
        ListNode *p = head, *pNext;
        ListNode *q = reverseList(pHalf), *qNext;
        while (p != pHalf) {
            pNext = p->next;
            qNext = q->next;
            p->next = q;
            if (pNext == pHalf) { break; }
            q->next = pNext;
            p = pNext;
            q = qNext;
        }
    }

};

int main(int argc, const char* argv[]) {
    
    vector<int> v = {1,2,3,4};
    Solution s;
    
    ListNode *p = s.createList(v);
    s.printList(p);
    s.reorderList(p);
    s.printList(p);

    
    // ListNode *pHalf = s.getHalfListNode(p);
    // s.printList(pHalf);
    // ListNode *pReverseHalf = s.reverseList(pHalf);
    // s.printList(pReverseHalf);
    // s.printList(p);

    // s.destroyList(p);

    return 0;
}



