#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node () : data(0), next(NULL) {}
        Node (int d) : data(d), next(NULL) {}
};

class Stack {
    public:
        Node *top;

        Stack () : top(NULL) {}
        Stack (int d) {
            top = new Node (d);
        }

        void push (int d) { // add new elements at top
            if (top == NULL) {
                top = new Node(d);
            }
            else {
                Node *newnode = new Node(d);
                newnode->next = top;
                top = newnode;
            }
        }

        void pop () {
            if (top != NULL) {
                Node *temp = top;
                top = top->next;
                delete temp;
            }
            else {
                cout<<"Top is empty." << endl;
            }
        }

        void peek () {
            if (top != NULL) {
                cout<<"Top = " << top->data << endl;
            }
            else {
                cout<<"Top is empty." << endl;
            }
        }

        void print () {
            Node *temp = top;
            while (temp != NULL) {
                cout<<temp->data << " " << endl;
                temp = temp->next;
            }
        }
};


int main () {

    Stack s1;
    s1.push(5);
    s1.push(4);
    s1.peek();
    s1.push(3);
    s1.print();
    cout<<endl;
    s1.pop();
    s1.print();

}