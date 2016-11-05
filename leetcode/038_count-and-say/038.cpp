#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string text = "1";
        for (int i=1; i<n; i++) {
            string next = genNext(text);
            text.swap(next);
        }
        return text;
    }

    static string genNext(const string &text) {
        ostringstream ostr;

        string::const_iterator it = text.begin();
        char ch;
        while (it != text.end()) {
            ch = *it;
            int cnt = 1;
            while (*(++it) == ch) cnt++;
            ostr << cnt << ch;
        }

        return ostr.str();
    }
};


int main(int argc, char const *argv[])
{
    // cout << Solution::genNext("1") << endl;
    // cout << Solution::genNext("11") << endl;
    // cout << Solution::genNext("21") << endl;
    // cout << Solution::genNext("1211") << endl;
    // cout << Solution::genNext("111221") << endl;
    // cout << Solution::genNext("312211") << endl;
    Solution s;
    for (int i=1; i<=5; i++) {
        cout << i << "th => " << s.countAndSay(i) << endl;
    }
    return 0;
}