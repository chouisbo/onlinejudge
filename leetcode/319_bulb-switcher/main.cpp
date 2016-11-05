
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 可以看出，非平方数的因数总是成对出现的，只有平方数的因数才是奇数，因为平方数除平方根外，
 * 其他的因数都是成对出现的！对于当前的开关灯泡问题，可知到最后处在平方数位置的灯泡一定是开启的，
 * 其他位置的灯泡一定是关闭的。而要计算一个数之下有多少小于或等于它的平方数，使用一个开平方用的函数就可以了。
 * 注意：此处为因数而非质因数
 * 如：
 * 6 = 1*6, 6 = 2*3 
 * 4 = 1*4, 4 = 2*2
 * 8 = 1*8, 8 = 2*4, 8 = 2*2*2
 */

class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};

int main(void) {

    Solution s;
    cout << "i=" << 999999 << ", cnt=" << s.bulbSwitch(999999) << endl;

    return 0;
}
