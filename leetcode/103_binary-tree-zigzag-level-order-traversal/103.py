# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root: return []
        queue, rs, curLevel, l2r = [root, None], [], [], True
        while queue:
            node = queue.pop(0)
            if node is None:
                if not curLevel: return rs
                if l2r: 
                    rs.append(curLevel)
                else:
                    rs.append(list(reversed(curLevel)))
                l2r = not l2r
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
        3
       / \
      9  20
        /  \
       15   7
    '''
    s = Solution()
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print (s.zigzagLevelOrder(root))


if __name__ == '__main__':
    test_01()
    