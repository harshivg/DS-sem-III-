#include <iostream>
#include <vector>

using namespace std;

// Define a class to represent a graph
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    // Constructor to initialize the graph with V vertices
    Graph(int V) : V(V), adj(V) {}

    // Function to add an edge between two vertices
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph, add an edge in both directions
    }

    // Function to print the graph
    void printGraph() {
        for (int v = 0; v < V; v++) {
            cout << "Vertex " << v << " is connected to: ";
            for (int u : adj[v]) {
                cout << u << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    int V = 5;
    Graph graph(V);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);

    // Print the graph
    graph.printGraph();

    return 0;
}