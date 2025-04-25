#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *leftChild;
        Node *rightChild;

        Node (int d) : data(d), leftChild(NULL), rightChild(NULL) {}
};

class BST {
    public:
        Node *root;

        BST () : root(NULL) {}

        void recursiveInsertion(Node* temp, int data, Node* parent = NULL) {
            if (root == NULL) {
                root = new Node(data);
                return;
            }

            if (temp == NULL) {
                if (data <= parent->data) {
                    parent->leftChild = new Node(data);
                }
                else {
                    parent->rightChild = new Node(data);
                }
                return;
            }

            parent = temp;
            if (data <= temp->data) recursiveInsertion(temp->leftChild, data, parent);
            else recursiveInsertion(temp->rightChild, data, parent);
        }

        void insertNode (int data) {
            if (root == NULL) {
                root = new Node(data);
                return;
            }

            Node *temp = root;
            Node *parent = temp;

            while (temp != NULL) {
                parent = temp;
                if (data <= temp->data) {
                    temp = temp->leftChild;
                }
                else {
                    temp = temp->rightChild;
                }
            }
            
            if (data <= parent->data) {
                parent->leftChild = new Node(data);
            }
            else {
                parent->rightChild = new Node(data);
            }
        }

        void inOrder (Node* temp) {
            if (temp == NULL) {
                return;
            }

            inOrder(temp->leftChild);
            cout << temp->data << " ";
            inOrder(temp->rightChild);
        }

        void search(Node *temp, int data) {
            if (temp == NULL) {
                cout << "Value is not found." << endl;
                return;
            }
            
            if (data == temp->data) {
                cout << "Value found." << endl;
                return;
            }

            if (data <= temp->data) search(temp->leftChild, data);
            else search(temp->rightChild, data);
        }

        Node* deleteNode (Node *temp, int target) {
            if (temp == NULL) return temp;

            // find the node
            if (target < temp->data) {
                temp->leftChild = deleteNode(temp->leftChild, target);
            } else if (target > temp->data) {
                temp->rightChild = deleteNode(temp->rightChild, target);
            }

            // if we are coming here, then the node must be found.
            else {
                // case 01: node has 0 children
                if (temp->leftChild == NULL && temp->rightChild == NULL) {
                    delete temp;
                    return NULL;
                }

                // case 02: node has 1 child (either left or right)
                else if (temp->leftChild != NULL) {
                    Node *left = temp->leftChild;
                    delete temp;
                    return left;
                    
                }
                else if (temp->rightChild != NULL) {
                    Node *right = temp->rightChild;
                    delete temp;
                    return right;
                }

                // case 03: node has 2 children
                // steps : find the inorder predecessor OR inorder successor, and replace it with the node
                
                // how to find predecessor: Node's left child ka sabse right element
                Node *inPredecessor = findInorderPredecessor(temp->leftChild);
                temp->data = inPredecessor->data;
                temp->leftChild = deleteNode(temp->leftChild, inPredecessor->data);

                // how to find successor: Node's right child ka sabse left element
                // Node *inSuccessor = findInorderSuccessor(temp->rightChild);
                // temp->data = inSuccessor->data;
                // temp->rightChild = deleteNode(temp->rightChild, inSuccessor->data);
            }
        }

        Node* findInorderPredecessor(Node *left) {
            while (left->rightChild != NULL) {
                left = left->rightChild;
            }
            return left;
        }

        Node* findInorderSuccessor(Node *right) {
            while (right->leftChild != NULL) {
                right = right->leftChild;
            }
            return right;
        }

};


int main () {

    BST b1;
    b1.insertNode(50);
    b1.insertNode(20);
    b1.insertNode(25);
    b1.insertNode(65);    
    b1.insertNode(78);
    b1.insertNode(81);
    b1.inOrder(b1.root);
    cout << endl;

    b1.deleteNode(b1.root, 81);
    b1.inOrder(b1.root);
    cout << endl;


    // b1.recursiveInsertion(b1.root, 50);
    // b1.recursiveInsertion(b1.root, 20);
    // b1.recursiveInsertion(b1.root, 25);
    // b1.recursiveInsertion(b1.root, 65);    
    // b1.recursiveInsertion(b1.root, 78);
    // b1.recursiveInsertion(b1.root, 81);


    return 0;
}