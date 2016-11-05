#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        t = x;
        size++;
    }

    // Removes the element on top of the stack.
    void pop() {
        for (int i=0; i<size-1; i++) {
            q.push(q.front());
            t = q.front();
            q.pop();
        }
        q.pop();
        size--;
    }

    // Get the top element.
    int top() {
        return t;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
    int t;
    int size;
};
