#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size -1;

    while (low<=high && target>=arr[low] && target<=arr[high]) {
        int mid = (low+high) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (target < arr[mid]) { // ignore right side
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main () {

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    int target = 5;
    int index = binarySearch(arr, n, target);

    cout<<"Original Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    if (index != -1) {
        cout<<"\nTarget '"<< target << "' found at position: " << index+1 << endl;
    } else {
        cout<<"\nTarget '"<< target << "' not found in the array." <<endl;
    }

    return 0;
}