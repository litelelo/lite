//Design and implement a smart college placement portal that uses advanced
//hashing techniques to efficiently manage student placement records with high
//performance and low collision probability, even under dynamic data growth.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- STUDENT RECORD ----------------
class Student {
public:
    int id;           // unique key (e.g., PRN)
    string name;
    string branch;
    float cgpa;
    string company;   // "NA" if not placed

    Student(int i = 0, string n = "", string b = "", float c = 0.0, string comp = "NA") {
        id = i;
        name = n;
        branch = b;
        cgpa = c;
        company = comp;
    }
};

// ---------------- HASH TABLE WITH ADVANCED HASHING ----------------
enum SlotState { EMPTY, OCCUPIED, DELETED };

class HashTable {
    struct Slot {
        Student s;
        SlotState state;
        Slot() {
            state = EMPTY;
        }
    };

    vector<Slot> table;
    int currentSize;   // OCCUPIED slots count

    // ----- helpers -----
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }

    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

    double loadFactor() const {
        return (double)currentSize / table.size();
    }

    int h1(int key) const {               // primary hash
        return key % table.size();
    }

    int h2(int key) const {               // secondary hash
        // must be non-zero and relatively prime to table size
        return 1 + (key % (table.size() - 1));
    }

    void rehash() {
        int oldSize = table.size();
        int newSize = nextPrime(2 * oldSize);

        vector<Slot> oldTable = table;
        table.clear();
        table.resize(newSize);
        currentSize = 0;

        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i].state == OCCUPIED) {
                insert(oldTable[i].s);   // reinsert into new table
            }
        }
        cout << "\n[Rehash] Expanded from " << oldSize
             << " to " << newSize << " (to handle dynamic growth)\n";
    }

public:
    HashTable(int initialSize = 11) {
        initialSize = nextPrime(initialSize);
        table.resize(initialSize);
        currentSize = 0;
    }

    // INSERT / UPDATE (double hashing + dynamic rehashing)
    void insert(const Student &st) {
        if (loadFactor() > 0.7) {
            rehash();
        }

        int key = st.id;
        int index = h1(key);
        int step = h2(key);
        int firstDeleted = -1;

        for (int i = 0; i < (int)table.size(); i++) {
            int idx = (index + i * step) % table.size();

            if (table[idx].state == EMPTY) {
                if (firstDeleted != -1) idx = firstDeleted;
                table[idx].s = st;
                table[idx].state = OCCUPIED;
                currentSize++;
                cout << "Record inserted at index " << idx << ".\n";
                return;
            } else if (table[idx].state == DELETED && firstDeleted == -1) {
                firstDeleted = idx;
            } else if (table[idx].state == OCCUPIED && table[idx].s.id == key) {
                table[idx].s = st;   // update
                cout << "Existing ID found. Record updated at index " << idx << ".\n";
                return;
            }
        }
        cout << "Table full. Insert failed.\n";
    }

    int findIndex(int key) const {
        int index = h1(key);
        int step = h2(key);

        for (int i = 0; i < (int)table.size(); i++) {
            int idx = (index + i * step) % table.size();

            if (table[idx].state == EMPTY) {
                return -1; // key not in table
            } else if (table[idx].state == OCCUPIED && table[idx].s.id == key) {
                return idx;
            }
        }
        return -1;
    }

    bool find(int key, Student &out) const {
        int idx = findIndex(key);
        if (idx == -1) return false;
        out = table[idx].s;
        return true;
    }

    void remove(int key) {
        int idx = findIndex(key);
        if (idx == -1) {
            cout << "Record with ID " << key << " not found.\n";
            return;
        }
        table[idx].state = DELETED;
        currentSize--;
        cout << "Record with ID " << key << " deleted (marked DELETED).\n";
    }

    void show() const {
        cout << "\n--- Placement Hash Table ---\n";
        cout << "Idx\tState\tID\tName\tBranch\tCGPA\tCompany\n";
        for (int i = 0; i < (int)table.size(); i++) {
            cout << i << "\t";
            if (table[i].state == EMPTY) {
                cout << "EMPTY\n";
            } else if (table[i].state == DELETED) {
                cout << "DELETED\n";
            } else {
                const Student &s = table[i].s;
                cout << "USED\t" << s.id << "\t" << s.name
                     << "\t" << s.branch << "\t" << s.cgpa
                     << "\t" << s.company << "\n";
            }
        }
        cout << "Current size: " << currentSize
             << " , Table size: " << table.size()
             << " , Load factor: " << loadFactor() << "\n";
    }
};

// input helper for full strings
string inputLine() {
    string s;
    cin >> ws;
    getline(cin, s);
    return s;
}

// ---------------- MAIN (SMART PLACEMENT PORTAL) ----------------
int main() {
    HashTable ht;
    int choice;

    do {
        cout << "\n=== Smart College Placement Portal ===\n";
        cout << "1. Insert / Update student record\n";
        cout << "2. Delete student record\n";
        cout << "3. Find student by ID\n";
        cout << "4. Show all records (hash table)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            float cgpa;
            cout << "Enter Student ID (numeric): ";
            cin >> id;
            cout << "Enter Name: ";
            string name = inputLine();
            cout << "Enter Branch: ";
            string branch = inputLine();
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter Company (or NA if not placed): ";
            string company = inputLine();

            Student s(id, name, branch, cgpa, company);
            ht.insert(s);

        } else if (choice == 2) {
            int id;
            cout << "Enter Student ID to delete: ";
            cin >> id;
            ht.remove(id);

        } else if (choice == 3) {
            int id;
            cout << "Enter Student ID to find: ";
            cin >> id;
            Student s;
            if (ht.find(id, s)) {
                cout << "Record found:\n";
                cout << "ID: " << s.id
                     << "\nName: " << s.name
                     << "\nBranch: " << s.branch
                     << "\nCGPA: " << s.cgpa
                     << "\nCompany: " << s.company << "\n";
            } else {
                cout << "No record with ID " << id << " found.\n";
            }

        } else if (choice == 4) {
            ht.show();
        }

    } while (choice != 0);

    return 0;
}
