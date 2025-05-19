#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
    
        Node () : data(0), next(NULL), prev(NULL) {}
        Node (int d) : data (d), next(NULL), prev(NULL) {}
};

class DLL {
    public:
        Node *head;

        DLL () : head(NULL) {}
        DLL (int d) {
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
                oldHead->prev = head;
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
                temp->next = new Node(d); // add new node at last
                temp->next->prev = temp; // link the next of prevNode with NewNode
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

            Node *behindPos = head;
            int i = 1;

            while (behindPos != NULL && i<pos-1) {
                behindPos = behindPos->next;
                i++;
            }
            
            if (behindPos == NULL) {
                cerr << "Position out of bounds." << endl;
                return;
            }
            
            // we'll reach to 1 node behind the position
            // e.g adding 4 b/w 3 and 5 in the series -> 1,2,3,5
            Node *newnode = new Node(d);
            newnode->next = behindPos->next; // connecting posNode with pos+1Node
            if (behindPos->next != NULL) newnode->next->prev = newnode; // connecting pos+1Node's prev with newNode
            behindPos->next = newnode; // updating posNode to newNode
            newnode->prev = behindPos; // connecting newNode's prev with pos-1Node
        }

        void deleteNode (int pos) {
            if (pos <= 0) {
                cerr << "Position can not be negative or zero." << endl;
                return;
            }
            if (pos == 1) {
                Node *temp = head;
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
                delete temp;
                return;
            }

            Node *currNode = head;
            Node *prevNode;
            int i = 1;

            while (currNode != NULL && i<pos) {
                prevNode = currNode;
                currNode = currNode->next;
                i++;
            }
            
            if (currNode == NULL) {
                cerr << "Position out of bounds." << endl;
                return;
            }

            prevNode->next = currNode->next;
            if (currNode->next != NULL) currNode->next->prev = prevNode;
            delete currNode;
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

    DLL l1;
    // l1.addAtTail(3);
    // l1.addAtTail(4);
    // l1.addAtTail(5);
    l1.addAtHead(2);
    l1.addAtHead(1);
    // l1.addAtSpecificPosition(6, 6);
    // l1.addAtSpecificPosition(7, 7);
    // l1.addAtSpecificPosition(8, 8);
    // l1.deleteNode(8);
    // l1.updateValue(123, 1);
    l1.print();
    cout<<endl;
    // l1.print();

    return 0;
}
