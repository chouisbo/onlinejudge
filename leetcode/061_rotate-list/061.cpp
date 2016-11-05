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


// 
// Given a list, rotate the list to the right by k places, where k is non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.
// 

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

    ListNode* rotateRight(ListNode* head, int k) {
        if (k < 0 || NULL == head) return NULL;
        if (0 == k) return head;
        ListNode *p = head, *q = head, *qPrev;

        int len = 0;
        for (p = head; p != NULL; p = p->next) len++;
        k = k % len;
        if (0 == k) return head;

        for (p = head; k > 0 && p != NULL; p = p->next) k--;
    
        if (NULL == p) return head;

        while (p != NULL) {
            p = p->next;
            qPrev = q;
            q = q->next;
        }

        while (q->next != NULL) {
            q = q->next;
        }
        q->next = head;
        q = qPrev->next;
        qPrev->next = NULL;

        return q;
    }

};

void _test(const vector<int>& v, int k) {
    Solution s;
    ListNode *p = s.createList(v);
    s.printList(p);
    cout << "right shift " << k << " ==>" << endl;
    s.printList(s.rotateRight(p, k));
    cout << "-----------------------------------" << endl;
    s.destroyList(p);
}

int main(int argc, const char* argv[]) {
    
    vector<int> v = {1,2,3,4,5};
    for (int i=0; i<=v.size(); i++) {
        _test(v, i);    
    }

    _test(v, 2000000000);

    return 0;
}



