#!/usr/bin/env python
# -*- coding: utf-8 -*-


# Example:
# Input: s = "abcdefg", k = 2
# Output: "bacdfeg"
class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        if k <= 0: return s
        rs, N, rflag = [], len(s)/k, True
        for i in range(N):
            if rflag:
                rs.extend(list(reversed(s[i*k : (i+1)*k])))
            else:
                rs.extend(list(s[i*k : (i+1)*k]))
            rflag = not rflag
        if rflag:
            rs.extend(list(reversed(s[N*k:])))
        else:
            rs.extend(list(s[N*k:]))
        return ''.join(rs)


if __name__ == "__main__":
    s = Solution()
    print (s.reverseStr("abcdefg", 2))
    print (s.reverseStr("abcdefg", 4))

