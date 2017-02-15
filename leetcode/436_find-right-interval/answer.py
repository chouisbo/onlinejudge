# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

import bisect

class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        n = len(intervals)
        if n <= 0: return []
        if 1 == n: return [-1]
        data = sorted(zip(range(len(intervals)), intervals), cmp=lambda a,b: a[1].start - b[1].start)
        rs, starts = [], [d[1].start for d in data]
        for interval in intervals:
            i = bisect.bisect_left(starts, interval.end)
            if i == n: rs.append(-1)
            else: rs.append(data[i][0])
        return rs
