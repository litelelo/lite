#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

class VertexClub {
    Node* head;
public:
    VertexClub() { head = NULL; }

    void addMember(int prn, string name) {
        Node* newNode = new Node{prn, name, NULL};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void addPresident(int prn, string name) {
        Node* newNode = new Node{prn, name, head};
        head = newNode;
    }

    void addSecretary(int prn, string name) {
        addMember(prn, name);
    }

    void deleteMember(int prn) {
        if (!head) return;
        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->prn != prn) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->prn << " " << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void concatenate(VertexClub& other) {
        if (!head) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = other.head;
        }
        other.head = NULL;
    }
};

int main() {
    VertexClub divA, divB;
    int choice, prn, n;
    string name;
    
    cout << "Enter number of members for Division A: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter PRN and Name: ";
        cin >> prn >> name;
        if (i == 0) {
            divA.addPresident(prn, name);
        } else if (i == n - 1) {
            divA.addSecretary(prn, name);
        } else {
            divA.addMember(prn, name);
        }
    }
    
    cout << "\nEnter number of members for Division B: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter PRN and Name: ";
        cin >> prn >> name;
        if (i == 0) {
            divB.addPresident(prn, name);
        } else if (i == n - 1) {
            divB.addSecretary(prn, name);
        } else {
            divB.addMember(prn, name);
        }
    }

    cout << "\nDiv A: "; divA.display();
    cout << "Div B: "; divB.display();
    
    cout << "\nTotal members in Div A: " << divA.countMembers() << endl;
    cout << "Total members in Div B: " << divB.countMembers() << endl;

    divA.concatenate(divB);
    cout << "\nAfter Concatenation: "; divA.display();
    cout << "Total members: " << divA.countMembers() << endl;

    return 0;
}
// Singly linked list for club membership with add/delete/concatenate | Time: O(n)
