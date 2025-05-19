#include <iostream>
using namespace std;

class MaxHeap {
    public:
        int arr[10];
        int size;
        int capacity = 10;
        
        MaxHeap() : capacity(10), size(0) {}

        void heapifyDown (int i, int heapSize) {
            int largest = i;
            int leftChild = (2 * i) + 1;
            int rightChild = (2 * i) + 2;

            if (leftChild < heapSize && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }

            if (rightChild < heapSize && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapifyDown(largest, heapSize);
            }
        }

        void heapifyUp (int index) {
            while (index > 0) {
                int parent = (index-1) / 2;

                if (arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else {
                    return;
                }
            } 
        }

        void buildMaxHeap () {
            for (int i=(size-1)/2; i>=0; i--) {
                heapifyDown(i, size);
            }
        }

        void heapSort() {
            buildMaxHeap();

            int heapSize = size;
            for (int i=heapSize-1; i>0; i--) {
                swap(arr[0], arr[i]);
                heapSize--;
                heapifyDown(0, heapSize);
            }
        }

        void insert(int data) {
            if (size == capacity) {
                cout << "Heap overflow" << endl;
                return;
            }

            int index = size;
            size++;
            arr[index] = data;

            heapifyUp(index);            
        }

        int peek() {
            if (size <= 0) {
                cout << "Heap is empty." << endl;
                return -1;
            }
            return arr[0];
        }

        void deleteFromHeap(int target) {
            if (size <= 0) {
                cout << "Heap is empty." << endl;
                return;
            }

            arr[0] = arr[size-1];
            size--;

            heapifyDown(0, size);
        }

        void deleteByIndex(int index, int target) {
            if (size <= 0) {
                cout << "Heap is empty." << endl;
                return;
            }

            arr[index] = arr[size-1];
            size--;

            heapifyDown(index, size);
            heapifyUp(index);
        }

        void printArray () {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};


int main () {
    
    MaxHeap h1;
    h1.insert(5);
    h1.insert(3);
    h1.insert(10);
    h1.insert(14);
    h1.insert(11);
    h1.insert(15);
    h1.insert(23);
    h1.insert(17);
    h1.insert(73);
    h1.insert(27);

    cout << "Original Array: ";
    h1.printArray();

    h1.deleteFromHeap();

    // h1.heapSort();
    
    cout << "After Deletion: ";
    h1.printArray();

    h1.deleteByIndex(3);
    cout << "After Index Based Deletion: ";
    h1.printArray();

    h1.deleteByValue(10);
    cout << "After Value Based Deletion: ";
    h1.printArray();

    h1.update(15, 2);
    cout << "After Updation of 15 to 2: ";
    h1.printArray();


    return 0;
}