#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
};

class StudentHash {
    Student** table;
    int size;
public:
    StudentHash(int s) {
        size = s;
        table = new Student*[size];
        for (int i = 0; i < size; i++) {
            table[i] = NULL;
        }
    }

    void insert(int roll, string name) {
        int index = roll % size;
        int i = 0;
        while (table[(index + i) % size] != NULL) {
            i++;
            if (i == size) {
                cout << "Table Full\n";
                return;
            }
        }
        table[(index + i) % size] = new Student{roll, name};
        cout << "Inserted student " << name << " with roll no " << roll << endl;
    }

    void search(int roll) {
        int index = roll % size;
        int i = 0;
        while (table[(index + i) % size] != NULL) {
            if (table[(index + i) % size]->rollNo == roll) {
                cout << "Found: " << table[(index + i) % size]->name << endl;
                return;
            }
            i++;
            if (i == size) {
                break;
            }
        }
        cout << "Not Found\n";
    }

    void display() {
        cout << "\nStudent Records:\n";
        for (int i = 0; i < size; i++) {
            if (table[i] != NULL) {
                cout << i << " --> Roll: " << table[i]->rollNo << ", Name: " << table[i]->name << endl;
            } else {
                cout << i << " --> " << endl;
            }
        }
    }
};

int main() {
    int size, choice, roll;
    string name;
    
    cout << "Enter hash table size: ";
    cin >> size;
    StudentHash sh(size);
    
    while (true) {
        cout << "\n1. Insert Student\n2. Search Student\n3. Display All\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter name: ";
            cin >> name;
            sh.insert(roll, name);
        } else if (choice == 2) {
            cout << "Enter roll number to search: ";
            cin >> roll;
            sh.search(roll);
        } else if (choice == 3) {
            sh.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Hash table for student records using linear probing | Time: O(1) avg, O(n) worst
