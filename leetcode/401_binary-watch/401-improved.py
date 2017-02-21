import itertools

class Solution(object):
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
            selectedHours = [sum(item) for item in itertools.combinations(hours, nHours) if sum(item) < 12] if nHours > 0 else [0]
            selectedMins = [sum(item) for item in itertools.combinations(mins, nMins) if sum(item) < 60] if nMins > 0 else [0]
            rs += ["%d:%02d" % item for item in itertools.product(selectedHours, selectedMins)]
        return rs

        
if __name__ == '__main__':
    s = Solution()
    print (s.readBinaryWatch(1))
    print (s.readBinaryWatch(2))
    print (s.readBinaryWatch(8))