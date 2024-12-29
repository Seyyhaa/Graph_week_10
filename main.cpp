#include <iostream>
#include "Graph.h"
int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    cout << "Graph Representation (Adjacency List):" << endl;
    graph.display();

    cout << "\nDFS (Recursive) starting from vertex 0: ";
    vector<bool> visited(5, false);
    graph.dfsRecursive(0, visited);

    cout << "\nDFS (Iterative) starting from vertex 0: ";
    graph.dfsIterative(0);

    cout << "\nBFS starting from vertex 0: ";
    graph.bfs(0);

    return 0;
}
