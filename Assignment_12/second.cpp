#include <iostream>
#include <list>
using namespace std;

#define MAX 100  // maximum number of vertices

class Graph {
private:
    list<int> *adj;  // array of adjacency lists
    int numVertices;

public:
    Graph(int vertices) {
        if (vertices > MAX || vertices <= 0) {
            cout << "Invalid number of vertices. Setting to 0." << endl;
            numVertices = 0;
        } else {
            numVertices = vertices;
        }
        adj = new list<int>[numVertices];
    }

    ~Graph() {
        delete[] adj;
    }

    void insertEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            // check if edge already exists
            if (!edgeExists(src, dest)) {
                adj[src].push_back(dest);
                adj[dest].push_back(src);  // assuming undirected graph
                cout << "Edge inserted between " << src << " and " << dest << "." << endl;
            } else {
                cout << "Edge already exists between " << src << " and " << dest << "." << endl;
            }
        }
    }

    void deleteEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            if (edgeExists(src, dest)) {
                adj[src].remove(dest);
                adj[dest].remove(src);  // assuming undirected graph
                cout << "Edge deleted between " << src << " and " << dest << "." << endl;
            } else {
                cout << "No edge exists between " << src << " and " << dest << "." << endl;
            }
        }
    }

    void searchEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            if (edgeExists(src, dest)) {
                cout << "Edge exists between " << src << " and " << dest << "." << endl;
            } else {
                cout << "No edge between " << src << " and " << dest << "." << endl;
            }
        }
    }

    void displayGraph() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << " -> ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
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

    bool edgeExists(int src, int dest) {
        for (int neighbor : adj[src]) {
            if (neighbor == dest) return true;
        }
        return false;
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
