#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys

class Solution:
    # @param {integer[]} digits
    # @return {integer[]}
    def plusOne(self, digits):
    	if len(digits) == 0: return [1]
    	carry = 1
    	for i in range(len(digits)-1, -1, -1):
    		digits[i] += carry
    		if digits[i] == 10:
    			carry, digits[i] = 1, 0
    		else:
    			carry = 0
    			break
    	if carry == 1:
    		rs = [1]
    		rs.extend(digits)
    		return rs
    	else:
    		return digits


def main(argv):
    s = Solution()
    print s.plusOne([])
    print s.plusOne([1])
    print s.plusOne([9])
    print s.plusOne([9,9])
    print s.plusOne([1,9,9])
    print s.plusOne([1,2,3])

if __name__ == '__main__':
    sys.exit(main(sys.argv))
