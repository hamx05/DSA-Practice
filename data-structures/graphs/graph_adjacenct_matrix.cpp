#include <iostream>
#include <stack> // For DFS
#include <queue> // For BFS
using namespace std;

class Graph {
public:
    int nodes;                  // Number of nodes
    int adjacencyMatrix[100][100]; // Adjacency matrix (max size: 100 nodes)
    bool visited[100];          // To track visited nodes for DFS/BFS
    
    // Constructor
    Graph(int n) {
        nodes = n;
        // Initialize adjacency matrix to 0
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    // Insert an edge between two nodes
    void insertEdge(int u, int v) {
        if (u >= 0 && u < nodes && v >= 0 && v < nodes) {
            adjacencyMatrix[u][v] = 1; // Add edge from u to v
            adjacencyMatrix[v][u] = 1; // For undirected graph
        } else {
            cout << "Invalid nodes!\n";
        }
    }

    // Delete an edge between two nodes
    void deleteEdge(int u, int v) {
        if (u >= 0 && u < nodes && v >= 0 && v < nodes) {
            adjacencyMatrix[u][v] = 0; // Remove edge from u to v
            adjacencyMatrix[v][u] = 0; // For undirected graph
        } else {
            cout << "Invalid nodes!\n";
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

    // Reset the visited array for new DFS/BFS traversal
    void resetVisited() {
        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
        }
    }

    // DFS Traversal using Built-in Stack
    void DFS(int startNode) {
        resetVisited(); // Ensure visited array is clean
        stack<int> s;   // Stack for DFS
        s.push(startNode); // Push start node onto stack
        visited[startNode] = true;

        cout << "DFS Traversal: ";
        while (!s.empty()) {
            int currentNode = s.top();
            s.pop();
            cout << currentNode << " "; // Process the node

            // Push all unvisited neighbors of the current node onto the stack
            for (int i = nodes - 1; i >= 0; i--) { // Reverse order for consistent traversal
                if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                    s.push(i); // Push onto stack
                    visited[i] = true; // Mark as visited
                }
            }
        }
        cout << endl;
    }

    // BFS Traversal using Queue
    void BFS(int startNode) {
        resetVisited(); // Ensure visited array is clean

        queue<int> q; // Queue for BFS
        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            cout << currentNode << " "; // Process the current node

            // Visit all unvisited neighbors
            for (int i = 0; i < nodes; i++) {
                if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i); // Enqueue
                }
            }
        }
        cout << endl;
    }

    // Display the graph (adjacency matrix)
    void displayGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
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

    // Display the adjacency matrix
    g.displayGraph();

    // Traverse using DFS
    cout << "\nDFS Traversal starting from node 0:\n";
    g.DFS(0);

    // Traverse using BFS
    cout << "\nBFS Traversal starting from node 0:\n";
    g.BFS(0);

    // Search for a node
    cout << "\nSearching for nodes:\n";
    g.searchNode(2);
    g.searchNode(6);

    // Delete an edge and traverse again
    cout << "\nGraph after deleting edge (1, 3):\n";
    g.deleteEdge(1, 3);
    g.displayGraph();

    cout << "\nDFS Traversal after modification:\n";
    g.DFS(0);

    return 0;
}
