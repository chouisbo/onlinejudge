# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def list2ListNode(list):
    if len(list) <= 0: return None
    head = ListNode(list[0])
    p = head
    for val in list[1:]:
        q = ListNode(val)
        p.next = q
        p = q
    return head


def outputListNode(head):
    p = head
    while p is not None:
        print p.val,
        p = p.next
    print
    print '=' * 80




class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if head is None: return None
        newHead = ListNode(-1)
        newHead.next = head
        p = newHead
        while p.next is not None and p.next.val < x: p = p.next
        if p.next is None: return head
        t = p
        q = p.next
        p = p.next
        while p.next is not None:
            if p.next.val >= x: 
                p = p.next
            else:
                t.next = p.next
                pnn = p.next.next
                p.next.next = q
                p.next = pnn
                t = t.next
        return newHead.next



if __name__ == '__main__':
    s = Solution()
    outputListNode(s.partition(list2ListNode([1,4,3,2,5,2]), 3))
