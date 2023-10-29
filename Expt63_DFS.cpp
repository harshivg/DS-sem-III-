#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    void depthFirstTraversal(int startVertex) {
        vector<bool> visited(V, false);

        dfs(startVertex, visited);
    }
};

int main() {
    int V = 6;
    Graph graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);

    cout << "Depth-First Traversal starting from vertex 0: ";
    graph.depthFirstTraversal(0);
    cout << endl;

    return 0;
}
