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
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(V);
    int mst_weight = 0;
    cout << "Edges in MST:\n";
    for (Edge e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mst_weight += e.w;
            cout << e.u << " -- " << e.v << " == " << e.w << endl;
        }
    }
    cout << "Total Weight: " << mst_weight << endl;
    return 0;
}
// Kruskal's algorithm for MST using union-find (DSU) | Time: O(E log E)
