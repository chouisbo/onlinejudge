#!/usr/bin/env python
# -*- coding: utf-8 -*-


# Example 1:
#       Input: "PPALLP"
#       Output: True
# Example 2:
#       Input: "PPALLL"
#       Output: False

class Solution(object):

    def __init__(self):
        self.limit_cnt_A = 1
        self.limit_cnt_continuous_L = 2

    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cnt_A, cnt_continuous_L = 0, 0
        for ch in s:
            if ch == 'L':
                cnt_continuous_L += 1
                if cnt_continuous_L > self.limit_cnt_continuous_L: return False
            else:
                cnt_continuous_L = 0
            if ch == 'A':
                cnt_A += 1
                if cnt_A > self.limit_cnt_A: return False
        return True


if __name__ == "__main__":
    s = Solution()
    print (s.checkRecord("PPALLP"))
    print (s.checkRecord("PPALLL"))
