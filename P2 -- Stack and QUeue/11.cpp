#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <initializer_list>
using namespace std;


struct MyStack {
    queue<int> q1;

    void push(int v) {
        q1.push(v);
    }

    int pop() {
        queue<int> q2;

        int toEnqueue;

        while (!q1.empty()) {
            toEnqueue = q1.front();
            q1.pop();
            
            if (q1.empty()) {
                break;
            }

            q2.push(toEnqueue);
        }

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
        return toEnqueue;
    }


    bool empty() {
        return q1.empty();
    }
};


void sortStack(int topValue, stack<int> &s) {
    if (s.empty()) {
        s.push(topValue);
        return;
    }

    int v = s.top();
    s.pop();
    sortStack(v, s);

    if (s.empty()) {
        s.push(v);
    }
    else {
        stack<int> auxStack;

        while (!s.empty() && s.top() < topValue) {
            auxStack.push(s.top());
            s.pop();
        }

        s.push(topValue);

        while (!auxStack.empty()) {
            s.push(auxStack.top());
            auxStack.pop();
        }
    }
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(4);
    s.push(3);
    s.push(5);

    int v = s.top();
    s.pop();
    sortStack(v, s);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
