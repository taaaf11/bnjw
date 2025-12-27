#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <initializer_list>
#include "show-pset2.h"
using namespace std;


static void sortStack(int topValue, stack<int> &s) {
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

void showP11() {
    stack<int> s;

    s.push(1);
    s.push(4);
    s.push(3);
    s.push(5);
    cout << "Pushed: 1, 4, 3, 5" << endl;

    int v = s.top();
    s.pop();
    sortStack(v, s);

    cout << "Popped: ";
    while (!s.empty()) {
        cout << s.top() << ", ";
        s.pop();
    }
    cout << endl;
}
