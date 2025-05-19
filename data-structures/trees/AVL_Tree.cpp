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

        int getHeight (Node* node) {
            if (node == NULL) return 0;
            return node->height;
        }

        void updateHeight(Node* node) {
            node->height = 1 + max(getHeight(node->leftChild), getHeight(node->rightChild));
        }

        int getBalanceFactor (Node* node) {
            if (node == NULL) return 0;
            return (getHeight(node->leftChild) - getHeight(node->rightChild));
        }

        Node* rotateRight (Node* y) {
        //		      y
        //		     / \
        //		    x   C     
        //		   / \
        //		  A   T2
        //--------------------------
        //			 x
        //		    / \
        //		   A   y
        //		      / \
        //		     T2   C

            Node *x = y->leftChild;
            Node *T2 = x->rightChild;

            x->rightChild = y;
            y->leftChild = T2;

            updateHeight(y);
            updateHeight(x);
            return x;
        }

        Node* rotateLeft (Node* x) {
        //			 x
        //		    / \
        //		   A   y
        //		      / \
        //		     T2   C
        //--------------------------
        //		      y
        //		     / \
        //		    x   C     
        //		   / \
        //		  A   T2
            Node* y = x->rightChild;
            Node *T2 = y->leftChild;

            y->leftChild = x;
            x->rightChild = T2;

            updateHeight(x);
            updateHeight(y);

            return y;
        }

        // Node* insert (Node* node, int data) {
        //     // if root is empty, then this node becomes the root.
        //     if (root == NULL) {
        //         root = new Node (data);
        //         return root;
        //     }
            
        //     if (node == NULL) {
        //         return new Node(data);
        //     }

        //     if (data < node->data) {
        //         node->leftChild = insert(node->leftChild, data);
        //     }
        //     else if (data > node->data) {
        //         node->rightChild = insert(node->rightChild, data);
        //     }
        //     else {
        //         return node;
        //     }

        //     updateHeight(node);
        //     int bf = getBalanceFactor(node);

        //     // Left Left
        //     if (bf > 1 && data < node->leftChild->data) {
        //         return rotateRight(node);
        //     }
        //     // Right Right
        //     if (bf < -1 && data > node->rightChild->data) {
        //         return rotateLeft(node);
        //     }
        //     // Left Right
        //     if (bf > 1 && data > node->rightChild->data) {
        //         node->leftChild = rotateLeft(node->leftChild);
        //         return rotateRight(node);
        //     }
        //     // Right Left
        //     if (bf < -1 && data < node->leftChild->data) {
        //         node->rightChild = rotateRight(node->rightChild);
        //         return rotateLeft(node);
        //     }

        //     return node;
        // }

        // void insertNode(int data) {
        //     root = insert(root, data);
        // }

        // Node *deleteNode (Node* temp, int target) {
        //     if (temp == NULL) return temp;

        //     if (target < temp->data) {
        //         temp->leftChild = deleteNode(temp->leftChild, target);
        //     }
        //     else if (target > temp->data) {
        //         temp->rightChild = deleteNode(temp->rightChild, target);
        //     }

        //     else {
        //         // node is found here.
        //         // case 01: leaf node
        //         if (temp->leftChild == NULL && temp->rightChild == NULL) {
        //             delete temp;
        //             return NULL;
        //         }
                
        //         // case 02: one child
        //         else if (temp->leftChild == NULL) {
        //             Node* right = temp->rightChild;
        //             delete temp;
        //             return right;
        //         }

        //         else if (temp->rightChild == NULL) {
        //             Node* left = temp->leftChild;
        //             delete temp;
        //             return left;
        //         }

        //         // case 03:
        //         Node *inSuccessor = findInOrderSuccessor(temp->rightChild);
        //         temp->data = inSuccessor->data;
        //         temp->rightChild = deleteNode(temp->rightChild, inSuccessor->data);
        //     }

        //     updateHeight(temp);
        //     int bf = getBalanceFactor(temp);

        //     // Left Left Case
        //     if (bf > 1 && getBalanceFactor(temp->leftChild) >= 0) {
        //         return rotateRight(temp);
        //     }
        //     // Left Right Case
        //     if (bf > 1 && getBalanceFactor(temp->leftChild) < 0) {
        //         temp->leftChild = rotateLeft(temp->leftChild);
        //         return rotateRight(temp);
        //     }
        //     // Right Right Case
        //     if (bf < -1 && getBalanceFactor(temp->rightChild) <= 0) {
        //         return rotateLeft(temp);
        //     }
        //     // Right Left Case
        //     if (bf < -1 && getBalanceFactor(temp->rightChild) > 0) {
        //         temp->rightChild = rotateRight(temp->rightChild);
        //         return rotateLeft(temp);
        //     }

        //     return temp;
        // }

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

                Node *inSuccessor = findInOrderSuccessor(temp);
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

        Node* findInOrderSuccessor(Node* right) {
            while (right->leftChild != NULL) {
                right = right->leftChild;
            }
            return right;
        }


        Node* search(Node *node, int target) {
            if (node == NULL) {
                cout << "\nValue not found!" << endl;
                return NULL;
            }

            if (target == node->data) {
                cout << "\nValue found!" << endl;
                return node;
            }

            if (target < node->data) {
                search(node->leftChild, target);
            }
            else {
                search(node->rightChild, target);
            }

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