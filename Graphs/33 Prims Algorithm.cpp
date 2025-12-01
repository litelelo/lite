#include <iostream>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

Node* adjList[20];
int visited[20], d[20], p[20];
int v, e;

void createAdjList() {
    int i, a, b, w;
    
    cout << "\nEnter graph details:\n";
    cout << "  Number of vertices: ";
    cin >> v;
    cout << "  Number of edges: ";
    cin >> e;
    
    for(i = 1; i <= v; i++) {
        adjList[i] = NULL;
    }
    
    for(i = 1; i <= v; i++) {
        p[i] = visited[i] = 0;
        d[i] = 32767;
    }
    
    for(i = 1; i <= e; i++) {
        cout << "\nEnter the two vertices between which the edge has been formed:\n  Vertex A: ";
        cin >> a;
        cout << "  Vertex B: ";
        cin >> b;
        cout << "Weight of the edge: ";
        cin >> w;
        
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

void prim() {
    int current, totalvisited, mincost, i;
    Node* temp;
    
    current = 1;
    d[current] = 0;
    totalvisited = 1;
    visited[current] = 1;
    
    while(totalvisited != v) {
        temp = adjList[current];
        while(temp != NULL) {
            if(visited[temp->vertex] == 0) {
                if(d[temp->vertex] > temp->weight) {
                    d[temp->vertex] = temp->weight;
                    p[temp->vertex] = current;
                }
            }
            temp = temp->next;
        }
        
        mincost = 32767;
        for(i = 1; i <= v; i++) {
            if(visited[i] == 0) {
                if(d[i] < mincost) {
                    mincost = d[i];
                    current = i;
                }
            }
        }
        visited[current] = 1;
        totalvisited++;
    }
    
    mincost = 0;
    for(i = 1; i <= v; i++)
        mincost += d[i];
    
    cout << "\nMinimum cost = " << mincost;
    cout << "\nMinimum span tree is:";
    for(i = 1; i <= v; i++)
        cout << "\nVertex " << i << " is connected to " << p[i];
}

int main() {
    int choice;
    
    createAdjList();
    
    do {
        cout << "\n\n=== Menu ===\n";
        cout << "1. Display Adjacency List\n";
        cout << "2. Find MST using Prim's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                displayAdjList();
                break;
                
            case 2:
                prim();
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
// Prim's algorithm for Minimum Spanning Tree | Time: O(V²) | Space: O(V)