#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* leftChild;
        Node* rightChild;
        int height;

        Node() : data(0), leftChild(nullptr), rightChild(nullptr), height(1) {}
        Node(int d) : data(d), leftChild(nullptr), rightChild(nullptr), height(1) {}
};

class AVLTree {
    public:
        Node* root;

        AVLTree() : root(nullptr) {}

        // Get height of a node
        int height(Node* node) {
            if (node == nullptr) {
                return 0; 
            } 
            return node->height; 
        }

        // Calculate balance factor of a node
        int balanceFactor(Node* node) {        
            if (node == nullptr)  {
                return 0; 
            }
            return height(node->leftChild) - height(node->rightChild); 
        }

        // Update height of a node
        void updateHeight(Node* node) {
            node->height = 1 + max(height(node->leftChild), height(node->rightChild));
        }

        // Right rotation
        Node* rotateRight(Node* y) {
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
            Node* x = y->leftChild; 
            Node* T2 = x->rightChild;

            x->rightChild = y;
            y->leftChild = T2;

            updateHeight(y);
            updateHeight(x);

            return x;
        }

        // Left rotation
        Node* rotateLeft(Node* x) {
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
            Node* T2 = y->leftChild;

            y->leftChild = x;
            x->rightChild = T2;

            updateHeight(x);
            updateHeight(y);

            return y;
        }

        // Recursive function to insert a node and balance the tree
        Node* insert(Node* node, int data) {
            // If there is no root, this becomes the root
            if (node == nullptr)
                return new Node(data);
            // If the data is smaller than the current node, insert it in the left subtree
            if (data < node->data)
                node->leftChild = insert(node->leftChild, data);
            // If the data is greater than the current node, insert it in the right subtree
            else if (data > node->data)
                node->rightChild = insert(node->rightChild, data);
            else
                return node;

            updateHeight(node);
            int balance = balanceFactor(node);
            // If this node becomes unbalanced, then there are 4 cases 
            // Rotate to balance the tree if needed
            
            // Left Left Case 
            if (balance > 1 && data < node->leftChild->data)
                return rotateRight(node);
            // Right Right Case 
            if (balance < -1 && data > node->rightChild->data)
                return rotateLeft(node);
            // Left Right Case            
            if (balance > 1 && data > node->leftChild->data) {
                node->leftChild = rotateLeft(node->leftChild);
                return rotateRight(node);
            }
            // Right Left Case 
            if (balance < -1 && data < node->rightChild->data) {
                node->rightChild = rotateRight(node->rightChild);
                return rotateLeft(node);
            }
            // Return the (unchanged) node pointer 
            return node;
        }

        // Wrapper function to insert a node starting from root
        void insertNode(int data) {
            root = insert(root, data);
        }

        // Recursive search function
        Node* search(Node* node, int key) {
            // Base case: if node is null or key is found
            if (node == nullptr || node->data == key) {
                return node;
            }

            // If key is less than the current node's data, search in the left subtree
            if (key < node->data) {
                return search(node->leftChild, key);
            }
            else {
                // If key is greater than the current node's data, search in the right subtree
                return search(node->rightChild, key);
            }
            
        }

        // Wrapper function for search
        Node* search(int key) {
            return search(root, key);
        }

        // Recursive function to delete a node and balance the tree
        Node* deleteNode(Node* node, int data) {
            // Base case: if the tree is empty
            if (node == nullptr)
                return node;
        
            // Traverse the tree
            if (data < node->data)
                node->leftChild = deleteNode(node->leftChild, data);  // Go left
            else if (data > node->data)
                node->rightChild = deleteNode(node->rightChild, data);  // Go right
            else {
                // Node to be deleted found
                // Case 1: Node has no child (leaf node)
                if ((node->leftChild == nullptr) || (node->rightChild == nullptr)) {
                    // Node* temp = node->leftChild ? node->leftChild : node->rightChild;
                    Node* temp;
                    if (node->leftChild) {
                        temp = node->leftChild;
                    } else {
                        temp = node->rightChild;
                    }

                    if (temp == nullptr) {
                        temp = node;
                        node = nullptr;
                    } else {
                        *node = *temp;  // Copy the contents of the non-empty child
                    }
                    delete temp;  // Delete the old node
                }

                // case 03: node has 2 children
                else {
                    Node* temp = findMin(node->rightChild);  // Find the in-order successor
                    node->data = temp->data;  // Replace the data with the successor's data
                    node->rightChild = deleteNode(node->rightChild, temp->data);  // Delete the successor node
                }
            }

            // If the node is now null, return null
            if (node == nullptr)
                return node;

            // Update the height of the current node
            updateHeight(node);
            
            // Get the balance factor of this node
            int balance = balanceFactor(node);

            // Rotate to balance the tree if needed
            // Left Left Case
            if (balance > 1 && balanceFactor(node->leftChild) >= 0)
                return rotateRight(node);

            // Left Right Case
            if (balance > 1 && balanceFactor(node->leftChild) < 0) {
                node->leftChild = rotateLeft(node->leftChild);
                return rotateRight(node);
            }

            // Right Right Case
            if (balance < -1 && balanceFactor(node->rightChild) <= 0)
                return rotateLeft(node);

            // Right Left Case
            if (balance < -1 && balanceFactor(node->rightChild) > 0) {
                node->rightChild = rotateRight(node->rightChild);
                return rotateLeft(node);
            }

            return node;  // Return the (potentially new) root of the subtree
        }


        Node* deleteNode(Node* node, int data) {
            // Base case: if the tree is empty
            if (node == nullptr)
                return node;

            // Search for the node to delete
            if (data < node->data) {
                node->leftChild = deleteNode(node->leftChild, data); // Go left
            } else if (data > node->data) {
                node->rightChild = deleteNode(node->rightChild, data); // Go right
            } else {
                // Node to be deleted found

                // Case 1: Node has no children (leaf node)
                if (node->leftChild == nullptr && node->rightChild == nullptr) {
                    delete node;
                    return nullptr;
                }

                // Case 2: Node has one child (left or right)
                else if (node->leftChild == nullptr) {
                    Node* right = node->rightChild;
                    delete node;
                    return right;
                } else if (node->rightChild == nullptr) {
                    Node* left = node->leftChild;
                    delete node;
                    return left;
                }

                // Case 3: Node has two children
                // Find the inorder successor
                Node* minRight = findMin(node->rightChild);
                node->data = minRight->data; // Replace with inorder successor's data
                node->rightChild = deleteNode(node->rightChild, minRight->data); // Delete the inorder successor
            }

            // Update the height of the current node
            updateHeight(node);

            // Get the balance factor of this node
            int balance = balanceFactor(node);

            // Rotate to balance the tree if needed
            // Left Left Case
            if (balance > 1 && balanceFactor(node->leftChild) >= 0)
                return rotateRight(node);

            // Left Right Case
            if (balance > 1 && balanceFactor(node->leftChild) < 0) {
                node->leftChild = rotateLeft(node->leftChild);
                return rotateRight(node);
            }

            // Right Right Case
            if (balance < -1 && balanceFactor(node->rightChild) <= 0)
                return rotateLeft(node);

            // Right Left Case
            if (balance < -1 && balanceFactor(node->rightChild) > 0) {
                node->rightChild = rotateRight(node->rightChild);
                return rotateLeft(node);
            }

            return node; // Return the (potentially new) root of the subtree
        }



        // Wrapper function for delete
        void deleteNode(int data) {
            root = deleteNode(root, data);
        }

        // Function to find the node with the minimum value
        Node* findMin(Node* node) {
            while (node->leftChild != nullptr)
                node = node->leftChild;
            return node;
        }

        // In-order traversal (left-root-right)
        void inOrderTraversal(Node* temp) {
            if (temp != nullptr) {
                inOrderTraversal(temp->leftChild);
                cout << "Data: " << temp->data << endl;
                inOrderTraversal(temp->rightChild);
            }
        }

        // Public display method to call the in-order traversal
        void displayInOrder() {
            cout << "In-Order Traversal:" << endl;
            inOrderTraversal(root);
            cout << endl;
        }
};

int main() {
    AVLTree tree;
    tree.insertNode(68);
    tree.insertNode(90);
    tree.insertNode(105);
    tree.insertNode(95);
    tree.insertNode(110);
    tree.insertNode(30);
    tree.insertNode(80);

    tree.displayInOrder();

    // int keyToSearch = 30;
    // Node* foundNode = tree.search(keyToSearch);
    // if (foundNode) {
    //     cout << "Node with key " << keyToSearch << " found: " << foundNode->data << endl;
    // } else {
    //     cout << "Node with key " << keyToSearch << " not found." << endl;
    // }

    cout << "Deleting 30...\n";
    tree.deleteNode(30);
    tree.displayInOrder();

    return 0;
}
