# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        st1, st2, carry, head = self.list2Stack(l1), self.list2Stack(l2), 0, None
        while st1 or st2:
            n = (st1.pop() if st1 else 0) + (st2.pop() if st2 else 0) + carry
            carry = 1 if n >= 10 else 0
            p = ListNode(n if n < 10 else n - 10)
            p.next = head
            head = p
        if carry > 0:
            p = ListNode(1)
            p.next = head
            head = p
        return head
    
    
    def list2Stack(self, l):
        s = []
        while l is not None:
            s.append(l.val)
            l = l.next
        return s
        
