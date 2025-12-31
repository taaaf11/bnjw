#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
#include <optional> // for optional
#include <utility> // for pair
#include "show-pset1.h"
using namespace std;


struct HeapDataStructure {
    bool max; // if true, maxHeap, otherwise minheap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    HeapDataStructure(bool v) {
        max = v;
    }

    void push(int value) {
        if (max) {
            maxHeap.push(value);
        }
        else {
            minHeap.push(value);
        }
    }

    int top() {
        if (max) {
            return maxHeap.top();
        }
        else {
            return minHeap.top();
        }
    }

    void pop() {
        if (max) {
            maxHeap.pop();
        }
        else {
            minHeap.pop();
        }
    }

    bool empty() {
        if (max) {
            return maxHeap.empty();
        }
        else {
            return minHeap.empty();
        }
    }
};  


// first indicates sort order of negatives
// second indicates sort order of positives
pair<bool, bool> detectSortOrder(vector<int>& elems) {
    stack<int> negatives, positives;
    optional<bool> negativesDescending, positivesDescending;

    for (int e: elems) {
        if (negativesDescending.has_value()) {
            positivesDescending = negativesDescending.value();
            break;
        }
        
        if (positivesDescending.has_value()) {
            negativesDescending = positivesDescending.value();
            break;
        }

        if (e > 0) {
            if (!positives.empty()) {
                if (!positivesDescending.has_value()) {
                    positivesDescending = e < positives.top();
                }
            }
            positives.push(e);
        }

        else {
            if (!negatives.empty()) {
                if (!negativesDescending.has_value()) {
                    negativesDescending = e < negatives.top();
                }
            }

            negatives.push(e);
        }
    }

    return {negativesDescending.value_or(false), positivesDescending.value_or(false)};
}


vector<int> sortt(vector<int>& elems) {
    pair<bool, bool> sortOrder = detectSortOrder(elems);

    HeapDataStructure  *negativesHeap, *positivesHeap;
    negativesHeap = new HeapDataStructure(sortOrder.first);
    positivesHeap = new HeapDataStructure(sortOrder.second);

    for (int e: elems) {
        if (e < 0) {
            negativesHeap->push(e);
        }
        else {
            positivesHeap->push(e);
        }
    }

    vector<int> rv;

    while (! (negativesHeap->empty()) ) {
        rv.push_back(negativesHeap->top());
        negativesHeap->pop();
    }

    while (! (positivesHeap->empty()) ) {
        rv.push_back(positivesHeap->top());
        positivesHeap->pop();
    }

    delete positivesHeap;
    delete negativesHeap;
    
    return rv;
}


int main() {
    vector<int> originalArray = {7, 1, -1, 9, -5, 15};
    vector< int> sortedd = sortt(originalArray);

    
    // vector<Element> elements;
    for (int e: sortedd) {
        cout << e << ", ";
    }
}