

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        import heapq
        charMap = {}
        for c in s:
            if c not in charMap:
                charMap[c] = 0
            charMap[c] += 1
        rs, heap = "", []
        for char, freq in charMap.items():
            heapq.heappush(heap, (-freq, char))
        while heap:
            freq, char = heapq.heappop(heap)
            rs += char * (-freq)
        return rs
        
if __name__ == "__main__":
    s = Solution()
    print (s.frequencySort("tree"))
