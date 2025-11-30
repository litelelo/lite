#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

class Set {
    Node* head;
public:
    Set() { head = NULL; }

    void insert(int id) {
        Node* newNode = new Node{id, head};
        head = newNode;
    }

    bool contains(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    static void intersection(Set& s1, Set& s2) {
        Node* temp = s1.head;
        cout << "Both Cricket and Football: ";
        while (temp) {
            if (s2.contains(temp->id)) cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    static void symmetricDifference(Set& s1, Set& s2) {
        cout << "Either but not both: ";
        Node* temp = s1.head;
        while (temp) {
            if (!s2.contains(temp->id)) cout << temp->id << " ";
            temp = temp->next;
        }
        temp = s2.head;
        while (temp) {
            if (!s1.contains(temp->id)) cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    int count() {
        int c = 0;
        Node* temp = head;
        while(temp) { c++; temp = temp->next; }
        return c;
    }
    
    static int unionCount(Set& s1, Set& s2) {
        int c = 0;
        Node* temp = s1.head;
        while(temp) { c++; temp = temp->next; }
        temp = s2.head;
        while(temp) {
            if(!s1.contains(temp->id)) c++;
            temp = temp->next;
        }
        return c;
    }
};

int main() {
    Set cricket, football;
    cricket.insert(1); cricket.insert(2); cricket.insert(3);
    football.insert(3); football.insert(4); football.insert(5);

    cout << "Cricket: "; cricket.display();
    cout << "Football: "; football.display();

    Set::intersection(cricket, football);
    Set::symmetricDifference(cricket, football);
    
    int totalStudents;
    cout << "Enter total number of students in class: ";
    cin >> totalStudents;
    cout << "Neither Cricket nor Football: " << totalStudents - Set::unionCount(cricket, football) << endl;

    return 0;
}
// Set operations (intersection, symmetric difference) using linked lists | Time: O(n²)
