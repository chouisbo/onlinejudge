class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if 0 == num: return "0"
        sig, rs = "", ""
        if num < 0: 
            sig = "-"
            num = -num
        while num != 0:
            rs = str(num % 7) + rs
            num /= 7
        return sig + rs
        
if __name__ == "__main__":
    s = Solution()
    print (s.convertToBase7(100))
    print (s.convertToBase7(-7))
