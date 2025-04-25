// Insertion Sort Algorithm
// Builds the sorted array one element at a time by inserting each element into its correct position.
// Time Complexity: O(n^2) average/worst, O(n) best (already sorted)
// Space Complexity: O(1) - in-place

#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int temp = arr[i];
        int j = i - 1;
        // Move elements of the sorted part to make space for the current element
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insert the current element into its correct position
        arr[j + 1] = temp;
    }
}

int main() {

    int arr[10] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    InsertionSort(arr, n);

    cout<<"\n\nSorted Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
    
    return 0;
}