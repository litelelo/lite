// WAP to simulate a faculty database as a hash table. Search a particular faculty by
//using MOD as a hash function for linear probing with chaining with replacement
//method of collision handling technique. Assume suitable data for faculty record

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Faculty {
    int id;
    string name;
    string dept;
    int next;      // index of next node in chain, -1 if none
    bool occupied; // whether this slot is used

    Faculty() {
        id = -1;
        name = "";
        dept = "";
        next = -1;
        occupied = false;
    }
};

Faculty tableHash[TABLE_SIZE];

int hashFunc(int key) {
    return key % TABLE_SIZE;
}

// Find empty slot using linear probing, starting after 'start'
int findEmptySlot(int start) {
    int i = (start + 1) % TABLE_SIZE;
    while (i != start) {
        if (!tableHash[i].occupied)
            return i;
        i = (i + 1) % TABLE_SIZE;
    }
    return -1; // table full
}

void insertFaculty(int id, const string &name, const string &dept) {
    int home = hashFunc(id);

    // Case 1: Home slot empty
    if (!tableHash[home].occupied) {
        tableHash[home].id = id;
        tableHash[home].name = name;
        tableHash[home].dept = dept;
        tableHash[home].next = -1;
        tableHash[home].occupied = true;
        return;
    }

    // Home slot occupied
    int existingHome = hashFunc(tableHash[home].id);

    // Case 2: Chaining without replacement (same home bucket)
    if (existingHome == home) {
        int pos = findEmptySlot(home);
        if (pos == -1) {
            cout << "Hash table is full. Cannot insert.\n";
            return;
        }

        // attach at end of chain
        int curr = home;
        while (tableHash[curr].next != -1)
            curr = tableHash[curr].next;

        tableHash[curr].next = pos;

        tableHash[pos].id = id;
        tableHash[pos].name = name;
        tableHash[pos].dept = dept;
        tableHash[pos].next = -1;
        tableHash[pos].occupied = true;
    }
    // Case 3: Chaining *with replacement*
    else {
        // Displace existing record at 'home'
        Faculty temp = tableHash[home];  // record to be moved
        int oldPos = home;
        int oldHome = existingHome;

        // Put new record at its correct home position
        tableHash[home].id = id;
        tableHash[home].name = name;
        tableHash[home].dept = dept;
        tableHash[home].next = -1;
        tableHash[home].occupied = true;

        // Find new empty slot for displaced record
        int pos = findEmptySlot(home);
        if (pos == -1) {
            cout << "Hash table is full. Cannot insert displaced record.\n";
            return;
        }

        // Copy displaced record to new position
        tableHash[pos] = temp;   // copies id, name, dept, next, occupied

        // Fix the chain that started at oldHome
        int pred = oldHome;
        while (tableHash[pred].next != oldPos && tableHash[pred].next != -1) {
            pred = tableHash[pred].next;
        }

        if (tableHash[pred].next == oldPos) {
            tableHash[pred].next = pos; // predecessor now points to the new position
        }
    }
}

int searchFaculty(int id) {
    int home = hashFunc(id);
    if (!tableHash[home].occupied)
        return -1;

    int curr = home;
    while (curr != -1) {
        if (tableHash[curr].occupied && tableHash[curr].id == id)
            return curr;
        curr = tableHash[curr].next;
    }
    return -1;
}

void displayTable() {
    cout << "\nIndex\tID\tName\tDept\tNext\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << "\t";
        if (tableHash[i].occupied) {
            cout << tableHash[i].id << "\t"
                 << tableHash[i].name << "\t"
                 << tableHash[i].dept << "\t"
                 << tableHash[i].next << "\n";
        } else {
            cout << "-\t-\t-\t" << tableHash[i].next << "\n";
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Faculty Hash Table ---\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name, dept;
            cout << "Enter Faculty ID (integer): ";
            cin >> id;
            cout << "Enter Faculty Name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, dept);
            insertFaculty(id, name, dept);
        } else if (choice == 2) {
            int id;
            cout << "Enter Faculty ID to search: ";
            cin >> id;
            int pos = searchFaculty(id);
            if (pos == -1) {
                cout << "Faculty not found.\n";
            } else {
                cout << "Faculty found at index " << pos << ":\n";
                cout << "ID: " << tableHash[pos].id
                     << ", Name: " << tableHash[pos].name
                     << ", Dept: " << tableHash[pos].dept << "\n";
            }
        } else if (choice == 3) {
            displayTable();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
