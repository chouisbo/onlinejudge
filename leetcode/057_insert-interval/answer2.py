
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
        s, e = newInterval.start, newInterval.end
        left, right = [], []
        for i in intervals:
            if i.end < s:
                left.append(i)
            elif i.start > e:
                right.append(i)
            else:
                s = min(s, i.start)
                e = max(e, i.end)
        return left + [Interval(s, e)] + right


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
    
    
