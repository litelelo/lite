#include <iostream>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

Node* adjList[20];
int visited[20], dist[20], parent[20];
int v, e;

void createAdjList() {
    int i, a, b, w;
    
    cout << "\nEnter graph details:\n";
    cout << "  Number of vertices: ";
    cin >> v;
    cout << "  Number of edges: ";
    cin >> e;
    
    // Initialize adjacency list
    for(i = 1; i <= v; i++) {
        adjList[i] = NULL;
        dist[i] = 32767;    // Initialize distances to INFINITY
        visited[i] = 0;     // Mark all vertices as unvisited
        parent[i] = 0;      // Initialize parent array
    }
    
    // Input edges
    for(i = 1; i <= e; i++) {
        cout << "\nEnter edge " << i << ":\n";
        cout << "  Vertex A: ";
        cin >> a;
        cout << "  Vertex B: ";
        cin >> b;
        cout << "Weight of edge: ";
        cin >> w;
        
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
    for(i = 1; i <= v; i++) {
        cout << "Vertex " << i << ": ";
        temp = adjList[i];
        while(temp != NULL) {
            cout << temp->vertex << "(" << temp->weight << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

void dijkstra() {
    int source, target;
    int current, i, mindist;
    Node* temp;
    
    cout << "\nEnter source vertex: ";
    cin >> source;
    cout << "Enter target vertex: ";
    cin >> target;
    
    // Initialize source distance to 0
    dist[source] = 0;
    current = source;
    
    while(current != target && current != 0) {
        visited[current] = 1;
        temp = adjList[current];
        
        // Update distances of all adjacent vertices
        while(temp != NULL) {
            if(!visited[temp->vertex]) {
                if(dist[temp->vertex] > dist[current] + temp->weight) {
                    dist[temp->vertex] = dist[current] + temp->weight;
                    parent[temp->vertex] = current;
                }
            }
            temp = temp->next;
        }
        
        // Find unvisited vertex with minimum distance
        mindist = 32767;
        current = 0;
        for(i = 1; i <= v; i++) {
            if(!visited[i] && dist[i] < mindist) {
                mindist = dist[i];
                current = i;
            }
        }
    }
    
    if(current == target) {
        cout << "\nShortest distance from " << source << " to " << target << " is: " << dist[target];
        
        // Print the path
        cout << "\nPath: ";
        int path[20], count = 0;
        current = target;
        
        while(current != source) {
            path[count++] = current;
            current = parent[current];
        }
        path[count] = source;
        
        for(i = count; i >= 0; i--) {
            cout << path[i];
            if(i > 0) cout << " -> ";
        }
        cout << endl;
    }
    else {
        cout << "\nNo path exists to target vertex!" << endl;
    }
}

int main() {
    int choice;
    
    createAdjList();
    
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Display Adjacency List\n";
        cout << "2. Find Shortest Path using Dijkstra's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                displayAdjList();
                break;
                
            case 2:
                dijkstra();
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
// Dijkstra's algorithm for shortest path | Time: O(V²) | Space: O(V)