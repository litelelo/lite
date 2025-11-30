#include <iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
};

class Queue {
    QNode *front, *rear;
public:
    Queue() { front = rear = NULL; }
    void push(int val) { QNode* t = new QNode{val, NULL}; if(rear) rear->next = t; else front = t; rear = t; }
    void pop() { if(front) { QNode* t = front; front = front->next; if(!front) rear = NULL; delete t; } }
    int getFront() { return front ? front->data : -1; }
    bool empty() { return front == NULL; }
};

struct StackNode {
    int data;
    StackNode* next;
};

class Stack {
    StackNode* top;
public:
    Stack() { top = NULL; }
    void push(int val) { StackNode* t = new StackNode{val, top}; top = t; }
    void pop() { if(top) { StackNode* t = top; top = top->next; delete t; } }
    int getTop() { return top ? top->data : -1; }
    bool empty() { return top == NULL; }
};

class Graph {
    int adj[10][10];
    int n;
public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void BFS(int start) {
        bool visited[10] = {false};
        Queue q;
        visited[start] = true;
        q.push(start);

        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.getFront();
            q.pop();
            cout << u << " ";
            for (int v = 0; v < n; v++) {
                if (adj[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        bool visited[10] = {false};
        Stack s;
        s.push(start);

        cout << "DFS: ";
        while (!s.empty()) {
            int u = s.getTop();
            s.pop();
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";
                for (int v = n - 1; v >= 0; v--) {
                    if (adj[u][v] && !visited[v]) {
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n, e, u, v, start;
    cout << "Enter number of nodes: ";
    cin >> n;
    Graph g(n);
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Enter start node: ";
    cin >> start;
    g.BFS(start);
    g.DFS(start);
    return 0;
}
// Graph BFS and DFS traversal using adjacency matrix | Time: O(V²)
