# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def largestValues(self, root):
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
                rs.append(max(curLevel))
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
    Input: 

              1
             / \
            3   2
           / \   \  
          5   3   9 

    Output: [1, 3, 9]
    '''
    s = Solution()
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(2)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(3)
    root.right.right = TreeNode(9)
    print (s.largestValues(root))


if __name__ == '__main__':
    test_01()
    