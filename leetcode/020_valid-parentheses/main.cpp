#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> validStack;
        for (size_t i=0; i<s.length(); i++) {
            if (validStack.size() > s.length()-i) return false;
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                validStack.push(s[i]);
            } else {
                if (validStack.empty()) return false;
                else {
                    if ((validStack.top() == '(' && s[i] == ')') ||
                        (validStack.top() == '{' && s[i] == '}') ||
                        (validStack.top() == '[' && s[i] == ']')) {
                        validStack.pop();
                    } else return false;
                }
            }
        }
        return validStack.empty();
    }
};
