# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# Input: The root of a Binary Search Tree like this:
#               5
#             /   \
#            2     13
# Output: The root of a Greater Tree like this:
#              18
#             /   \
#           20     13
class Solution(object):

    def __init__(self):
        self.accum = 0

    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None: return None
        def right_preorder(node):
            if node.right is not None:
                right_preorder(node.right)
            self.accum += node.val
            node.val = self.accum
            if node.left is not None:
                right_preorder(node.left)
        right_preorder(root)
        return root


def left_preorder_print(root):
    if root is None: return
    left_preorder_print(root.left)
    print root.val,
    left_preorder_print(root.right)


if __name__ == '__main__':
    s = Solution()
    root = TreeNode(5)
    root.right = TreeNode(13)
    root.left = TreeNode(2)

    left_preorder_print(root)
    print
    left_preorder_print(s.convertBST(root))

    
