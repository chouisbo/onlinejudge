
# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __str__(self):
        return "(%d, %d)" % (self.start, self.end)

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        n = len(intervals)
        if n <= 1: return intervals
        sorted_intervals = sorted(intervals, key=lambda interval: interval.start)
        merged, prev = [], sorted_intervals[0]
        for i in range(1, n):
            if sorted_intervals[i].start <= prev.end:
                prev.end = max(sorted_intervals[i].end, prev.end)
            else:
                merged.append(prev)
                prev = sorted_intervals[i]
        merged.append(prev)
        return merged


if __name__ == "__main__":
    # intervals = [Interval(2, 6), Interval(1, 3), Interval(8, 10), Interval(15, 18)]
    intervals = [Interval(1,4), Interval(0,1)];
    s = Solution()
    for interval in s.merge(intervals): print (interval)
