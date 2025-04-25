#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    public:
        int arr[MAX];
        int top; // top -1 is empty
        int size; // size = 0 is empty

        Stack () : top(-1), size(0) {}

        void push (int x) {
            if (top != -1 && size == MAX) {
                cout<<"Overflow condition. Element cannot be added." << endl;
                return;
            }
            else {
                top++;
                size++;
                arr[top] = x;
                cout<< arr[top] << " has been pushed to the stack." << endl;
            }
        }

        void pop () {
            if (top == -1) {
                cout<<"Underflow condition. Stack is already empty." << endl;
                return;
            }
            else {
                size--;
                cout << arr[top--] << " has been removed from the stack." << endl;
            }
        }

        void peek () {
            if (top == -1) {
                cout<<"Underflow condition. Stack is empty." << endl;
                return;
            }
            else {
                cout << arr[top] << " is the top element." << endl;
            }
        }

        void print() {
            cout<<"Size: " << size<<endl;
            cout<<"Elements in the stack are: " << endl;
            for (int i=size-1; i>=0; i--) {
                cout<<arr[i] << " ";
            }
            cout<<endl;
        }
};

int main () {

    Stack s;
    s.push(5);
    s.push(3);
    s.push(6);
    s.print();
    s.peek();
    s.pop();
    s.pop();
    s.print();
    
    return 0;
}