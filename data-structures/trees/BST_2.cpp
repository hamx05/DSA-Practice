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

        void recursiveInsertion(Node *temp, int data, Node *parent = NULL) {
            if (root == NULL) {
                root = new Node(data);
                return;
            }

            if (temp == NULL) {
                if (data <= parent->data) parent->leftChild = new Node(data);
                else parent->rightChild = new Node(data);
                return;
            }

            parent = temp;
            if (data <= parent->data) { // OR data <= temp->data
                recursiveInsertion(temp->leftChild, data, parent);
            } else {
                recursiveInsertion(temp->rightChild, data, parent);
            }
        }

        void insert (int data) {
            if (root == NULL) {
                root = new Node(data);
                return;
            }

            Node *temp = root;
            Node *parent = temp;

            while (temp != NULL) {
                parent = temp;
                if (data <= temp->data) temp = temp->leftChild;
                else temp = temp->rightChild;
            }

            if (data <= parent->data) parent->leftChild = new Node(data);
            else parent->rightChild = new Node(data);;
        }

        void inOrder (Node *temp) {
            if (temp == NULL) {
                return;
            }

            inOrder(temp->leftChild);
            cout << temp->data << " ";
            inOrder(temp->rightChild);
        }

        Node* deleteNode (Node* temp, int target) {
            if (temp == NULL) return NULL;

            // find the node
            if (target < temp->data) {
                temp->leftChild = deleteNode(temp->leftChild, target);
            }
            else if (target > temp->data) {
                temp->rightChild = deleteNode(temp->rightChild, target);
            }
            
            // once the node has been found, we reach here
            else {
                // case 01: no children
                if (temp->leftChild == NULL && temp->rightChild == NULL) {
                    delete temp;
                    return NULL;
                }

                // case 02: 1 child
                else if (temp->rightChild == NULL) { // node has left child
                    Node *left = temp->leftChild;
                    delete temp;
                    return left;
                }

                else if (temp->leftChild == NULL) { // node has right child
                    Node *right = temp->rightChild;
                    delete temp;
                    return right;
                }

                // case 03: 2 children
                Node *inSuccessor = findInSuccessor(temp->rightChild);
                temp->data = inSuccessor->data;
                temp->rightChild = deleteNode(temp->rightChild, inSuccessor->data);
            }
        }
        
        Node* findInSuccessor(Node* right) {
            while (right->leftChild != NULL) {
                right = right->leftChild;
            }
            return right;
        }
};


int main () {

    BST b1;
    b1.insert(50);
    b1.insert(20);
    b1.insert(25);
    b1.insert(65);    
    b1.insert(78);
    b1.insert(81);
    b1.inOrder(b1.root);
    cout << endl;
    b1.deleteNode(b1.root, 65);
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



/*
question:
        30
        / \
       20  40
      /  \
     10   25
     /\     \
    5  15    27

my final avl tree:
           20
        /     \
       10      30
      /  \     / \
     5   15   25  40
                \
                27
*/