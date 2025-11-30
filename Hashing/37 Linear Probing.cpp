#include <iostream>
using namespace std;

class HashTable {
    int *table;
    int size;
public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int index = key % size;
        int i = 0;
        while (table[(index + i) % size] != -1) {
            i++;
            if (i == size) {
                cout << "Table Full\n";
                return;
            }
        }
        table[(index + i) % size] = key;
        cout << "Inserted " << key << " at index " << (index + i) % size << endl;
    }

    void search(int key) {
        int index = key % size;
        int i = 0;
        while (table[(index + i) % size] != -1) {
            if (table[(index + i) % size] == key) {
                cout << "Found " << key << " at index " << (index + i) % size << endl;
                return;
            }
            i++;
            if (i == size) {
                break;
            }
        }
        cout << "Key " << key << " not found\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                cout << i << " --> " << table[i] << endl;
            } else {
                cout << i << " --> " << endl;
            }
        }
    }
};

int main() {
    int size, choice, key;
    
    cout << "Enter hash table size: ";
    cin >> size;
    HashTable ht(size);
    
    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
        } else if (choice == 2) {
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
        } else if (choice == 3) {
            ht.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Hash table with linear probing for collision resolution | Time: O(1) avg, O(n) worst
