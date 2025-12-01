#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

Node* adjList[20];
int visited[20];
int v, e;

void createAdjList() {
    int i, a, b;
    
    cout << "\nEnter graph details:\n";
    cout << "  Number of vertices: ";
    cin >> v;
    cout << "  Number of edges: ";
    cin >> e;
    
    // Initialize adjacency list
    for(i = 1; i <= v; i++) {
        adjList[i] = NULL;
    }
    
    // Input edges
    for(i = 1; i <= e; i++) {
        cout << "\nEnter edge " << i << ":\n";
        cout << "  Vertex A: ";
        cin >> a;
        cout << "  Vertex B: ";
        cin >> b;
        
        // Add edge from a to b
        Node* newNode = new Node;
        newNode->vertex = b;
        newNode->next = adjList[a];
        adjList[a] = newNode;
        
        // Add edge from b to a (undirected graph)
        newNode = new Node;
        newNode->vertex = a;
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
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

void BFS(int start) {
    int queue[20], front = 0, rear = 0;
    Node* temp;
    
    // Initialize visited array
    for(int i = 1; i <= v; i++)
        visited[i] = 0;
    
    // Start BFS
    cout << "\nBFS starting from vertex " << start << ": ";
    queue[rear++] = start;
    visited[start] = 1;
    
    while(front < rear) {
        int current = queue[front++];
        cout << current << " ";
        
        temp = adjList[current];
        while(temp != NULL) {
            if(!visited[temp->vertex]) {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

void DFS(int vertex) {
    Node* temp;
    
    visited[vertex] = 1;
    cout << vertex << " ";
    
    temp = adjList[vertex];
    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

void DFSTraversal(int start) {
    // Initialize visited array
    for(int i = 1; i <= v; i++)
        visited[i] = 0;
    
    cout << "\nDFS starting from vertex " << start << ": ";
    DFS(start);
    cout << endl;
}

int main() {
    int choice, start;
    
    createAdjList();
    
    do {
        cout << "\n=== Graph Traversal Menu ===\n";
        cout << "1. Display Adjacency List\n";
        cout << "2. BFS Traversal\n";
        cout << "3. DFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                displayAdjList();
                break;
                
            case 2:
                cout << "Enter starting vertex: ";
                cin >> start;
                BFS(start);
                break;
                
            case 3:
                cout << "Enter starting vertex: ";
                cin >> start;
                DFSTraversal(start);
                break;
                
            case 4:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);
    
    return 0;
}
// Graph using adjacency list with BFS & DFS traversal | Time: O(V+E) | Space: O(V+E)