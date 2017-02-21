import itertools

class Solution(object):
    def pick_recursive(self, data, n, prefix):
        rs, size = [], len(data)
        if n <= 0 or n > size: return [prefix + []]
        if n == size: return [prefix + data]
        rs.extend(self.pick_recursive(data[1:], n, prefix))
        rs.extend(self.pick_recursive(data[1:], n-1, prefix+data[:1]))
        return rs
        
        
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        hours, mins = [1, 2, 4, 8], [1, 2, 4, 8, 16, 32]
        NHours, NMins, rs = len(hours), len(mins), []
        if num < 0 or num > (NHours+NMins-2): return []
        if num == 0: return ["0:00"]
        for nHours in range(NHours):
            nMins = num - nHours
            if nMins < 0: break
            if nMins >= NMins: continue
            selectedHours = [sum(item) for item in self.pick_recursive(hours, nHours, []) if sum(item) < 12]
            selectedMins = [sum(item) for item in self.pick_recursive(mins, nMins, []) if sum(item) < 60]
            if nHours == 0:
                rs += ["%d:%02d" % item for item in zip([0] * len(selectedMins), selectedMins)]
                continue
            if nMins == 0:
                rs += ["%d:%02d" % item for item in zip(selectedHours, [0] * len(selectedHours))]
                continue
            rs += ["%d:%02d" % item for item in itertools.product(selectedHours, selectedMins)]
        return rs


def test1():
    s = Solution()
    print (s.pick_recursive([1,2,3,4], 0, []))
    print (s.pick_recursive([1,2,3,4], 1, []))
    print (s.pick_recursive([1,2,3,4], 2, []))
    print (s.pick_recursive([1,2,3,4], 3, []))
    print (s.pick_recursive([1,2,3,4], 4, []))
    print ("=" * 120)
    print (s.pick_recursive([1,2,3,4], 2, []))
    print ([sum(item) for item in s.pick_recursive([1,2,3,4], 2, [])])
    print ([sum(item) for item in s.pick_recursive([1,2,3,4], 2, []) if sum(item) < 5])
    print ("*" * 120)


def test2():
    s = Solution()
    hours, mins = [1, 2, 4, 8], [1, 2, 4, 8, 16, 32]
    selectedHours = [sum(item) for item in s.pick_recursive(hours, 3, []) if sum(item) < 12]
    selectedMins = [sum(item) for item in s.pick_recursive(mins, 5, []) if sum(item) < 60]
    print (["%d:%02d" % item for item in itertools.product(selectedHours, selectedMins)])

        
if __name__ == '__main__':
    # test1()
    # test2()
    # print ("#" * 80)
    s = Solution()
    print (s.readBinaryWatch(1))
    print (s.readBinaryWatch(2))
    print (s.readBinaryWatch(8))