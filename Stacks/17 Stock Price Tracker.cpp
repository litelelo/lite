#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* next;
};

class StockTracker {
    Node* top;
public:
    StockTracker() { top = NULL; }

    void record(int price) {
        Node* newNode = new Node{price, top};
        top = newNode;
    }

    int remove() {
        if (isEmpty()) return -1;
        int price = top->price;
        Node* temp = top;
        top = top->next;
        delete temp;
        return price;
    }

    int latest() {
        if (isEmpty()) return -1;
        return top->price;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    StockTracker st;
    int choice, price;
    
    while (true) {
        cout << "\n1. Record Price\n2. Remove Latest\n3. View Latest\n4. Check if Empty\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter stock price: ";
            cin >> price;
            st.record(price);
            cout << "Price recorded.\n";
        } else if (choice == 2) {
            price = st.remove();
            if (price != -1) {
                cout << "Removed price: " << price << endl;
            } else {
                cout << "Stack is empty!\n";
            }
        } else if (choice == 3) {
            price = st.latest();
            if (price != -1) {
                cout << "Latest price: " << price << endl;
            } else {
                cout << "Stack is empty!\n";
            }
        } else if (choice == 4) {
            if (st.isEmpty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Stack is not empty.\n";
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Stack using linked list for stock price tracking (LIFO) | Time: O(1)
