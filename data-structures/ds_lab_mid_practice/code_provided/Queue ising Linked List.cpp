#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;

        cout << data << " enqueued into the queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return 0;
        }

        int data = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;

        cout << data << " dequeued from the queue" << endl;
        return data;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        Node* current = front;
        while (current) {
            cout << current->data;
            current = current->next;
            if (current) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element is " << queue.peek() << endl;

    queue.display();

    cout << "Current size of the queue: " << queue.getSize() << endl;

    return 0;
}

