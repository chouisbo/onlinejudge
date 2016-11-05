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

#define _MORE_TEST_ 1


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// 
// Sort a linked list using insertion sort.
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
        head = NULL;
    }

    void printList(ListNode *head) {
        ListNode *p = head;
        while (p != NULL) {
            cout << p->val << ", ";
            p = p->next;
        }
        cout << endl;
    }

    // searching range: [begin, end)
    void lower_bound(ListNode *begin, ListNode *end, int _val, ListNode * &q, ListNode * &qPrev) {
        q = begin; qPrev = NULL;
        while (q != end && q->val < _val) {
            qPrev = q;
            q = q->next;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        if (NULL == head) return NULL;
        ListNode *p = head->next, *pPrev = head, *q, *qPrev;
        while (p != NULL) {
            // lower_bound(head, p, p->val, q, qPrev);
            q = head; qPrev = NULL;
            while (q != p && q->val < p->val) {
                qPrev = q;
                q = q->next;
            }

            if (q != p) {
                pPrev->next = p->next;
                p->next = q;
                if (NULL == qPrev) {
                    head = p;
                } else {
                    qPrev->next = p;
                }
                p = pPrev->next;
            } else {
                pPrev = p;
                p = p->next;
            }
        }
        return head;
    }

};

int main(int argc, const char* argv[]) {
    
    // vector<int> v = {3, 1, 2};
#ifdef _MORE_TEST_
    vector<int> v;
    for (int i=1; i<=9; i++) {
        for (int j=0; j<i; j++) {
            v.push_back(i);
        }
    }
#endif
    Solution s;
    ListNode *p = NULL;

    p = s.createList(v);
    s.printList(p);
    // ListNode *q, *qPrev;
    // s.lower_bound(p, p->next, p->next->val, q, qPrev);
    // cout << q->val << endl;
    // if (NULL == qPrev) {
    //     cout << "qPrev is NULL" << endl;
    // } else {
    //     cout << "qPrev is not NULL" << endl;
    // }
    // cout << "-----------------------------------" << endl;
    p = s.insertionSortList(p);
    s.printList(p);
    s.destroyList(p);

#ifdef _MORE_TEST_
    std::random_device rd;
    std::mt19937 g(rd());

    for (int i=0; i<10; i++) {
        std::shuffle(v.begin(), v.end(), g);
        p = s.createList(v);
        s.printList(p);
        cout << "sorted " << " ==>" << endl;
        p = s.insertionSortList(p);
        s.printList(p);
        cout << "-----------------------------------" << endl;
        s.destroyList(p);
    }
#endif

    return 0;
}



