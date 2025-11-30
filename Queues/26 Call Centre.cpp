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
    int choice, callId;
    
    while (true) {
        cout << "\n1. Receive Call\n2. Assist Call\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter call ID: ";
            cin >> callId;
            cc.enqueue(callId);
        } else if (choice == 2) {
            cc.dequeue();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Queue using linked list for call center management | Time: O(1)
