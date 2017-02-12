class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = 0, len(nums)
        if n < k or k <= 0: return None
        if n == k: return sorted(nums)[-1]
        import heapq
        heap = []
        for num in nums[0:k]:
            heapq.heappush(heap, num)
        for num in nums[k:]:
            if num > heap[0]: heapq.heapreplace(heap, num)
        return heap[0]
            

if __name__ == "__main__":
    s = Solution()
    print (s.findKthLargest([], 0))
    print (s.findKthLargest([1], 1))
    print (s.findKthLargest([1,3,2,4,5,8,7,6], 3))
