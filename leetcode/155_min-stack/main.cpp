#include <iostream>

#include <stack>
using namespace std;

class MinStack {

    public:
        void push(int x) {
            v_stack.push(x);
            if (m_stack.empty() || x < m_stack.top()) {
                m_stack.push(x);
            } else {
                m_stack.push(m_stack.top());
            }
        }

        void pop() {
            if (! v_stack.empty()) {
                v_stack.pop();
            }
            if (! m_stack.empty()) {
                m_stack.pop();
            }
        }

        int top() {
            return v_stack.top();
        }

        int getMin() {
            return m_stack.top();
        }
    private:
        stack<int> v_stack;
        stack<int> m_stack;
};

int main(int argc, const char *argv[]) {

    return 0;
}

