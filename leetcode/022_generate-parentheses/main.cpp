/*
 * Given n pairs of parentheses, write a function to generate 
 * all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int nLeft = 1, nRight = 0;
        vector<string> rs;
        vector<char> vChoose {'('};
        while (true) {
            if (nRight > nLeft) {
                // error-matching, back-tracking
                while (! vChoose.empty()) {
                    if ('(' == vChoose.back()) break;
                    vChoose.pop_back();
                    nRight--;
                }
                if (vChoose.empty()) break;
                vChoose.back() = ')';
                nLeft--, nRight++;
                continue;
            }
            if (n == nLeft) {
                // get a result
                string aRs(vChoose.begin(), vChoose.end());
                aRs.append((size_t)(n-nRight), ')');
                rs.push_back(aRs);
                // back-tracking
                vChoose.back() = ')';
                nLeft--, nRight++;
                continue;
            }
            vChoose.push_back('(');
            nLeft++;
        }
        return rs;
    }
};

void printN(int n) {
    Solution s;
    for (auto &x : s.generateParenthesis(n)) {
        cout << x << ", ";
    }
    cout << endl;
}

int main(void) {

    for (int i=1; i<5; i++) printN(i);
    return 0;
}

