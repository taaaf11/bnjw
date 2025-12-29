#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


static int putNegativesInPlace(vector<int>& arr) {
    int negativeIndex = 0;
    int swapsRequired = 0;
    
    int i = 0;

    // j will store the for loop INDEX from which
    // the negative was swapped
    int j = 0;
    for (i; i < arr.size(); i++) {
        if (arr[i] < 0) {
            swap(arr[i], arr[negativeIndex]);
            j = i;
            swapsRequired++;
            negativeIndex++;
        }
    }

    // int k = j;
    while (j > negativeIndex) {
        if (arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            swapsRequired++;
        }
        j--;
    }
    return swapsRequired;
}

void showP2() {
    vector<int> arr = {1, 7, -5, 9, -12, 15};

    cout << "Original array: ";
    for (int e: arr) {
        
        cout << e << ", ";
    }

    int swapsRequired = putNegativesInPlace(arr);

    cout << endl << "Sorted array:  ";
    for (int e: arr) {
        cout << e << ", ";
    }

    cout << endl  << "Swaps required: " << swapsRequired << endl;
}