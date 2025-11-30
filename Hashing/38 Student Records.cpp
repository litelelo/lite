#include <iostream>
#include <string>
using namespace std;
#define SIZE 10

struct Student {
    int rollNo;
    string name;
};

class StudentHash {
    Student* table[SIZE];
public:
    StudentHash() {
        for (int i = 0; i < SIZE; i++) table[i] = NULL;
    }

    void insert(int roll, string name) {
        int index = roll % SIZE;
        int i = 0;
        while (table[(index + i) % SIZE] != NULL) {
            i++;
            if (i == SIZE) {
                cout << "Table Full\n";
                return;
            }
        }
        table[(index + i) % SIZE] = new Student{roll, name};
    }

    void search(int roll) {
        int index = roll % SIZE;
        int i = 0;
        while (table[(index + i) % SIZE] != NULL) {
            if (table[(index + i) % SIZE]->rollNo == roll) {
                cout << "Found: " << table[(index + i) % SIZE]->name << endl;
                return;
            }
            i++;
            if (i == SIZE) break;
        }
        cout << "Not Found\n";
    }
};

int main() {
    StudentHash sh;
    sh.insert(101, "Alice");
    sh.insert(102, "Bob");
    sh.insert(111, "Charlie"); // Collision with 101 if size 10 and mod 10
    sh.search(101);
    sh.search(111);
    sh.search(999);
    return 0;
}
// Hash table for student records using linear probing | Time: O(1) avg, O(n) worst
