#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None: return 0
        self.maxdepth(root)
        ld = root.left.val if root.left is not None else 0
        rd = root.right.val if root.right is not None else 0
        return max(self.diameterOfBinaryTree(root.left),
                   self.diameterOfBinaryTree(root.right),
                   ld + rd)
        

    def maxdepth(self, node):
        if node is None: return 0
        ld = self.maxdepth(node.left)
        rd = self.maxdepth(node.right)
        node.val = max(ld, rd) + 1
        return node.val
    

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    
    s = Solution()
    print (s.maxdepth(root))
    print (s.diameterOfBinaryTree(root))

