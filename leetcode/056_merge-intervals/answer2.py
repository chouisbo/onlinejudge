
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
        out = []
        for i in sorted(intervals, key=lambda i: i.start):
            if out and i.start <= out[-1].end:
                out[-1].end = max(out[-1].end, i.end)
            else:
                out.append(i)
        return out

if __name__ == "__main__":
    # intervals = [Interval(2, 6), Interval(1, 3), Interval(8, 10), Interval(15, 18)]
    intervals = [Interval(1,4), Interval(0,1)];
    s = Solution()
    for interval in s.merge(intervals): print (interval)
