#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    public:
        int arr[MAX];
        int front;
        int rear;
        int size;

        Queue () : front(0), rear(-1), size(0) {}

        bool isFull() {
            return (size == MAX);
        }
        
        bool isEmpty() {
            return (size == 0);
        }

        void enqueue (int x) {
            if (isFull()) {
                cout<<"Overflow condition. " << x << " cannot be added." << endl;
                return;
            }
            else {
                rear = (rear + 1) % MAX;
                size++;
                arr[rear] = x;
                cout<< "Enqueued: " << arr[rear] << endl;
            }
        }

        void dequeue () {
            if (isEmpty()) {
                cout<<"Underflow condition. The Queue is already empty." << endl;
                return;
            }
            else {
                cout<< "Dequeued: " << arr[front] << endl;
                arr[front] = 0;
                size--;
                front = (front + 1) % MAX;
            }
        }

        void print() {
             if (isEmpty()) {
                cout<<"The Queue is already empty. Nothing to print." << endl;
                return;
            }
            cout<<"Elements in the Queue are: (Queue Size = " << size << ")" << endl;
            for (int i=0; i<size; i++) {
                cout<<arr[(front + i) % MAX] << " ";
            }
            cout<<endl;
        }


};

int main () {

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(7);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(1);
    q.print();

    return 0;
}