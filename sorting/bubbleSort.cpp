// Bubble Sort Algorithm
// Repeatedly compares adjacent elements and swaps them if they are in the wrong order.
// Time Complexity: O(n^2) in worst/average case, O(n) best case (already sorted)
// Space Complexity: O(1) - in-place sorting

#include <iostream>
using namespace std;

// for ascending order
void bubbleSort (int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        bool flagSwap = false;
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flagSwap = true;
            }
        }
        if (!flagSwap) {
            break;
        }
    }
    return;
}

int main () {
    
    int arr[10] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"Original Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    bubbleSort(arr, n);

    cout<<"\n\nSorted Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    return 0;
}