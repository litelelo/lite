#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

int hashTable[TABLE_SIZE];
bool isOccupied[TABLE_SIZE];

void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
        isOccupied[i] = false;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (isOccupied[index]) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            cout << "Hash table is full. Cannot insert key " << key << endl;
            return;
        }
    }

    hashTable[index] = key;
    isOccupied[index] = true;
    cout << "Inserted key " << key << " at index " << index << endl;
}

int search (int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (isOccupied[index]) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;
    }

    return -1; 
}

void removeKey(int key) {
    int index = search(key);
    if (index != -1) {
        hashTable[index] = -1;
        isOccupied[index] = false;
        cout << "Key " << key << " deleted from index " << index << endl;
    } else {
        cout << "Key " << key << " not found.\n";
    }
}

void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (isOccupied[i])
            cout << "Index " << i << ": " << hashTable[i] << endl;
        else
            cout << "Index " << i << ": Empty\n";
    }
}

int main() {
    initialize();
    int choice, key;
    do {
        cout << "\nHash Table Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            {
                int index = search(key);
                if (index != -1)
                    cout << "Key " << key << " found at index " << index << endl;
                else
                    cout << "Key " << key << " not found." << endl;
            }
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            removeKey(key);
            break;
        case 4:
            display();
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
// Hash table with linear probing collision resolution | Operations: insert, search, display | Time: O(1) avg, O(n) worst | Space: O(n)
