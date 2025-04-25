#include <iostream>
#define MAX 100

using namespace std;

class Queue {
public:
    int front, rear;
    int arr[MAX]; // Array to hold the queue elements

    Queue() : front(-1), rear(-1) {} // Constructor to initialize front and rear

    bool enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full. Cannot enqueue " << x << endl;
            return false;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX; // Circular queue
            }
            arr[rear] = x;
            cout << x << " enqueued into the queue" << endl;
            return true;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty. Cannot dequeue." << endl;
            return 0;
        } else {
            int x = arr[front];
            if (front == rear) {
                front = rear = -1; // Reset front and rear for an empty queue
            } else {
                front = (front + 1) % MAX; // Circular queue
            }
            return x;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return 0;
        } else {
            return arr[front];
        }
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    int size() {
        if (isEmpty()) {
            return 0;
        } else if (front <= rear) {
            return (rear - front + 1);
        } else {
            return (MAX - front + rear + 1);
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX; // Circular queue
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << queue.dequeue() << " dequeued from the queue" << endl;

    cout << "Front element is " << queue.peek() << endl;

    queue.display();

    cout << "Is the queue full? " << (queue.isFull() ? "Yes" : "No") << endl;
    cout << "Current size of the queue: " << queue.size() << endl;

    return 0;
}

