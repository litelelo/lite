#include <iostream>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Node {
    int vertex;
    int weight;
    Node* next;
};

Node* adjList[20];
Edge edges[100];
int parent[20];
int vertices, edgesCount;  // renamed from v, e for clarity

void createAdjList() {
    int i, a, b, w;
    
    cout << "\nEnter graph details:\n";
    cout << "  Number of vertices: ";
    cin >> vertices;
    cout << "  Number of edges: ";
    cin >> edgesCount;
    
    // Initialize adjacency list
    for(i = 1; i <= vertices; i++) {
        adjList[i] = NULL;
    }
    
    // Input edges
    for(i = 0; i < edgesCount; i++) {
        cout << "\nEnter edge " << i+1 << ":\n  Vertex A: ";
        cin >> a;
        cout << "  Vertex B: ";
        cin >> b;
        cout << "  Weight of the edge: ";
        cin >> w;
        
        // Store edge for Kruskal's algorithm
        edges[i].src = a;
        edges[i].dest = b;
        edges[i].weight = w;
        
        // Add edge from a to b
        Node* newNode = new Node;
        newNode->vertex = b;
        newNode->weight = w;
        newNode->next = adjList[a];
        adjList[a] = newNode;
        
        // Add edge from b to a (undirected graph)
        newNode = new Node;
        newNode->vertex = a;
        newNode->weight = w;
        newNode->next = adjList[b];
        adjList[b] = newNode;
    }
}

void displayAdjList() {
    int i;
    Node* temp;
    
    cout << "\nAdjacency List:\n";
    for(i = 1; i <= vertices; i++) {
        cout << "Vertex " << i << ": ";
        temp = adjList[i];
        while(temp != NULL) {
            cout << temp->vertex << "(" << temp->weight << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

void sortEdges() {
    int i, j;
    Edge temp;
    
    for(i = 0; i < edgesCount - 1; i++) {
        for(j = 0; j < edgesCount - i - 1; j++) {
            if(edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int findParent(int vertex) {
    if(parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = findParent(parent[vertex]);  // Path compression
}

void kruskal() {
    int i, edgeCount = 0, mincost = 0;
    int u, vtx;
    
    // Initialize parent array - each vertex is its own parent
    for(i = 1; i <= vertices; i++)
        parent[i] = i;
    
    // Sort edges by weight
    sortEdges();
    
    cout << "\nEdges in MST:\n";
    
    // Process edges in sorted order
    for(i = 0; i < edgesCount && edgeCount < vertices - 1; i++) {
        u = edges[i].src;
        vtx = edges[i].dest;
        
        // Find parents with path compression
        int setU = findParent(u);
        int setV = findParent(vtx);
        
        // If including this edge doesn't form a cycle
        if(setU != setV) {
            cout << "Edge: " << u << " - " << vtx << " (Weight: " << edges[i].weight << ")\n";
            mincost += edges[i].weight;
            parent[setU] = setV;  // Union
            edgeCount++;
        }
    }
    
    if(edgeCount != vertices - 1)
        cout << "\nWarning: Could not form a spanning tree!" << endl;
    else
        cout << "\nMinimum cost of spanning tree = " << mincost << endl;
}

int main() {
    int choice;
    
    createAdjList();
    
    do {
        cout << "\n\n=== Menu ===\n";
        cout << "1. Display Adjacency List\n";
        cout << "2. Find MST using Kruskal's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                displayAdjList();
                break;
                
            case 2:
                kruskal();
                break;
                
            case 3:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 3);
    
    return 0;
}
// Kruskal's algorithm for MST using Union-Find | Time: O(E log E) | Space: O(V+E)
