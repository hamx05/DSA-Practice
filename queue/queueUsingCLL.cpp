#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node () : data(0), next(NULL) {}
        Node (int d) : data(d), next(NULL) {}
};

class CQ {
    public:
        Node *head;
        Node *tail;

        CQ () : head(NULL), tail(NULL) {}
        CQ (int d) {
            head = new Node(d);
            tail = head;
        }

        void addData (int d) {
            if (head == NULL) {
                head = new Node(d);
                tail = head;
                tail->next = head;
            } else {
                Node *temp = tail;
                temp->next = new Node(d);
                tail = temp->next;
                tail->next = head;  
            }
        }

        void popData () {
            if (head == NULL) {
                cout<<"\nList is already empty, no element can be popped." << endl;
                return;
            }
            
            if (head->next == head) {
            	delete head;
            	head = NULL;
            	tail = NULL;
            	return;
			}

            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }

        void print() {
        	
        	if (head == NULL) {
        		cout<<"Queue is empty." << endl;
        		return;
			}
			
            Node *temp = head;
            cout<<"Elements in the queue: "<<endl;
            do {
                cout<< temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            
            cout<< endl;
        }
};

int main () {
	
    CQ q1;
    q1.addData(1);
    q1.addData(2);
    q1.addData(3);
    q1.print();
    
    // Pop 1
    cout<<"\nPopping 1 and then printing the queue: ";
    q1.popData();
    cout<<endl;
    q1.print();                
	
	// Pop 2
	cout<<"\nPopping 2 and then printing the queue: ";
	q1.popData();
    cout<<endl;
    q1.print();
    
	// Pop 3
	cout<<"\nPopping 3 and then printing the queue: ";
	q1.popData();
    cout<<endl;
    q1.print();
    
    // Invalid Pop
    cout<<"\nTrying to pop an empty Queue: ";
    q1.popData();
	
	return 0;
}
