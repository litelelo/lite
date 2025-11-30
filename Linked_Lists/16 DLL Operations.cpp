#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DLL {
    Node* head;
public:
    DLL() { head = NULL; }

    void insertFront(int val) {
        Node* newNode = new Node{val, head, NULL};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertEnd(int val) {
        if (!head) { insertFront(val); return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        Node* newNode = new Node{val, NULL, temp};
        temp->next = newNode;
    }

    void deleteFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = NULL;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DLL list;
    list.insertFront(10);
    list.insertEnd(20);
    list.insertFront(5);
    list.display();
    list.deleteFront();
    list.display();
    list.deleteEnd();
    list.display();
    return 0;
}
// Doubly linked list with insert/delete at front and end | Time: O(n)
