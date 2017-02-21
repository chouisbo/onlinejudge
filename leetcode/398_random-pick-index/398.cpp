#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand(time(0));
    }

    int pick(int target) {
        int rs = -1, n = 0, index = 0;
        for (vector<int>::const_iterator it = nums.begin();
             it != nums.end(); ++it, index++) {
            if (*it == target) {
                n++;
                if (rand() % n == 0) {
                    rs = index;
                }
            }
        }
        return rs;
    }

private:
    vector<int> nums;
};


int main(void) {

    vector<int> nums {1,2,2,3,3,3};
    Solution s(nums);
    cout << s.pick(1) << endl;
    cout << s.pick(1) << endl;
    cout << s.pick(2) << endl;
    cout << s.pick(2) << endl;
    cout << s.pick(2) << endl;
    cout << s.pick(2) << endl;
    cout << s.pick(3) << endl;
    cout << s.pick(3) << endl;
    cout << s.pick(3) << endl;
    cout << s.pick(3) << endl;
    cout << s.pick(3) << endl;
    cout << s.pick(3) << endl;
    cout << s.pick(3) << endl;


    return 0;
}

