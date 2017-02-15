import bisect

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = len(numbers)
        for i in range(n):
            low, high = i+1, n-1
            while low <= high:
                mid = int((high-low)/2) + low
                if numbers[mid] == (target-numbers[i]):
                    return [i+1, mid+1]
                elif numbers[mid] < (target-numbers[i]):
                    low = mid + 1
                else:
                    high = mid - 1
        return [-1, -1]
        
