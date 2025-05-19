#include <iostream>
using namespace std;

void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

/* Time Complexity:
Best case: O(
Average case: O(
Worst case: O
*/

int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int start = low;
    int end = high;

    while (start < end) {
        while (arr[start] <= pivot && start<=high) {
            start++;
        }

        while (arr[end] > pivot && end>=low) {
            end--;
        }

        if (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;
    return end;

}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);

}

int main () {

    int arr[] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    print(arr, n);
    
    quickSort(arr, 0, n-1);
 
    cout<<"\nSorted Array: " << endl;
    print(arr, n);

    return 0;
}