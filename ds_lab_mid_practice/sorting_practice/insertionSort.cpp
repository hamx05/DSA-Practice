#include <iostream>
using namespace std;

void print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

/* Time Complexity:
Best case: O(N)
Average case: O(N^2)
Worst case: O(N^2)
*/
void insertionSort(int arr[], int n) {

    for (int i=1; i<n; i++) {
        int temp = arr[i];
        int j = i - 1;
        
        while (j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

}

int main () {

    int arr[] = {5, 6, 2, 1, 3, 10, 12, 53, 7, 66};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Original Array: " << endl;
    print(arr, n);
    
    insertionSort(arr, n);
 
    cout<<"\nSorted Array: " << endl;
    print(arr, n);

    return 0;
}