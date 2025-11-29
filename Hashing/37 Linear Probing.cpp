#include <iostream>
using namespace std;
#define SIZE 10

class HashTable {
    int table[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) table[i] = -1;
    }

    void insert(int key) {
        int index = key % SIZE;
        int i = 0;
        while (table[(index + i) % SIZE] != -1) {
            i++;
            if (i == SIZE) {
                cout << "Table Full\n";
                return;
            }
        }
        table[(index + i) % SIZE] = key;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (table[i] != -1) cout << i << " --> " << table[i] << endl;
            else cout << i << " --> " << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(10); ht.insert(20); ht.insert(30); // Collisions
    ht.insert(4); ht.insert(14);
    ht.display();
    return 0;
}
