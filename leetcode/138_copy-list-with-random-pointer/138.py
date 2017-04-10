# Definition for singly-linked list with a random pointer.
class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None


def list2RandomList(list):
    if len(list) <= 0: return None
    head = RandomListNode(list[0])
    p = head
    for label in list[1:]:
        q = RandomListNode(label)
        p.next = q
        p = q
    return head


def outputRandomList(head):
    p = head
    while p is not None:
        print p.label,
        p = p.next
    print


class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if head is None: return None
        p = head
        while p is not None:
            q = RandomListNode(p.label)
            q.next = p.next
            p.next = q
            p = q.next
        p = head
        while p is not None:
            if p.random is not None:
                p.next.random = p.random.next
            p = p.next.next
        newHead = head.next
        p = head
        while p.next is not None:
            q = p.next
            p.next = p.next.next
            p = q
        return newHead


if __name__ == '__main__':
    s = Solution()
    outputRandomList(s.copyRandomList(list2RandomList([1,2,3,4,5])))
