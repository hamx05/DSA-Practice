#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* leftChild;
        Node* rightChild;
        int height;

        Node() : data(0), leftChild(NULL), rightChild(NULL), height(1) {}
        Node(int d) : data(d), leftChild(NULL), rightChild(NULL), height(1) {}
};

class AVLTree {
    public:
        Node* root;

        AVLTree() : root(nullptr) {}

        int getHeight (Node *node) {
            if (node == NULL) return 0;
            return node->height;
        }

        void updateHeight (Node *node) {
            node->height =  1 + max(getHeight(node->leftChild), getHeight(node->rightChild));
        }

        int getBalanceFactor (Node *node) {
            if (node == NULL) {
                return 0;
            }
            return (getHeight(node->leftChild) - getHeight(node->rightChild));
        }

        Node* rotateRight (Node* x) {
            Node *y = x->leftChild;
            Node *T2 = y->rightChild;

            y->rightChild = x;
            x->leftChild = T2;
            
            updateHeight(x);
            updateHeight(y);

            return y;
        }

        Node *rotateLeft (Node *x) {
            Node *y = x->rightChild;
            Node *T2 = y->leftChild;

            y->leftChild = x;
            x->rightChild = T2;
        
            updateHeight(x);
            updateHeight(y);

            return y;
        }

        Node* insertNode (Node *temp, int data) {
            if (root == NULL) {
                root = new Node(data);
                return root;
            }

            if (temp == NULL) {
                return new Node(data);
            }

            if (data < temp->data) {
                temp->leftChild = insertNode(temp->leftChild, data);
            }
            else if (data > temp->data) {
                temp->rightChild = insertNode(temp->rightChild, data);
            }
            else { // node is found
                return temp;   
            }

            updateHeight(temp);
            int bf = getBalanceFactor(temp);

            // Left Left
            if (bf > 1 && data < temp->leftChild->data) {
                return rotateRight(temp);
            }

            // Right Right
            if (bf < -1 && data > temp->rightChild->data) {
                return rotateLeft(temp);
            }

            // Left Right
            if (bf > 1 && data > temp->rightChild->data) {
                temp->leftChild = rotateLeft(temp->leftChild);
                return rotateRight(temp);
            }

            // Right Left
            if (bf < -1 && data < temp->leftChild->data) {
                temp->rightChild = rotateRight(temp->rightChild);
                return rotateLeft(temp);
            }

            return temp;
        }

        void insert(int data) {
            root = insertNode(root, data);
        }

        Node *deleteNode (Node *temp, int target) {
            if (temp == NULL) {
                return temp;
            }

            if (target < temp->data) {
                temp->leftChild = deleteNode(temp->leftChild, target);
            }
            else if (target > temp->data) {
                temp->rightChild = deleteNode(temp->rightChild, target);
            }
            else { // node found
                if (temp->leftChild == NULL && temp->rightChild == NULL) {
                    delete temp;
                    return NULL;
                }

                // case 02: one child
                else if (temp->leftChild == NULL) {
                    Node* right = temp->rightChild;
                    delete temp;
                    return right;
                }

                else if (temp->rightChild == NULL) {
                    Node* left = temp->leftChild;
                    delete temp;
                    return left;
                }

                Node *inSuccessor = findInSuccessor(temp);
                temp->data = inSuccessor->data;
                temp->rightChild = deleteNode(temp->rightChild, inSuccessor->data);
            }

            updateHeight(temp);
            int bf = getBalanceFactor(temp);

            // Left Left
            if (bf > 1 && getBalanceFactor(temp->leftChild) <= 0) {
                return rotateRight(temp);
            }

            // Right Right
            if (bf < -1 && getBalanceFactor(temp->rightChild) >= 0) {
                return rotateLeft(temp);
            }

            // Left Right
            if (bf > 1 && getBalanceFactor(temp->rightChild) > 0) {
                temp->leftChild = rotateLeft(temp->leftChild);
                return rotateRight(temp);
            }

            // Right Left
            if (bf < -1 && getBalanceFactor(temp->rightChild) < 0) {
                temp->rightChild = rotateRight(temp->rightChild);
                return rotateLeft(temp);
            }

            return temp;
        }

        Node* findInSuccessor(Node *node) {
            while (node->leftChild != NULL) {
                node = node->leftChild;
            }
            return node;
        }
        
        void inOrderTraversal (Node* node) {
            if (node == NULL) return;
            inOrderTraversal(node->leftChild);
            cout << node->data << " ";
            inOrderTraversal(node->rightChild);
        }
};

int main () {

    AVLTree t1;

    cout << "test" << endl;
    t1.insertNode(t1.root, 5);
    t1.insertNode(t1.root, 10);
    t1.insertNode(t1.root, 3);
    t1.insertNode(t1.root, 16);
    t1.insertNode(t1.root, 25);
    t1.inOrderTraversal(t1.root);

    t1.deleteNode(t1.root, 3);
    cout << endl;
    t1.inOrderTraversal(t1.root);
    
    // t1.search(t1.root, 35);


}