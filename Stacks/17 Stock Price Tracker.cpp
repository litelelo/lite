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
    st.record(100);
    st.record(105);
    cout << "Latest: " << st.latest() << endl;
    st.remove();
    cout << "Latest after remove: " << st.latest() << endl;
    return 0;
}
