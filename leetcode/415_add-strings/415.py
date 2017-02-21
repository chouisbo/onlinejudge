class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        rs, m, n, carray = "", len(num1) - 1, len(num2) - 1, 0
        while m >= 0 and n >= 0:
            s = int(num1[m]) + int(num2[n]) + carray
            carray = 1 if s > 9 else 0
            s = s if s < 10 else (s - 10)
            rs = str(s) + rs
            m, n = m-1, n-1
        if m >= 0:
            prefix = self.addStrings(num1[:m+1], "1") if carray > 0 else num1[:m+1]
            return prefix + rs
        if n >= 0:
            prefix = self.addStrings(num2[:n+1], "1") if carray > 0 else num2[:n+1]
            return prefix + rs
        return rs if carray < 1 else ("1" + rs)


if __name__ == '__main__':
    s = Solution()
    print (s.addStrings("9", "99"))
    print (s.addStrings("0", "299"))
    print (s.addStrings("7", "12"))
    print (s.addStrings("102", "299"))