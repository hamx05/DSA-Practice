#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    
        Node () : data(0), next(NULL) {}
        Node (int d) : data (d), next(NULL) {}
};

class SCLL {
    public:
        Node *head;
        Node *tail;

        SCLL () : head(NULL), tail(NULL) {}
        SCLL (int d) {
            head = new Node(d);
            tail = head;
            tail->next = head;
        }

        void addAtHead (int d) {
            if (head == NULL) {
                head = new Node(d);
                tail = head;
                tail->next = head;
            }
            else {
                Node *oldHead = head;
                head = new Node(d);
                head->next = oldHead;
                tail->next = head;
            }
        }

        void addAtTail (int d) {
            if (head == NULL) {
                head = new Node(d);
                tail = head;
                tail->next = head;
            } else {
                Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = new Node(d);
                tail = temp->next;
                tail->next = head;
            }
        }

        void addAtSpecificPosition (int d, int pos) {
            if (pos <= 0) {
                cerr << "Position can not be negative or zero." << endl;
                return;
            }
            if (pos == 1) {
                addAtHead(d);
                return;
            }

            Node *temp = head;
            int i = 1;

            while (temp != NULL && i<pos-1) {
                temp = temp->next;
                i++;
            }
            
            if (temp == NULL) {
                cerr << "Position out of bounds." << endl;
                return;
            }
            
            // we'll reach to 1 node behind the position
            if (temp == tail) { // if we are reached at tail
                addAtTail(d);
                return;
            }

            Node *newnode = new Node(d);
            newnode->next = temp->next;
            temp->next = newnode;
        }
        
        void print() {
            if (head == NULL) {
                cout<<"List is empty." << endl;
                return;   
            }

            Node *temp = head;
            
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
        }
};

int main () {
    SCLL l1;
    l1.addAtTail(3);
    l1.addAtTail(4);
    l1.addAtTail(5);
    l1.addAtHead(2);
    l1.addAtHead(1);
    l1.addAtSpecificPosition(6, 6);
    l1.addAtSpecificPosition(7, 7);
    l1.addAtSpecificPosition(8, 8);
    // l1.deleteNode(7);
    // l1.updateValue(123, 1);
    l1.print();
    cout<<endl;
    // l1.print();

    

    return 0;
}
