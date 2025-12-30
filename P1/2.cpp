#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <optional>
using namespace std;


// false indicates ascending
// true indicates descending
bool getSortOrder(vector<int>& arr) {
    stack<int> negatives, positives;
    optional<bool> negativesDescending, positivesDescending;

    for (int e: arr) {
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

    return negativesDescending.value_or(false) || positivesDescending.value_or(false);
}


static int putNegativesInPlace(vector<int>& arr) {
    int negativeIndex = 0;
    int swapsRequired = 0;
    bool sortOrder = getSortOrder(arr);
    
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
        if (!sortOrder) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                swapsRequired++;
            }
        }
        else {
            if (arr[j - 1] < arr[j]) {
                swap(arr[j - 1], arr[j]);
                swapsRequired++;
            }
        }
        
        j--;
    }
    return swapsRequired;
}

void showP2() {
    // vector<int> arr = {1, 7, -5, 9, -12, 15};
    vector<int> arr = {15,-12,  9, -5, 7, 1};

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