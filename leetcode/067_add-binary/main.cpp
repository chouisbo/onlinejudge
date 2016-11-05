#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() <= 0) return b;
        if (b.length() <= 0) return a;
        int sum, carry = 0;
        string rs = "";
        string::const_reverse_iterator ia = a.rbegin(), ib = b.rbegin();
        while (ia != a.rend() || ib != b.rend()) {
            sum = 0;
            if (ia != a.rend()) sum += (*ia++) - '0';
            if (ib != b.rend()) sum += (*ib++) - '0';
            sum += carry;
            if (sum >= 2) {
                carry = 1; sum -= 2;
            } else carry = 0;
            rs.push_back('0'+sum);
        }
        if (carry != 0) rs.push_back('1');
        reverse(rs.begin(), rs.end());
        return rs;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;
}

