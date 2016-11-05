#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        if len(s) != len(t): return False
        foward_map   = {}
        backward_map = {}
        for i in range(len(s)):
            if not foward_map.has_key(s[i]):
                if backward_map.has_key(t[i]):
                    return False
                else:
                    foward_map[s[i]]   = t[i]
                    backward_map[t[i]] = s[i]
            else:
                if foward_map[s[i]] != t[i]:
                    return False
        return True

def main(argv):
    s = Solution()
    print s.isIsomorphic("", "")
    print s.isIsomorphic("a", "a")
    print s.isIsomorphic("ab", "aa")
    print s.isIsomorphic("egg", "add")
    print s.isIsomorphic("foo", "bar")
    print s.isIsomorphic("paper", "title")
    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv))