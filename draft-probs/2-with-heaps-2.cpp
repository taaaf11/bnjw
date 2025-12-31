#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include <optional>
#include "show-pset1.h"
// #include <minhea
using namespace std;


struct Element {
    int absValue;
    bool sign; // if sign is true, the number is negative.

    Element(int n) {
        absValue = abs(n);
        sign = n < 0;
    }

    operator int() {
        int i = absValue;
        if (sign) {
            i = -i;
        }
        return i;
    }
};


struct MaxStack {
    stack<int> s;

    void push(int value) {
        stack<int> auxStack;

        while (!s.empty() && s.top() > value) {
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

struct MinStack {
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



vector<int> sortt(vector<int> elems) {
    // MinStack negatives;
    // MinStack positives;
    stack<int> positives, negatives;
    optional<bool> positivesDescending, negativesDescending;

    for (int e: elems) {
        if (positivesDescending.has_value() && negativesDescending.has_value()) {
            break;
        }

        if (e > 0) {
            if (!positives.empty()) {
                if (e < positives.top()) {
                    //positives have descending order.

                    // We only modify the boolean if value was not already there.
                    if (!positivesDescending.has_value())
                        positivesDescending = true; 
                }
            }
            positives.push(e);
        }
        else {
            if (!negatives.empty()) {
                if (e < negatives.top()) {
                    //negatives have descending order.

                    // We only modify the boolean if value was not already there.
                    if (!negativesDescending.has_value())
                        negativesDescending = true; 
                }
            }
            negatives.push(e);
        }
    }


    // above code was for detecting sorting order.

    // now the real sorting will start.
    optional<priority_queue<int, vector<int>, greater<int>>> positivesMinHeap, negativesMinHeap;
    optional<priority_queue<int>> positivesMaxHeap, negativesMaxHeap;

    if (positivesDescending) {
        positivesMaxHeap = priority_queue<int>();
    }
    else {
        positivesMinHeap = priority_queue<int, vector<int>, greater<int>>();
    }

    if (negativesDescending) {
        negativesMaxHeap = priority_queue<int>();
    }
    else {
        negativesMinHeap = priority_queue<int, vector<int>, greater<int>>();
    }

    for (int e: elems) {
        if (e < 0) {
            if (negativesDescending) {
                negativesMaxHeap.value().push(e);
            }
            else {
                negativesMinHeap.value().push(e);
            }
        }
        else {
            if (positivesDescending) {
                positivesMaxHeap.value().push(e);
            }
            else {
                positivesMinHeap.value().push(e);
            }
        }
    }

    vector<int> rv;

    if (negativesDescending) {
        while (!negativesMaxHeap.value().empty()) {
            int value = negativesMaxHeap.value().top();
            cout << "incoming " << value << "from negative max heap" << endl;
            rv.push_back(negativesMaxHeap.value().top());
            negativesMaxHeap.value().pop();
        }
    }
    else {
        while (!negativesMinHeap.value().empty()) {
            int value = negativesMinHeap.value().top();
            cout << "incoming " << value << "from negative min heap" << endl;
            rv.push_back(negativesMinHeap.value().top());
            negativesMinHeap.value().pop();
        }
    }

    if (positivesDescending) {
        while (!positivesMaxHeap.value().empty()) {
            rv.push_back(positivesMaxHeap.value().top());
            positivesMaxHeap.value().pop();
        }
    }
    else {
        while (!positivesMinHeap.value().empty()) {
            rv.push_back(positivesMinHeap.value().top());
            positivesMinHeap.value().pop();
        }
    }

    return rv;
}


void showP2() {
    vector<int> originalArray = {7, 1, -12, 9, -5, 15};
    vector< int> sortedd = sortt(originalArray);

    
    // vector<Element> elements;
    for (int e: sortedd) {
        cout << e << ", ";
    }
}