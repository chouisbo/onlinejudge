# -*- coding: utf-8 -*-
import heapq


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def list2ListNode(list):
    if len(list) <= 0: return None
    head = ListNode(list[0])
    p = head
    for i in range(1, len(list)):
        p.next = ListNode(list[i])
        p = p.next
    return head


def outputListNode(head):
    p = head
    while p != None:
        print p.val,
        p = p.next
    print


class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head, p, h = None, None, []
        for i in range(len(lists)):
            if lists[i] is not None:
                heapq.heappush(h, (lists[i].val, i))
        if h:
            val, i = heapq.heappop(h)
            head = ListNode(val)
            p = head
            lists[i] = lists[i].next
            if lists[i] is not None:
                heapq.heappush(h, (lists[i].val, i))
        while h:
            val, i = heapq.heappop(h)
            p.next = ListNode(val)
            p = p.next
            lists[i] = lists[i].next
            if lists[i] is not None:
                heapq.heappush(h, (lists[i].val, i))
        return head


if __name__ == '__main__':
    s, lists = Solution(), []
    lists.append(list2ListNode([3, 3, 4, 5]))
    lists.append(list2ListNode([3, 5, 6, 7, 8, 9]))
    lists.append(list2ListNode([1, 2, 3, 4, 5]))
    outputListNode(s.mergeKLists(lists))
    




