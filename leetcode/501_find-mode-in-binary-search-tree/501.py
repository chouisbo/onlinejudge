import collections

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None: return []
        counter = collections.Counter()
        def traverse(root):
            if not root: return
            counter[root.val] += 1
            traverse(root.left)
            traverse(root.right)
        traverse(root)
        maxn = max(counter.values())
        return [e for e, v in counter.iteritems() if v == maxn]


if __name__ == '__main__':
    s = Solution()
    print (s.findMode(None))
    print (s.findMode(TreeNode(2147483647)))