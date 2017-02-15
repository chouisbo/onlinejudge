class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if 1 == num: return True
        low, high = 1, num
        while low <= high:
            mid = int((high-low)/2) + low
            if num == mid * mid: return True
            elif num > mid * mid:
                low = mid + 1
            else:
                high = mid - 1
        return False
