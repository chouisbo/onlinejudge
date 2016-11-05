#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.length() == 1) { return s; }

        vector<int> alphaCountMap(26, 0);
        for (auto &ch : s) {
            alphaCountMap[(size_t) (ch-'a')]++;
        }

        stack<char> _st;
        vector<bool> inStack(26, false);
        for (size_t i=0; i<s.length(); i++) {
            while (! _st.empty() && _st.top() > s[i] 
                   && ! inStack[(size_t) (s[i] - 'a')]
                   && --alphaCountMap[(size_t) (_st.top() - 'a')] > 0) {
                inStack[(size_t) (_st.top() - 'a')] = false;
                _st.pop(); 
            }
            if (! inStack[(size_t) (s[i] - 'a')]) {
                _st.push(s[i]);
                inStack[(size_t) (s[i] - 'a')] = true;
            } else {
                --alphaCountMap[(size_t) (s[i] - 'a')];
            }
        }

        string rs("");
        while (! _st.empty()) {
            rs.append(1, _st.top());
            _st.pop();
        }

        reverse(rs.begin(), rs.end());

        return rs;
    }
};


int main(void) {

    Solution s;
    cout << s.removeDuplicateLetters("bcabc")    << ", expected => abc" << endl;
    cout << s.removeDuplicateLetters("cbacdcbc") << ", expected => acdb"<< endl;
    cout << s.removeDuplicateLetters("bbcaac")   << ", expected => bac" << endl;
    cout << s.removeDuplicateLetters("abacb")    << ", expected => abc" << endl;

	return 0;
}

