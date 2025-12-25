#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct MinStack {
    // vector<int> v;
    stack<int> s;

    void push(int value) {
        stack<int> auxStack;

        while (!s.empty() && s.top() < value) {
            auxStack.push(s.top());
            s.pop();
        }

        s.push(value);
        
        while (!auxStack.empty()) {
            s.push(auxStack.top());
            auxStack.pop();
        }
    }

    int pop() {
        int v = top();
        s.pop();
        return v;
    }

    int top() {
        if (s.empty()) {
            cout << "Stack is empty." << endl;
            exit(1);
        }
        else {
            return s.top();
        }
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    MinStack ms;

    ms.push(2);
    ms.push(3);
    ms.push(4);

    while (!ms.empty()) {
        cout << ms.pop() << endl;
    }
    return 0;
}