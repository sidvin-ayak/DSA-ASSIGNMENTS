#include <iostream>
using namespace std;

#define MAX 100  // maximum number of vertices

class Graph {
private:
    int adj[MAX][MAX];
    int numVertices;

public:
    Graph(int vertices) {
        if (vertices > MAX || vertices <= 0) {
            cout << "Invalid number of vertices. Setting to 0." << endl;
            numVertices = 0;
        } else {
            numVertices = vertices;
        }
        // Initialize adjacency matrix with 0
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                adj[i][j] = 0;
    }

    void insertEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            adj[src][dest] = 1;
            adj[dest][src] = 1;  // assuming undirected graph
            cout << "Edge inserted between " << src << " and " << dest << "." << endl;
        }
    }

    void deleteEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            if (adj[src][dest] == 1) {
                adj[src][dest] = 0;
                adj[dest][src] = 0;
                cout << "Edge deleted between " << src << " and " << dest << "." << endl;
            } else {
                cout << "No edge exists between " << src << " and " << dest << "." << endl;
            }
        }
    }

    void searchEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            if (adj[src][dest] == 1) {
                cout << "Edge exists between " << src << " and " << dest << "." << endl;
            } else {
                cout << "No edge between " << src << " and " << dest << "." << endl;
            }
        }
    }

    void displayGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    bool isValidVertex(int v) {
        if (v >= 0 && v < numVertices) {
            return true;
        } else {
            cout << "Invalid vertex: " << v << ". Must be between 0 and " << numVertices - 1 << "." << endl;
            return false;
        }
    }
};

int main() {
    int vertices, choice, src, dest;
    
    cout << "Enter the number of vertices in the graph (max " << MAX << "): ";
    cin >> vertices;
    
    Graph g(vertices);

    while (true) {
        cout << "\n--- Graph ADT Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source and destination vertices: ";
            cin >> src >> dest;
            g.insertEdge(src, dest);
            break;
        case 2:
            cout << "Enter source and destination vertices to delete: ";
            cin >> src >> dest;
            g.deleteEdge(src, dest);
            break;
        case 3:
            cout << "Enter source and destination vertices to search: ";
            cin >> src >> dest;
            g.searchEdge(src, dest);
            break;
        case 4:
            g.displayGraph();
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}
