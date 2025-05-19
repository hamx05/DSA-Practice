#include <iostream>
using namespace std;

int recursiveBinarySearch (int arr[], int target, int l, int h) {
    if (l>h) return -1;

    int mid = l + (h - l) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (target < arr[mid]) {
        return recursiveBinarySearch(arr, target, l, mid-1);
    }
    
    return recursiveBinarySearch(arr, target, mid+1, h);
}

int main () {

    int arr[5] = {10, 20, 30, 40, 50};
    int target = 50;

    int res = recursiveBinarySearch(arr, target, 0,  4);
    
    if (res != -1) {
        cout<<"Answer: " << res;
    } else {
        cout<<"Target not found." << endl;
    }

    return 0;
}