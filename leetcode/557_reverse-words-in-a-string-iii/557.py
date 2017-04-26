#!/usr/bin/env python
# -*- coding: utf-8 -*-


# Example:
# Input: "Let's take LeetCode contest"
# Output: "s'teL ekat edoCteeL tsetnoc"

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s is None: return None
        i, j, l, rs = 0, 0, len(s), []
        if l <= 1: return s
        while i < l:
            j = 0
            while i+j < l and not s[i+j].isspace(): j += 1
            rs.extend(list(reversed(s[i: i+j])))
            i += j
            if i < l: 
                rs.append(s[i])
                i += 1
        return ''.join(rs)


if __name__ == "__main__":
    s = Solution()
    print (s.reverseWords("Let's take LeetCode contest"))

