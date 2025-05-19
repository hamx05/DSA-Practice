#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Node class representing each node in the adjacency list
class Node {
public:
    int data;   // The node's data (neighbor)
    Node* next; // Pointer to the next node in the adjacency list

    // Constructor to initialize the node with given data
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Graph class to handle the graph operations using adjacency list
class Graph {
public:
    int nodes;              // Number of nodes in the graph
    Node** adjList;         // Array of pointers to adjacency lists
    bool* visited;          // Array to track visited nodes for DFS and BFS

    // Constructor to initialize the graph with n nodes
    Graph(int n) {
        nodes = n;
        adjList = new Node*[nodes];
        visited = new bool[nodes];

        // Initialize all adjacency lists as nullptr (no neighbors)
        for (int i = 0; i < nodes; i++) {
            adjList[i] = nullptr;
            visited[i] = false;
        }
    }

    // Insert an edge between node u and node v
    void insertEdge(int u, int v) {
        // Create a new node for the adjacency list of u
        Node* newNode = new Node(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        // Create a new node for the adjacency list of v (for undirected graph)
        newNode = new Node(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    // Delete an edge between node u and node v
    void deleteEdge(int u, int v) {
        // Remove v from adjacency list of u
        Node* temp = adjList[u];
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != v) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) {
            if (prev == nullptr) {
                adjList[u] = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
        }

        // Remove u from adjacency list of v (for undirected graph)
        temp = adjList[v];
        prev = nullptr;
        while (temp != nullptr && temp->data != u) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) {
            if (prev == nullptr) {
                adjList[v] = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
        }
    }

    // Search for a node
    void searchNode(int node) {
        if (node >= 0 && node < nodes) {
            cout << "Node " << node << " exists in the graph.\n";
        } else {
            cout << "Node " << node << " does not exist.\n";
        }
    }

    // Reset the visited array for DFS/BFS
    void resetVisited() {
        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
        }
    }

    // DFS traversal using stack
    void DFS(int startNode) {
        resetVisited();
        stack<int> s;
        s.push(startNode);
        visited[startNode] = true;

        cout << "DFS Traversal: ";
        while (!s.empty()) {
            int currentNode = s.top();
            s.pop();
            cout << currentNode << " ";

            // Push all unvisited neighbors to the stack
            Node* temp = adjList[currentNode];
            while (temp != nullptr) {
                int neighbor = temp->data;
                if (!visited[neighbor]) {
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    // BFS traversal using queue
    void BFS(int startNode) {
        resetVisited();
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            cout << currentNode << " ";

            // Enqueue all unvisited neighbors
            Node* temp = adjList[currentNode];
            while (temp != nullptr) {
                int neighbor = temp->data;
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    bool isCyclicUtility(int node, int parent)
    {
        visited[node] = 1;
        Node *temp = adjList[node];

        while (temp != NULL)
        {
            int neighbour = temp->data;
            if (!visited[neighbour])
            {
                if (isCyclicUtility(neighbour, node))
                    return true;
                if (parent != neighbour)
                    return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool isCyclic()
    {
        resetVisited();
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                if (isCyclicUtility(i, -1))
                {
                    resetVisited();
                    return true;
                }
            }
        }
        resetVisited();
        return false;
    }

    // Display the adjacency list
    void displayGraph() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < nodes; i++) {
            cout << i << ": ";
            Node* temp = adjList[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    
    // Destructor to clean up the dynamically allocated memory
    ~Graph() {
        for (int i = 0; i < nodes; i++) {
            Node* temp = adjList[i];
            while (temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjList;
        delete[] visited;
    }
};

int main() {
    int n = 5; // Number of nodes in the graph
    Graph g(n);

    // Insert edges
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(3, 4);

    // Display the adjacency list
    g.displayGraph();

    // Perform DFS and BFS
    cout << "\nDFS Traversal starting from node 0:\n";
    g.DFS(0);

    cout << "\nBFS Traversal starting from node 0:\n";
    g.BFS(0);

    // Search for nodes
    g.searchNode(2);
    g.searchNode(6);

    // Delete an edge and display the graph again
    g.deleteEdge(1, 3);
    g.displayGraph();

    return 0;
}