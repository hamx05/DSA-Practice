#include <iostream>
using namespace std;

int interpolationSearch (int arr[], int n, int target) {
    int low = 0;
    int high = n-1;

    while (low<=high && target>=arr[low] && target<=arr[high]) {
        int mid = low + (((high - low)*(target - arr[low])) / (arr[high] - arr[low]));

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) { // ignore elements at left side
            low = mid+1;
        }
        else { // ignore elements at right side
            high = mid-1;
        }
    }
    return -1;
}

int main () {
    
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    int target = 5;
    int index = interpolationSearch(arr, n, target);

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