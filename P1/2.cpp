#include <iostream>
using namespace std;

void arrangePosNegs(int arr[], int n)
{
	int pos = -1; // first positive number di position
	
	for (int i = 0; i < n; i++)
	{
		if (pos == -1 && arr[i] >= 0)
		{
			pos = i; // 1
		}
		
		else if (pos != -1 && arr[i] < 0)
		{
			int temp = arr[i];
			
			for (int j = i; j > pos; j--)
			{
				arr[j] = arr[j - 1];
			}
			
			arr[pos] = temp;
			pos++;
		}
	}
}
void showP2()
{
	int arr[] = {1, 5, 7, 8, 15, 16, 26, -7, -22, -67};
    int n = sizeof(arr) / sizeof(arr[0]);

    arrangePosNegs(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}