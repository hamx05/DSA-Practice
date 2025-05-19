// Shell Sort Algorithm
// A generalization of Insertion Sort that allows comparing elements far apart using a gap sequence.
// Time Complexity: Depends on gap, typically O(n log n) to O(n^2)
// Space Complexity: O(1) - in-place

#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for (int gap=n/2; gap>=1; gap /= 2) {
        for (int j=gap; j<n; j++) {
            for (int i=j-gap; i>=0; i -= gap) {
                if (arr[i+gap] < arr[i]) {
                    swap(arr[i], arr[i+gap]);
                } else {
                    break;
                }
            }
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

    shellSort(arr, n);

    cout<<"\n\nSorted Array: " << endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }

    return 0;
}