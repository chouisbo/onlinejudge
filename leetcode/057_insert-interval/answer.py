
# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __str__(self):
        return "(%d, %d)" % (self.start, self.end)

class Solution(object):

    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        if not newInterval: return intervals
        n = len(intervals)
        if n <= 0: return [newInterval]

        if newInterval.end < intervals[0].start: return [newInterval] + intervals
        if newInterval.start > intervals[-1].end: return intervals + [newInterval]

        if newInterval.start <= intervals[0].start:
            out = [newInterval]
            for i in range(n):
                if out[-1].end < intervals[i].start:
                    return out + intervals[i:]
                else:
                    out[-1].end = max(out[-1].end, intervals[i].end)
            return out
        if newInterval.start >= intervals[-1].start:
            if newInterval.start > intervals[-1].end:
                return intervals + [newInterval]
            else:
                out = [] + intervals
                out[-1].end = max(intervals[-1].end, newInterval.end)
                return out
        out, i = [], 0
        while i < n: 
            if newInterval.start > intervals[i].start: i += 1
            else: break
        out = intervals[:i]
        if out[-1].end < newInterval.start:
            out += [newInterval]
        else:
            out[-1].end = max(newInterval.end, out[-1].end)
        while i < n:
            if out[-1].end < intervals[i].start:
                return out + intervals[i:]
            else:
                out[-1].end = max(out[-1].end, intervals[i].end)
            i += 1
        return out


def test_1():
    intervals, newInterval = [Interval(1,3), Interval(6,9)], Interval(2,5)
    s = Solution()
    for i in s.insert(intervals, newInterval): print (i)


def test_2():
    intervals, newInterval = [Interval(1,2), Interval(3,5), Interval(6,7), 
        Interval(8,10), Interval(12,16)], Interval(4,9)
    s = Solution()
    for i in s.insert(intervals, newInterval): print (i)


def test_3():
    intervals, newInterval = [Interval(1,5)], Interval(2,3)
    s = Solution()
    for i in s.insert(intervals, newInterval): print (i)

if __name__ == "__main__":
    test_1()
    print ('-' * 120)
    test_2()
    print ('-' * 120)
    test_3()
    
    
