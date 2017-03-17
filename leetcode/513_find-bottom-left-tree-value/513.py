# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return []
        queue, curLevel = [root, None], []
        while queue:
            node = queue.pop(0)
            if node is None:
                if not queue: return curLevel[0]
                curLevel = []
                queue.append(None)
            else:
                curLevel.append(node.val)
                if node.left is not None: 
                    queue.append(node.left)
                if node.right is not None: 
                    queue.append(node.right)
        return curLevel[0]


def test_01():
    '''
    Input:

            1
           / \
          2   3
         /   / \
        4   5   6
           /
          7

    Output:
    7
    '''
    s = Solution()
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(6)
    root.right.left.left = TreeNode(7)
    print (s.findBottomLeftValue(root))


if __name__ == '__main__':
    test_01()
    