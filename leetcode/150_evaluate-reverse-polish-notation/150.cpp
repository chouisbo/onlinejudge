#include <stack>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opStack;
        for (auto &x : tokens) {
            if ("+" == x || "-" == x || "*" == x || "/" == x) {
                int op1 = opStack.top(); opStack.pop();
                int op2 = opStack.top(); opStack.pop();
                if ("+" == x) {
                    opStack.push(op2 + op1);
                } else if ("-" == x) {
                    opStack.push(op2 - op1);
                } else if ("*" == x) {
                    opStack.push(op2 * op1);
                } else {
                    opStack.push(op2 / op1);
                }
            } else {
                opStack.push(atoi(x.c_str()));
            }
        }
        return opStack.top();
    }
};

int main(void) {
    Solution s;
    vector<vector<string> > exps = {
        {"2", "1", "+", "3", "*"},
        {"4", "13", "5", "/", "+"},
        {"18"}
    };
    for (auto &exp : exps) {
        cout << s.evalRPN(exp) << endl;
    }
    return 0;
}

