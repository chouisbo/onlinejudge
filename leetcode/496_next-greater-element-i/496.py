import bisect

class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        m, n = len(findNums), len(nums)
        if m <= 0: return []
        elif n <= 0: return [-1] * m

        nextMap, stack = {}, [nums[0]]
        for i in range(1, n):
            while stack and nums[i] > stack[-1]:
                nextMap[stack.pop()] = nums[i]
            stack.append(nums[i])
        while stack:
            nextMap[stack.pop()] = -1
        return [nextMap[num] for num in findNums]


if __name__ == '__main__':
    s = Solution()
    print (s.nextGreaterElement([4,1,2], [1,3,4,2]))
    print (s.nextGreaterElement([2,4], [1,2,3,4]))
