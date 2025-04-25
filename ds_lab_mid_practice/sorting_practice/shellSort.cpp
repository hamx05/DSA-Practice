#include <iostream>
using namespace std;

void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

/* Time Complexity:
Best case: O(nlogn)
Average case: O(n(logn)^2)
Worst case: O(N^2)
*/

void shellSort(int arr[], int n) {

    for (int gap=n/2; gap>=1; gap /= 2) {
        for (int j=gap; j<n; j++) {
            for (int i=j-gap; i>=0; i=i-gap) {
                if (arr[i+gap] < arr[i]) {
                    int temp = arr[i+gap];
                    arr[i+gap] = arr[i];
                    arr[i] = temp;
                } else break;
            }
        }    
    }

}

int main () {

    int arr[] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    print(arr, n);
    
    shellSort(arr, n);
    
    cout<<"Sorted Array: " << endl;
    print(arr, n);
    return 0;
       
   }