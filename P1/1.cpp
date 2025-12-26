#include <iostream>
#include <vector>
#include "show-pset1.h"
using namespace std;


static void rotate(vector<int>& arr, int index, int valueAtIndex, int rotateBy) {
    if (rotateBy == 0) {
        return;
    }

    if (rotateBy < 0) { 
        cout << "Invalid rotate-by." << endl;
        return;
    }
    
    if (index >= arr.size())
        return;

    rotate(arr, index + 1, arr[index + 1], rotateBy);

    int i = index + rotateBy;
    if (i >= arr.size()) {
        i = i % arr.size();
    }
    arr[i] = valueAtIndex;
}


void showP1() {
    vector<int> array = {1, 2, 3, 4, 5};

    rotate(array, 0, array[0], 2);
    
    for (int e: array) {
        cout << e << ", "; 
    }
}