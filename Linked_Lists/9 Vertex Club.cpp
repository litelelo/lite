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
    divA.addPresident(1, "PresA");
    divA.addMember(2, "MemA1");
    divA.addSecretary(3, "SecA");
    
    divB.addPresident(4, "PresB");
    divB.addMember(5, "MemB1");
    divB.addSecretary(6, "SecB");

    cout << "Div A: "; divA.display();
    cout << "Div B: "; divB.display();

    divA.concatenate(divB);
    cout << "Concatenated: "; divA.display();

    return 0;
}
