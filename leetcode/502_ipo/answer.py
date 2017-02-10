import heapq

class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        current, future = [], sorted(zip(Capital, Profits), reverse=True)
        for _ in range(k):
            while future and future[-1][0] <= W:
                heapq.heappush(current, -future.pop()[1])
            if current:
                W -= heapq.heappop(current)
        return W


if __name__ == "__main__":
    s = Solution()
    print (s.findMaximizedCapital(2, 0, [1,2,3], [0,1,1]))

