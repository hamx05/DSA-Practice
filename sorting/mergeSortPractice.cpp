#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int temp[high-low+1];
    int currIndex = 0;

    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp[currIndex] = arr[left];
            left++;
        }
        else {
            temp[currIndex] = arr[right];
            right++;
        }
        currIndex++;
    }

    while (left <= mid) {
        temp[currIndex] = arr[left];
        left++;
        currIndex++;
    }

    while (right <= high) {
        temp[currIndex] = arr[right];
        right++;
        currIndex++;
    }

    for (int i=0; i<currIndex; i++) {
        arr[i + low] = temp[i];
    }
}

void mergeSort (int arr[], int low, int high) {
    if (low >= high) return;

    int mid = (low + (high-low) / 2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}


void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}


int main () {

    int arr[] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);


    cout<<"Original Array: " << endl;
    print(arr, n);
    
    mergeSort(arr, 0, n-1);
 
    cout<<"\nSorted Array: " << endl;
    print(arr, n);

    return 0;
} 