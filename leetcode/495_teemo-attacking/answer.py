class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        if len(timeSeries) <= 0: return 0
        total, start, end = 0, timeSeries[0], timeSeries[0] + duration
        for i in range(1, len(timeSeries)):
            if end < timeSeries[i]:
                total += end - start 
                start = timeSeries[i]
            end = timeSeries[i] + duration
        total += end - start
        return total


if __name__ == "__main__":
    s = Solution()
    print ("[1, 4], 2 =>", s.findPoisonedDuration([1, 4], 2))
    print ("[1, 2], 2 =>", s.findPoisonedDuration([1, 2], 2))
