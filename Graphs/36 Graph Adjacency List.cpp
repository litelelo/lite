#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++) visited[i] = false;

        queue<int> q;
        visited[s] = true;
        q.push(s);

        cout << "BFS: ";
        while(!q.empty()) {
            s = q.front();
            cout << s << " ";
            q.pop();

            for(auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if(!visited[*i]) {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int V, e, u, v, start;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    Graph g(V);
    
    cout << "Enter number of edges: ";
    cin >> e;
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    cout << "Enter start vertex for BFS: ";
    cin >> start;
    
    g.BFS(start);
    return 0;
}
// Graph BFS traversal using adjacency list representation | Time: O(V+E)
