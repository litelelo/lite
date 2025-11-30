#include <iostream>
#include <climits>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int **graph, int src, int V) {
    int *dist = new int[V];
    bool *sptSet = new bool[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nVertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int V, e, u, v, w, src;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    int **graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    
    cout << "Enter number of edges: ";
    cin >> e;
    
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    cout << "Enter source vertex: ";
    cin >> src;
    
    dijkstra(graph, src, V);
    return 0;
}
// Dijkstra's shortest path algorithm using adjacency matrix | Time: O(V²)
