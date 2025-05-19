// Selection Sort Algorithm
// Repeatedly selects the minimum element from the unsorted part and places it at the beginning.
// Time Complexity: O(n^2) in all cases
// Space Complexity: O(1) - in-place

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main () {

    int arr[10] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    selectionSort(arr, n);

    cout<<"\n\nSorted Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    return 0;
}