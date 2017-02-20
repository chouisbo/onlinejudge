class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        rs = [""] * n
        for i in range(1, int(n/3) + 1):
            rs[3*i - 1] += "Fizz"
        for i in range(1, int(n/5) + 1):
            rs[5*i - 1] += "Buzz"
        for i in range(1, n+1):
            if rs[i-1] == "": rs[i-1] = str(i)
        return rs


if __name__ == "__main__":
    s = Solution()
    print (s.fizzBuzz(0))
    print (s.fizzBuzz(1))
    print (s.fizzBuzz(14))
    print (s.fizzBuzz(15))
    print (s.fizzBuzz(16))
    
