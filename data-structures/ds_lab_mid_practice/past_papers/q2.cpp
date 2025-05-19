#include <iostream>
#include <string>
#include <cstring>
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
            Node *prev;
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

        Node* getHead () {
            return head;
        }

        void add (SLL &l1, SLL &l2) {
            Node *head1 = l1.getHead();
            Node *head2 = l2.getHead();
            Node *temp1 = head1;
            Node *temp2 = head2;
            Node *temp = head;

            if (head1 == NULL) {
                cout<<"List 1 is empty, so list 2 is copied to list 3." << endl;
                while (temp1 != NULL) {
                    temp = temp1;
                    temp1 = temp1->next;
                    temp = temp->next;
                }
                return;
            }

            if (head2 == NULL) {
                cout<<"List 2 is empty, so list 1 is copied to list 3." << endl;
                while (temp2 != NULL) {
                    temp = temp2;
                    temp2 = temp2->next;
                    temp = temp->next;
                }
                return;
            }

            int sum;
            int carry = 0;
            bool CF = false;
            while (temp1 != NULL && temp2 != NULL) {
                if (temp1->data + temp2->data + carry > 9) {
                    CF = true;
                    string toDivide = to_string(temp1->data + temp2->data);
                    temp1->data = toDivide[0];
                    int sum = toDivide[1];
                    addAtTail(sum);
                }
                else {
                    int sum = temp1->data + temp2->data;
                    if (CF) temp->data += carry;
                    temp = temp->next;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                
                    // If sum is greater than 9, we set carry
                    // carry = sum / 10; // Carry is sum divided by 10
                    // sum = sum % 10;   // The digit to store is sum mod 10

                    // Insert the sum digit into the result list
                    addAtTail(sum);
                    

                    // If there is a carry left after processing all digits, add it
                    // if (carry > 0) {
                    //     addAtTail(carry);
                    // }
                }
            }


        }

        

        void print () {
            Node *temp = head;
            while (temp != NULL) {
                cout<<temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main () {

    // 1 -> 3 -> 4 -> 7
    SLL l1;
    l1.addAtTail(1);
    l1.addAtTail(3);
    l1.addAtTail(4);
    l1.addAtTail(7);
    l1.print();

    // 1 -> 9 -> 8 -> 9 -> 4 -> 7
    SLL l2;
    l2.addAtTail(1);
    l2.addAtTail(9);
    l2.addAtTail(8);
    l2.addAtTail(9);
    l2.addAtTail(4);
    l2.addAtTail(7);
    l2.print();
    
    // sum = 2 -> 0 -> 0 -> 1 -> 9 -> 4
    SLL l3;
    l3.add(l1, l2);
    l3.print();


    return 0;
}
