#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class PassengerQueue {
    string q[MAX];
    int front, rear;
public:
    PassengerQueue() { front = -1; rear = -1; }

    void insert(string name) {
        if (rear == MAX - 1) return;
        if (front == -1) front = 0;
        q[++rear] = name;
    }

    void remove() {
        if (front == -1 || front > rear) return;
        cout << "Removed: " << q[front++] << endl;
    }

    void displayFront() {
        if (front == -1 || front > rear) cout << "Empty\n";
        else cout << "Front: " << q[front] << endl;
    }

    int count() {
        if (front == -1 || front > rear) return 0;
        return rear - front + 1;
    }
};

int main() {
    PassengerQueue pq;
    int ch;
    string name;
    do {
        cout << "1. Insert 2. Remove 3. Front 4. Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> name; pq.insert(name); }
        else if (ch == 2) pq.remove();
        else if (ch == 3) pq.displayFront();
    } while (ch != 4);
    cout << "Passengers left: " << pq.count() << endl;
    return 0;
}
// Linear queue for passenger ticket management | Time: O(1)
