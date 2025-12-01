#include <iostream>
using namespace std;

int adj[20][20], visited[20];
int v, e;

void creategraph(){
    int i, j, a, b;
    cout << "\nEnter graph details:\n";
    cout << "Number of vertices: ";
    cin >> v;
    cout << "Number of edges: ";
    cin >> e;
    
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++)
            adj[i][j] = 0;
    }
    
    for(i = 1; i <= e; i++){
        cout << "\nEnter edge " << i << ":\n";
        cout << "  Vertex A: ";
        cin >> a;
        cout << "  Vertex B: ";
        cin >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
}

void displayMatrix(){
    int i, j;
    cout << "\nAdjacency Matrix:\n";
    cout << "   ";
    for(i = 1; i <= v; i++)
        cout << i << " ";
    cout << endl;
    
    for(i = 1; i <= v; i++){
        cout << i << "  ";
        for(j = 1; j <= v; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void BFS(int start){
    int queue[20], front = 0, rear = 0;
    int current, i;
    
    for(i = 1; i <= v; i++)
        visited[i] = 0;
    
    cout << "\nBFS Traversal: ";
    queue[rear++] = start;
    visited[start] = 1;
    
    while(front < rear){
        current = queue[front++];
        cout << current << " ";
        
        for(i = 1; i <= v; i++){
            if(adj[current][i] == 1 && visited[i] == 0){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void DFS(int vertex){
    int i;
    cout << vertex << " ";
    visited[vertex] = 1;
    
    for(i = 1; i <= v; i++){
        if(adj[vertex][i] == 1 && visited[i] == 0){
            DFS(i);
        }
    }
}

void DFSTraversal(int start){
    int i;
    for(i = 1; i <= v; i++)
        visited[i] = 0;
    
    cout << "\nDFS Traversal: ";
    DFS(start);
    cout << endl;
}

int main(){
    int choice, start;
    
    creategraph();
    
    do{
        cout << "\n=== Graph Traversal Menu ===\n";
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. BFS Traversal\n";
        cout << "3. DFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                displayMatrix();
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
    }while(choice != 4);
    
    return 0;
}
// Graph BFS & DFS traversal using adjacency matrix | Time: O(V²) | Space: O(V)