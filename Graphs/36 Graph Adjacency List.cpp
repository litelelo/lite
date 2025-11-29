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
    Graph g(4);
    g.addEdge(0, 1); g.addEdge(0, 2);
    g.addEdge(1, 2); g.addEdge(2, 0);
    g.addEdge(2, 3); g.addEdge(3, 3);
    g.BFS(2);
    return 0;
}
