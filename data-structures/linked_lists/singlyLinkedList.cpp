#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    
        Node () : data(0), next(NULL) {}
        Node (int d) : data (d), next(NULL) {}
};

class SLL {
    public:
        Node *head;

        SLL () : head(NULL) {}
        SLL (int d) {
            head = new Node(d);
        }

        void addAtHead (int d) {
            if (head == NULL) {
                head = new Node(d);
            }
            else {
                Node *oldHead = head;
                head = new Node(d);
                head->next = oldHead;
            }
        }

        void addAtTail (int d) {
            if (head == NULL) {
                head = new Node(d);
            } else {
                Node *temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new Node(d);
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

            // using (i < pos - 1) because we wanna stop 1 node before the desired position
            while (temp != NULL && i<pos-1) {
                temp = temp->next;
                i++;
            }
            
            if (temp == NULL) {
                cerr << "Position out of bounds." << endl;
                return;
            }
            
            // we'll reach to 1 node behind the position
            Node *newnode = new Node(d);
            newnode->next = temp->next;
            temp->next = newnode;
        }

        void deleteNode (int pos) {
            if (pos <= 0) {
                cerr << "Position can not be negative or zero." << endl;
                return;
            }
            if (pos == 1) {
                Node *temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node *curr = head;
            Node *prev = NULL;
            int i = 1;

            while (curr != NULL && i<pos) {
                prev = curr;
                curr = curr->next;
                i++;
            }
            
            if (curr == NULL) {
                cerr << "Position out of bounds." << endl;
                return;
            }

            prev->next = curr->next;
            delete curr;
        }

        void updateValue (int d, int pos) {
            if (pos <= 0) {
                cerr << "Position can not be negative or zero." << endl;
                return;
            }
            if (pos == 1) {
                head->data = d;
                return;
            }

            Node *temp = head;
            int i = 1;

            while (temp != NULL && i<pos) {
                temp = temp->next;
                i++;
            }
            
            if (temp == NULL) {
                cerr << "Position out of bounds." << endl;
                return;
            }

            temp->data = d;
        }

        void print () {
            Node *temp = head;
            while (temp != NULL) {
                cout<<temp->data << " ";
                temp = temp->next;
            }

        }
};

int main () {

    SLL l1;
    l1.addAtTail(3);
    l1.addAtTail(4);
    l1.addAtTail(5);
    l1.addAtHead(2);
    l1.addAtHead(1);
    l1.addAtSpecificPosition(6, 6);
    l1.addAtSpecificPosition(7, 7);
    l1.addAtSpecificPosition(8, 8);
    l1.deleteNode(7);
    l1.updateValue(123, 1);
    l1.print();
    cout<<endl;
    // l1.print();

    return 0;
}