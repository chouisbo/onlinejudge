# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root: return []
        queue, rs, curLevel = [root, None], [], []
        while queue:
            node = queue.pop(0)
            if node is None:
                if not curLevel: return rs
                rs.append(curLevel[-1])
                curLevel = []
                queue.append(None)
            else:
                curLevel.append(node.val)
                if node.left is not None: 
                    queue.append(node.left)
                if node.right is not None: 
                    queue.append(node.right)
        return rs


def test_01():
    '''
          1            <---
         /   \
        2     3         <---
         \     \
          5     4       <---
    '''
    s = Solution()
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(4)
    print (s.rightSideView(root))


if __name__ == '__main__':
    test_01()
    