#include <iostream>
using namespace std;

// -------- Pivot = low -------- 
int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int start = low;
    int end = high;

    while (start < end) {
        while (arr[start] <= pivot && start <= high) {
            start++;
        }
        while (arr[end] > pivot && end >= 0) {
            end--;
        }

        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[low], arr[end]);
    return end;
}

// -------- Pivot = Mid -------- 
int partition (int arr[], int low, int high) {
    int mid = low + ((high-low)/2);
    int pivot = arr[mid];
    int start = low;
    int end = high;

    while (start <= end) {
        while (arr[start] < pivot && start <= high) {
            start++;
        }

        while (arr[end] > pivot && end >= low) {
            end--;
        }

        if (start <= end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    return start - 1;
}

// -------- Pivot = High -------- 
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int start = low;
    int end = high - 1;

    while (start <= end) {
        while (arr[start] <= pivot && start <= end) {
            start++;
        }
        while (arr[end] > pivot && end >= low) {
            end--;
        }

        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[high], arr[start]);
    return start;
}


void quickSort (int arr[], int low, int high) {
    if (low >= high) return;

    int pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);
}


void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main () {

    int arr[10] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    print(arr, n);
    
    quickSort(arr, 0, n-1);
 
    cout<<"\nSorted Array: " << endl;
    print(arr, n);

    return 0;
}