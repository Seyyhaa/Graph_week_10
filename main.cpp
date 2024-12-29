#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Assuming an undirected graph
    }

    void display() {
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void dfsRecursive(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    void dfsIterative(int start) {
        vector<bool> visited(adjList.size(), false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;

                for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
    }

    void bfs(int start) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

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
