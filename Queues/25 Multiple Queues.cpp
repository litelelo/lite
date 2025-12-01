#include <iostream>
using namespace std;

const int SIZE = 10;
int arr[SIZE];
int front1 = -1, rear1 = -1;
int front2 = SIZE, rear2 = SIZE;

void enqueue1() {
    if (rear1 + 1 == rear2) {
        cout << "\nError: Queue 1 Overflow!!" << endl;
    } else {
        int val;
        cout << "\nEnter a number to enqueue in queue 1: ";
        cin >> val;
        if (front1 == -1) front1 = rear1 = 0;
        else rear1++;
        arr[rear1] = val;
    }
}

void enqueue2() {
    if (rear2 - 1 == rear1) {
        cout << "\nError: Queue 2 Overflow!!" << endl;
    } else {
        int val;
        cout << "\nEnter a number to enqueue in queue 2: ";
        cin >> val;
        if (front2 == SIZE) front2 = rear2 = SIZE - 1;
        else rear2--;
        arr[rear2] = val;
    }
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        cout << "\nError: Queue 1 Underflow!!" << endl;
    } else {
        cout << "\nNumber dequeued from queue 1: " << arr[front1++] << endl;
        if (front1 > rear1) front1 = rear1 = -1;
    }
}

void dequeue2() {
    if (front2 == SIZE || front2 < rear2) {
        cout << "\nError: Queue 2 Underflow!!" << endl;
    } else {
        cout << "\nNumber dequeued from queue 2: " << arr[front2--] << endl;
        if (front2 < rear2) front2 = rear2 = SIZE;
    }
}

void display() {
    cout << "\nQueue 1: ";
    if (front1 == -1 || front1 > rear1) cout << "Empty";
    else for (int i = front1; i <= rear1; i++) cout << arr[i] << " ";
    cout << "\nQueue 2: ";
    if (front2 == SIZE || front2 < rear2) cout << "Empty";
    else for (int i = front2; i >= rear2; i--) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n=== Multi-Queue Menu ===" << endl;
        cout << "1. Enqueue Queue 1" << endl;
        cout << "2. Enqueue Queue 2" << endl;
        cout << "3. Dequeue Queue 1" << endl;
        cout << "4. Dequeue Queue 2" << endl;
        cout << "5. Display Both Queues" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: enqueue1(); break;
            case 2: enqueue2(); break;
            case 3: dequeue1(); break;
            case 4: dequeue2(); break;
            case 5: display(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);
    return 0;
}
// Two circular queues (normal & VIP) in single array | Operations: enqueue, dequeue, display | Time: O(1) | Space: O(n)
