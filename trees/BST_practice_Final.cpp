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

        void recursiveInsertion (Node* temp, int data, Node* parent = NULL) {
            if (root == NULL) {
                root = new Node(data);
                return;
            }

            if (temp == NULL) {
                if (data <= parent->data) 
                    parent->leftChild = new Node(data);
                else
                    parent->rightChild = new Node(data);
                return;
            }

            parent = temp;

            if (data <= temp->data) {
                recursiveInsertion(temp->leftChild, data, parent);
            }
            else {
                recursiveInsertion(temp->rightChild, data, parent);
            }
        }

        void insert (int data) {
            if (root == NULL) {
                root = new Node(data);
                return;
            }

            Node *temp = root;
            Node *parent = NULL;

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

        void inOrder (Node *temp) {
                if (temp == NULL) {
                    return;
                }

                inOrder(temp->leftChild);
                cout << temp->data << " ";
                inOrder(temp->rightChild);
            }

        Node* deleteNode (Node *temp, int target) {
            if (root == NULL) {
                cout << "root is empty. nothing to delete." << endl;
                return NULL;
            }

            if (target < temp->data) {
                temp->leftChild = deleteNode(temp->leftChild, target);
            }
            else if (target > temp->data) {
                temp->rightChild = deleteNode(temp->rightChild, target);
            }
            else { // node is found.
                if (temp->leftChild == NULL && temp->rightChild == NULL) {
                    delete temp;
                    return NULL;
                }

                else if (temp->rightChild == NULL) {
                    Node *left = temp->leftChild;
                    delete temp;
                    return left;
                }

                else if (temp->leftChild == NULL) {
                    Node *right = temp->rightChild;
                    delete temp;
                    return right;
                }

                Node *inSucessor = findInSucessor(temp);
                temp->data = inSucessor->data;
                temp->rightChild = deleteNode(temp->rightChild, inSucessor->data);
            }
        }

        Node* findInSucessor(Node *node) {
            while (node->leftChild != NULL) {
                node = node->leftChild;
            }
            return node;
        }
};


int main () {

    BST b1;
    // b1.insert(50);
    // b1.insert(20);
    // b1.insert(25);
    // b1.insert(65);    
    // b1.insert(78);
    // b1.insert(81);
    b1.recursiveInsertion(b1.root, 50);
    b1.recursiveInsertion(b1.root, 20);
    b1.recursiveInsertion(b1.root, 25);
    b1.recursiveInsertion(b1.root, 65);    
    b1.recursiveInsertion(b1.root, 78);
    b1.recursiveInsertion(b1.root, 81);
    b1.inOrder(b1.root);
    cout << endl;
    b1.deleteNode(b1.root, 20);
    b1.inOrder(b1.root);
    cout << endl;
    



    return 0;
}

