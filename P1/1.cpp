#include <iostream>
using namespace std;

static void rotateOnce (int arr[], int n, int idx, int last)
{
	if (idx == 0)
	{
		arr[0] = last;
		return;
	}
	
	arr[idx] = arr[idx - 1];
	rotateOnce(arr, n, idx - 1, last);
}

static void rotateRight (int arr[], int n, int k)
{
	if (k == 0) return;
	
	int last = arr[n - 1];
	
	rotateOnce(arr, n, n - 1, last);
	rotateRight(arr, n, k - 1);
}


void showP1() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    rotateRight(arr, 5, 2);

    cout << "After rotating right by 2: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}