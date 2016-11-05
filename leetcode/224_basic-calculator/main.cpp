#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

#define STACK_ERR 0
#define STACK_POP 1
#define STACK_PUSH 2
#define STACK_CALC 3

class Solution {
public:
    int calculate(string s) {
        stack<char> opStack;
        stack<int> dataStack;
        opStack.push('#');
        s.append(1, '#');

        string buffer;
        for (size_t i = 0; i < s.length(); i++) {
            if (isDigit(s[i])) {
                buffer.append(1, s[i]);
                continue;
            }
            if (! buffer.empty()) {
                dataStack.push(stoi(buffer));
                buffer.clear();
            }
            if (isOp(s[i])) {
                int rc = calcOp(s[i], opStack.top());
                while (rc == STACK_CALC) {
                    int a = dataStack.top();
                    dataStack.pop();
                    int b = dataStack.top();
                    dataStack.pop();
                    if (opStack.top() == '+') {
                        dataStack.push(b+a);
                    } else if (opStack.top() == '-') {
                        dataStack.push(b-a);
                    } else if (opStack.top() == '*') {
                        dataStack.push(b*a);
                    } else if (opStack.top() == '/') {
                        if (0 == a) { assert(false); }
                        dataStack.push(b/a);
                    } else {
                        assert(false);
                    }
                    opStack.pop();
                    rc = calcOp(s[i], opStack.top());
                }
                if (STACK_ERR == rc) {
                    assert(false);
                } else if (STACK_PUSH == rc) {
                    opStack.push(s[i]);
                } else if (STACK_POP == rc) {
                    opStack.pop();
                } else {
                    assert(false);
                }
            }
        }

        assert(opStack.empty());
        
        return dataStack.top();
    }

    bool isDigit(char ch) {
        return ch>='0' && ch <='9';
    }

    bool isOp(char ch) {
        return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch == ')' || ch == '#';
    }

    // opA 表示当前读取到的操作符
    // opB 表示当前栈顶操作符
    int calcOp(char opA, char opB) {
        if ('#' == opB) {
            if ('#' == opA) {
                return STACK_POP;
            } else if (')' == opA) {
                return STACK_ERR;
            } else {
                return STACK_PUSH;
            }
        }
        else if ('(' == opB) {
            if ('#' == opA) {
                return STACK_ERR;
            } else if (')' == opA) {
                return STACK_POP;
            } else {
                return STACK_PUSH;
            }
        }
        else if ('+' == opB || '-' == opB) {
            if ( '(' == opA || '*' == opA || '/' == opA) {
                return STACK_PUSH;
            } else { // "#, +, -, )" 
                return STACK_CALC;
            }
        }
        else if ('*' == opB || '/' == opB) {
            if ('(' == opA) {
                return STACK_PUSH;
            } else { // "#, +, -, *, /, )"
                return STACK_CALC;
            }
        }
        else { 
            return STACK_ERR;
        }
    }

};

int main(void) {
    string exp1("2*(4+10/(3-1)-(6-5))");
    string exp2(" 2-1 + 2 ");
    string exp3("(1+(4+5+2)-3)+(6+8)");

    Solution s;
    cout << exp1 << " [16] = " << s.calculate(exp1) << endl;
    cout << exp2 << " [3]  = " << s.calculate(exp2) << endl;
    cout << exp3 << " [23] = " << s.calculate(exp3) << endl;

    return 0;
}
