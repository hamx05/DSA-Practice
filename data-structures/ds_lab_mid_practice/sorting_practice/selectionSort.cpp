#include <iostream>
using namespace std;

void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

/* Time Complexity:
Best case: O(N^2)
Average case: O(N^2)
Worst case: O(N^2)
*/
void selectionSort(int arr[], int n) {

    for (int i=0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

}

int main () {

    int arr[] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    print(arr, n);
    
    selectionSort(arr, n);
 
    cout<<"\nSorted Array: " << endl;
    print(arr, n);

    return 0;
}