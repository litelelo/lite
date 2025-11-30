#include <iostream>
using namespace std;

class PizzaParlour {
    int *orders;
    int front, rear, maxSize;
public:
    PizzaParlour(int size) {
        maxSize = size;
        orders = new int[maxSize];
        front = -1;
        rear = -1;
    }

    void placeOrder(int id) {
        if ((front == 0 && rear == maxSize - 1) || (rear == (front - 1) % (maxSize - 1))) {
            cout << "Orders Full\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == maxSize - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        orders[rear] = id;
        cout << "Order " << id << " placed.\n";
    }

    void serveOrder() {
        if (front == -1) {
            cout << "No orders.\n";
            return;
        }
        cout << "Order " << orders[front] << " served.\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == maxSize - 1) {
            front = 0;
        } else {
            front++;
        }
    }
};

int main() {
    int size, choice, orderId;
    
    cout << "Enter queue size: ";
    cin >> size;
    PizzaParlour p(size);
    
    while (true) {
        cout << "\n1. Place Order\n2. Serve Order\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter order ID: ";
            cin >> orderId;
            p.placeOrder(orderId);
        } else if (choice == 2) {
            p.serveOrder();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Circular queue for pizza order management (FCFS) | Time: O(1)
