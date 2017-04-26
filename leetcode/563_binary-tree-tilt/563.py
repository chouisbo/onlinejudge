#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def __init__(self):
        self._tilt = 0

    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None: return 0
        self._tilt =  0
        self.postOrder(root)
        return self._tilt

    def postOrder(self, node):
        if node is None: return 0
        left = self.postOrder(node.left)
        right = self.postOrder(node.right)
        self._tilt += abs(left - right)
        node.val += left + right
        return node.val


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    
    s = Solution()
    print (s.findTilt(root))

