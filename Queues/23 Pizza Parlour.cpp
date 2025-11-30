#include <iostream>
#define MAX 5
using namespace std;

class PizzaParlour {
    int orders[MAX];
    int front, rear;
public:
    PizzaParlour() { front = -1; rear = -1; }

    void placeOrder(int id) {
        if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
            cout << "Orders Full\n";
            return;
        }
        if (front == -1) { front = 0; rear = 0; }
        else if (rear == MAX - 1 && front != 0) rear = 0;
        else rear++;
        orders[rear] = id;
        cout << "Order " << id << " placed.\n";
    }

    void serveOrder() {
        if (front == -1) {
            cout << "No orders.\n";
            return;
        }
        cout << "Order " << orders[front] << " served.\n";
        if (front == rear) { front = -1; rear = -1; }
        else if (front == MAX - 1) front = 0;
        else front++;
    }
};

int main() {
    PizzaParlour p;
    p.placeOrder(101);
    p.placeOrder(102);
    p.serveOrder();
    p.placeOrder(103);
    return 0;
}
// Circular queue for pizza order management (FCFS) | Time: O(1)
