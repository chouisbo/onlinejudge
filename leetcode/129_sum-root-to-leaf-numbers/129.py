# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# For example,
#     1
#    / \
#   2   3
# The root-to-leaf path 1->2 represents the number 12.
# The root-to-leaf path 1->3 represents the number 13.
# Return the sum = 12 + 13 = 25.

#         4
#        / \
#       9   0
#        \
#         1
# return 491 + 40 = 531

class Solution(object):

    def __init__(self):
        self.sum = 0

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None: return 0
        def dfs(node, n):
            n = n * 10 + node.val
            if node.left is not None: dfs(node.left, n)
            if node.right is not None: dfs(node.right, n)
            if node.left is None and node.right is None:
                self.sum += n
        dfs(root, 0)
        return self.sum


if __name__ == '__main__':
    s = Solution()
    root = TreeNode(4)
    root.left = TreeNode(9)
    root.right = TreeNode(0)
    root.left.right = TreeNode(1)

    print s.sumNumbers(root)
    