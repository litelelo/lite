#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int adj[10][10];
    int n;
public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void BFS(int start) {
        bool visited[10] = {false};
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v = 0; v < n; v++) {
                if (adj[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        bool visited[10] = {false};
        stack<int> s;
        s.push(start);

        cout << "DFS: ";
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";
                for (int v = n - 1; v >= 0; v--) {
                    if (adj[u][v] && !visited[v]) {
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n = 5;
    Graph g(n);
    g.addEdge(0, 1); g.addEdge(0, 2);
    g.addEdge(1, 3); g.addEdge(1, 4);
    g.BFS(0);
    g.DFS(0);
    return 0;
}
