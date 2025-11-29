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

    void insert(int val) {
        Node* newNode = new Node{val, NULL, NULL};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void bubbleSort() {
        if (!head) return;
        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
};

int main() {
    DLL list;
    list.insert(5); list.insert(3); list.insert(8); list.insert(1);
    cout << "Original: "; list.display();
    list.bubbleSort();
    cout << "Sorted: "; list.display();
    return 0;
}
