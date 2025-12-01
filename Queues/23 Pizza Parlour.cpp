#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;
struct order {
    string name;
    float price;
};

struct queue{
    order queue[SIZE];
    int front, rear;
} q = { {}, -1, -1 };

bool isFull(){
    if(q.front == (q.rear+1)%SIZE) return true; 
    else return false;
}

bool isEmpty(){
    if(q.front == -1) return true; 
    else return false;
}

void enqueue(){
    if(isFull()) {
        cout << "\nWe are not accepting orders at the moment! Try again in some time!";
        return;
    }
    order o;
    cout << "Enter pizza name: ";
    cin.ignore();
    getline(cin, o.name);
    cout << "Enter price: ";
    cin >> o.price;
    if(isEmpty()) {
        q.rear = q.front = 0;
        q.queue[q.rear] = o;
    }
    else{
        q.rear = (q.rear+1)%SIZE;
        q.queue[q.rear] = o;
    }
}

void dequeue(){
    if(isEmpty()) cout << "\nThere are no orders to dequeue!";
    else{
        order o = q.queue[q.front];
        if(q.front == q.rear) q.front = q.rear = -1;
        else q.front = (q.front+1)%SIZE;

        cout << "\nDequeued order: " << o.name << " | Price: Rs. " << o.price;
    }
}

void display(){
    if(isEmpty()){
        cout << "\nThere are no orders to display!";
        return;
    } 
    else {
        cout << "\nOrders in queue: " << endl;
        if(q.rear>=q.front)
            for(int i=q.front; i<=q.rear; i++)
                cout << "\t" << q.queue[i].name << " | Price: Rs. " << q.queue[i].price << endl;
        else {
            for(int i=q.front; i<SIZE; i++)
                cout << "\t" << q.queue[i].name << " | Price: Rs. " << q.queue[i].price << endl;
            for(int i=0; i<=q.rear; i++)
                cout << "\t" << q.queue[i].name << " | Price: Rs. " << q.queue[i].price << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Pizza Parlour Menu ---" << endl;
        cout << "1. Place Order (Enqueue)" << endl;
        cout << "2. Serve Order (Dequeue)" << endl;
        cout << "3. Display Orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);
    return 0;
}
// Circular queue for pizza order management | Operations: place order, serve order, display orders | Time: O(1) | Space: O(n)