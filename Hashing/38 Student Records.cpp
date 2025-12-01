#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Student {
    int rollNumber;
    string name;
    float marks;
    bool isEmpty;
    
    Student() : rollNumber(-1), name(""), marks(0.0), isEmpty(true) {}
};

Student hashTable[TABLE_SIZE];

void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = Student();
    }
}

int hashFunction(int rollNumber) {
    return rollNumber % TABLE_SIZE;
}

void insertStudent() {
    int rollNumber;
    string name;
    float marks;
    
    cout << "Enter roll number: ";
    cin >> rollNumber;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter marks: ";
    cin >> marks;
    
    int index = hashFunction(rollNumber);
    int startIndex = index;

    while (!hashTable[index].isEmpty) {
        if (hashTable[index].rollNumber == rollNumber) {
            cout << "Roll number " << rollNumber << " already exists!" << endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            cout << "Hash table is full. Cannot insert student record." << endl;
            return;
        }
    }

    hashTable[index].rollNumber = rollNumber;
    hashTable[index].name = name;
    hashTable[index].marks = marks;
    hashTable[index].isEmpty = false;
    
    cout << "Student record inserted at index " << index << endl;
}

int searchStudent(int rollNumber) {
    int index = hashFunction(rollNumber);
    int startIndex = index;

    while (!hashTable[index].isEmpty) {
        if (hashTable[index].rollNumber == rollNumber) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;
    }

    return -1;
}

void displayStudent() {
    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;
    
    int index = searchStudent(rollNumber);
    if (index != -1) {
        cout << "\nStudent Record Found at index " << index << ":\n";
        cout << "Roll Number: " << hashTable[index].rollNumber << endl;
        cout << "Name: " << hashTable[index].name << endl;
        cout << "Marks: " << hashTable[index].marks << endl;
    } else {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}

void deleteStudent() {
    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;
    
    int index = searchStudent(rollNumber);
    if (index != -1) {
        cout << "Student record deleted: " << hashTable[index].name << 
                " (Roll: " << hashTable[index].rollNumber << ")" << endl;
        hashTable[index] = Student(); // Reset to empty
    } else {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}

void displayAllStudents() {
    cout << "\nAll Student Records:\n";
    cout << "Index\tRoll No\tName\t\tMarks\n";
    cout << "---------------------------------------------\n";
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hashTable[i].isEmpty) {
            cout << i << "\t" << hashTable[i].rollNumber << "\t" 
                 << hashTable[i].name << "\t\t" << hashTable[i].marks << endl;
        } else {
            cout << i << "\tEmpty\n";
        }
    }
}

int main() {
    initialize();
    int choice;
    
    do {
        cout << "\n=== Student Record Hash Table ===\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Search Student by Roll Number\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Display All Records\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            insertStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            displayAllStudents();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
// Student records hash table with linear probing | Operations: insert, delete, search, display | Time: O(1) avg, O(n) worst | Space: O(n)