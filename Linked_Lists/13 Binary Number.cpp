#include <iostream>
using namespace std;

struct Node {
    int bit;
    Node* next;
    Node* prev;
};

class BinaryNumber {
    Node* head;
    Node* tail;
public:
    BinaryNumber() { head = NULL; tail = NULL; }

    void addBit(int b) {
        Node* newNode = new Node{b, NULL, tail};
        if (tail) tail->next = newNode;
        else head = newNode;
        tail = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->bit;
            temp = temp->next;
        }
        cout << endl;
    }

    void onesComplement() {
        cout << "1's Complement: ";
        Node* temp = head;
        while (temp) {
            cout << (temp->bit == 0 ? 1 : 0);
            temp = temp->next;
        }
        cout << endl;
    }

    void twosComplement() {
        cout << "2's Complement: ";
        // Copy bits to array or new list to manipulate
        // Or traverse from tail
        Node* temp = tail;
        int carry = 1;
        int res[100], i = 0;
        
        while (temp) {
            int val = (temp->bit == 0 ? 1 : 0) + carry;
            if (val == 2) {
                res[i++] = 0;
                carry = 1;
            } else {
                res[i++] = val;
                carry = 0;
            }
            temp = temp->prev;
        }
        if (carry) res[i++] = 1;
        
        for (int j = i - 1; j >= 0; j--) cout << res[j];
        cout << endl;
    }
};

int main() {
    BinaryNumber bn;
    int n, bit;
    cout << "Enter number of bits: ";
    cin >> n;
    cout << "Enter bits: ";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        bn.addBit(bit);
    }

    cout << "Original: "; bn.display();
    bn.onesComplement();
    bn.twosComplement();

    return 0;
}
