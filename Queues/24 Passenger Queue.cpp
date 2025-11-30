#include <iostream>
#include <string>
using namespace std;

class PassengerQueue {
    string *q;
    int front, rear, maxSize;
public:
    PassengerQueue(int size) {
        maxSize = size;
        q = new string[maxSize];
        front = -1;
        rear = -1;
    }

    void insert(string name) {
        if (rear == maxSize - 1) {
            cout << "Queue Full!\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        q[++rear] = name;
        cout << "Passenger " << name << " added.\n";
    }

    void remove() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Removed: " << q[front++] << endl;
    }

    void displayFront() {
        if (front == -1 || front > rear) {
            cout << "Empty\n";
        } else {
            cout << "Front: " << q[front] << endl;
        }
    }

    int count() {
        if (front == -1 || front > rear) {
            return 0;
        }
        return rear - front + 1;
    }
};

int main() {
    int size, choice;
    string name;
    
    cout << "Enter queue size: ";
    cin >> size;
    PassengerQueue pq(size);
    
    while (true) {
        cout << "\n1. Insert\n2. Remove\n3. Display Front\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter passenger name: ";
            cin >> name;
            pq.insert(name);
        } else if (choice == 2) {
            pq.remove();
        } else if (choice == 3) {
            pq.displayFront();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    cout << "Passengers left: " << pq.count() << endl;
    return 0;
}
// Linear queue for passenger ticket management | Time: O(1)
