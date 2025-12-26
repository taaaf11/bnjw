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

int main() {
    MyStack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty()) {
        cout << s.pop() << endl;
    }

    return 0;
}
