#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

class Polynomial {
    Node* head;
public:
    Polynomial() { head = NULL; }

    void addTerm(int c, int e) {
        Node* newNode = new Node{c, e, NULL};
        if (!head || head->exp < e) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->exp >= e) {
                temp = temp->next;
            }
            if (temp->exp == e) {
                temp->coeff += c;
                delete newNode;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial res;
        Node* t1 = p1.head;
        Node* t2 = p2.head;
        while (t1) {
            res.addTerm(t1->coeff, t1->exp);
            t1 = t1->next;
        }
        while (t2) {
            res.addTerm(t2->coeff, t2->exp);
            t2 = t2->next;
        }
        return res;
    }
};

int main() {
    Polynomial p1, p2;
    p1.addTerm(3, 2); p1.addTerm(5, 0);
    p2.addTerm(4, 2); p2.addTerm(1, 1);

    cout << "P1: "; p1.display();
    cout << "P2: "; p2.display();

    Polynomial p3 = Polynomial::add(p1, p2);
    cout << "Sum: "; p3.display();

    return 0;
}
