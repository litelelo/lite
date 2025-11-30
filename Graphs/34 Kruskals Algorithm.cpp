#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}

struct DSU {
    int parent[100];
    DSU(int n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

int main() {
    int V, e, u, v, w;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> e;
    
    vector<Edge> edges;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(V);
    int mst_weight = 0;
    cout << "\nEdges in MST:\n";
    for (int i = 0; i < edges.size(); i++) {
        Edge edge = edges[i];
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_weight += edge.w;
            cout << edge.u << " -- " << edge.v << " == " << edge.w << endl;
        }
    }
    cout << "Total Weight: " << mst_weight << endl;
    return 0;
}
// Kruskal's algorithm for MST using union-find (DSU) | Time: O(E log E)
