#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string callerName;
    Node *next;

    Node(string name) {
        callerName = name;
        next = NULL;
    }
};


class CallQueue {
    Node *front;
    Node *rear;

public:
    CallQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    
    void enqueue(string name) {
        Node *temp = new Node(name);

        if (rear == NULL) {
            front = rear = temp;
            cout << "Call received from: " << name << "\n";
            return;
        }

        rear->next = temp;
        rear = temp;
        cout << "Call received from: " << name << "\n";
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "No calls in queue... Waiting for calls.\n";
            return;
        }

        Node *temp = front;
        cout << "Agent is now handling call from: " << temp->callerName << "\n";

        front = front->next;
        if (front == NULL)
            rear = NULL;

        delete temp;
    }


    void display() {
        if (isEmpty()) {
            cout << "No calls waiting.\n";
            return;
        }

        cout << "\nCalls waiting in queue:\n";
        Node *t = front;
        while (t != NULL) {
            cout << " - " << t->callerName << "\n";
            t = t->next;
        }
    }
};

string inputLine() {
    string s;
    cin >> ws;
    getline(cin, s);
    return s;
}

int main() {
    CallQueue cq;
    int choice;

    do {
        cout << "\n=== Call Center Queue System ===\n";
        cout << "1. Receive new call (Enqueue)\n";
        cout << "2. Assign call to agent (Dequeue)\n";
        cout << "3. Display waiting calls\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter caller name: ";
            string name = inputLine();
            cq.enqueue(name);

        } else if (choice == 2) {
            cq.dequeue();

        } else if (choice == 3) {
            cq.display();
        }

    } while (choice != 0);

    return 0;
}
