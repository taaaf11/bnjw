#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<int>& arr, int index, int valueAtIndex, int rotateBy) {
    if (index >= arr.size())
        return;

    rotate(arr, index + 1, arr[index + 1], rotateBy);

    int i = index + rotateBy;
    if (i >= arr.size()) {
        i = i % arr.size();
    }
    arr[i] = valueAtIndex;
}


int main() {
    vector<int> array = {1, 2, 3, 4, 5};

    rotate(array, 0, array[0], 2);
    
    for (int e: array) {
        cout << e << ", "; 
    }
    return 0;
}