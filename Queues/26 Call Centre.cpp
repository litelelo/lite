#include <iostream>
using namespace std;

struct Node {
    int callId;
    Node* next;
};

class CallCentre {
    Node *front, *rear;
public:
    CallCentre() { front = rear = NULL; }

    void enqueue(int id) {
        Node* temp = new Node{id, NULL};
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
        cout << "Call " << id << " received.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "System waiting for calls...\n";
            return;
        }
        Node* temp = front;
        cout << "Assisting call " << front->callId << endl;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }
};

int main() {
    CallCentre cc;
    cc.dequeue();
    cc.enqueue(101);
    cc.enqueue(102);
    cc.dequeue();
    cc.dequeue();
    cc.dequeue();
    return 0;
}
// Queue using linked list for call center management | Time: O(1)
