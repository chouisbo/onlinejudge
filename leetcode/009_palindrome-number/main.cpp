

/*
题目要求只能用O(1)的空间，所以不能考虑把它转化为字符串然后reverse比较的方法。
在提示中也提到了，如果考虑reverse number的方法，可能造成溢出。
那么只能选择分离数字的方法，当然要用到大量除10和取余数的计算。真是一件悲惨的事情呢。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
            
        if (x < 10)
            return true;
            
        int digits = 0;
        int t = x;
        int d = 0;
        while(t != 0) t /= 10, ++d;
        
        int left = pow(10, d - 1);
        int right = 1;
        while( left >= right)
        {
            if (x / left % 10 != x / right % 10)
                return false;
            
            left /= 10;
            right *= 10;
        }
        return true;
    }
};
