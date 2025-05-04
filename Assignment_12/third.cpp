#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 100

class Edge {
public:
    int src, dest, weight;
};

class Graph {
private:
    int numVertices;
    int adjMatrix[MAX][MAX];

public:
    Graph(int vertices) {
        if (vertices <= 0 || vertices > MAX) {
            cout << "Invalid number of vertices. Setting to 0." << endl;
            numVertices = 0;
        } else {
            numVertices = vertices;
        }
        // Initialize adjacency matrix
        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = 0;
    }

    void addEdge(int src, int dest, int weight) {
        if (isValidVertex(src) && isValidVertex(dest) && weight >= 0) {
            adjMatrix[src][dest] = weight;
            adjMatrix[dest][src] = weight; // undirected
            cout << "Edge added between " << src << " and " << dest << " with weight " << weight << "." << endl;
        }
    }

    void display() {
        cout << "Adjacency Matrix (0 means no edge):" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void primMST() {
        vector<int> key(numVertices, INT_MAX);
        vector<bool> mstSet(numVertices, false);
        vector<int> parent(numVertices, -1);

        key[0] = 0;

        for (int count = 0; count < numVertices - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < numVertices; v++) {
                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        cout << "Prim's MST edges (u - v : weight):" << endl;
        int totalWeight = 0;
        for (int i = 1; i < numVertices; i++) {
            cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << endl;
            totalWeight += adjMatrix[i][parent[i]];
        }
        cout << "Total weight: " << totalWeight << endl;
    }

    void kruskalMST() {
        vector<Edge> edges;

        // collect all edges
        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {
                if (adjMatrix[i][j]) {
                    edges.push_back({i, j, adjMatrix[i][j]});
                }
            }
        }

        // sort edges by weight
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(numVertices);
        for (int i = 0; i < numVertices; i++) parent[i] = i;

        int totalWeight = 0;
        cout << "Kruskal's MST edges (u - v : weight):" << endl;

        for (Edge e : edges) {
            int uRoot = find(parent, e.src);
            int vRoot = find(parent, e.dest);
            if (uRoot != vRoot) {
                cout << e.src << " - " << e.dest << " : " << e.weight << endl;
                totalWeight += e.weight;
                parent[uRoot] = vRoot;
            }
        }
        cout << "Total weight: " << totalWeight << endl;
    }

    void dijkstra(int src) {
        if (!isValidVertex(src)) return;

        vector<int> dist(numVertices, INT_MAX);
        vector<bool> sptSet(numVertices, false);

        dist[src] = 0;

        for (int count = 0; count < numVertices - 1; count++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < numVertices; v++) {
                if (!sptSet[v] && adjMatrix[u][v] &&
                    dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        cout << "Dijkstra's shortest distances from node " << src << ":" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "To " << i << " : " << dist[i] << endl;
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

    int minKey(vector<int>& key, vector<bool>& mstSet) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < numVertices; v++)
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        return min_index;
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    int minDistance(vector<int>& dist, vector<bool>& sptSet) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < numVertices; v++)
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        return min_index;
    }
};

int main() {
    int vertices, choice, src, dest, weight;

    cout << "Enter number of vertices in the graph (max " << MAX << "): ";
    cin >> vertices;

    Graph g(vertices);

    while (true) {
        cout << "\n--- Graph ADT Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra's Shortest Path\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source, destination, weight: ";
            cin >> src >> dest >> weight;
            g.addEdge(src, dest, weight);
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.primMST();
            break;
        case 4:
            g.kruskalMST();
            break;
        case 5:
            cout << "Enter source vertex for Dijkstra's: ";
            cin >> src;
            g.dijkstra(src);
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter 1-6." << endl;
        }
    }

    return 0;
}
