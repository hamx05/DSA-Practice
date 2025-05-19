#include <iostream>
using namespace std;

class MaxHeap {
    public:
        int arr[10];
        int size;
        int capacity = 10;
        
        MaxHeap() : capacity(10), size(0) {}

        void heapifyDown(int i, int heapSize) {
            int largest = i;
            int left = (2 * i) + 1;
            int right = (2 * i) + 2;


            if (left < heapSize && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < heapSize && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapifyDown(largest, heapSize);
            }
        }

        void heapifyUp (int index) {
            while (index > 0) {
                int parent = (index-1)/2;

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
            for (int i = (size/2); i>=0; i--) {
                heapifyDown(i, size);
            }
        }

        void heapSort() {
            buildMaxHeap();
            
            int heapSize = size;
            for (int i = heapSize - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                heapSize--;
                heapifyDown(0, heapSize);
            }
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "The heap is full. Cannot insert." << endl;
                return;
            }

            int index = size;
            size++;
            arr[index] = value;
        
            heapifyUp(index);
        }

        void deleteFromHeap () {
            if (size <= 0) {
                cout << "Heap is empty, cannot delete." << endl;
                return;
            }

            arr[0] = arr[size-1];
            size--;

            heapifyDown(0, size);
        }

        void deleteByIndex(int index) {
            if (index < 0 || index >= size) {
                cout << "Index out of bounds." << endl;
                return;
            }

            arr[index] = arr[size-1];
            size--;

            heapifyDown(index, size);
            heapifyUp(index);
        }
        
        void deleteByValue(int value) {
            int result = search(value);

            if (result != -1) {
                deleteByIndex(result);
                return;
            }
            cout << "Value not found in the heap." << endl;
        }

        int search (int target) {
            for (int i = 0; i < size; i++) {
                if (arr[i] == target) {
                    return i;
                }
            }
            return -1;
        }

        void update(int target, int newValue) {
            int result = search(target);

            if (result == -1) {
                cout << "Value not found in the heap." << endl;
                return;
            }

            arr[result] = newValue;
            heapifyDown(result, size);
            heapifyUp(result);
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