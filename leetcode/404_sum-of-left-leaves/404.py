# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def _sumOfLeftLeaves(self, root, isLeft):
        if None == root: return 0
        if root.left == None and root.right == None: 
            return root.val if isLeft else 0
        left, right = 0, 0
        if root.left != None:
            left = self._sumOfLeftLeaves(root.left, True)
        if root.right != None:
            right = self._sumOfLeftLeaves(root.right, False)
        return left + right
    
    
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self._sumOfLeftLeaves(root, False)
