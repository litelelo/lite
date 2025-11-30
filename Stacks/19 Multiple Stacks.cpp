#include <iostream>
using namespace std;

class MultiStack {
    int *arr;
    int *top;
    int *next;
    int n, k;
    int free;

public:
    MultiStack(int k1, int n1) {
        k = k1; n = n1;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        free = 0;
        for (int i = 0; i < k; i++) top[i] = -1;
        for (int i = 0; i < n - 1; i++) next[i] = i + 1;
        next[n - 1] = -1;
    }

    void push(int item, int sn) {
        if (free == -1) {
            cout << "Stack Overflow\n";
            return;
        }
        int i = free;
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = item;
    }

    int pop(int sn) {
        if (top[sn] == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }

    void display(int sn) {
        int i = top[sn];
        while (i != -1) {
            cout << arr[i] << " ";
            i = next[i];
        }
        cout << endl;
    }
};

int main() {
    int k, n, choice, item, stackNum;
    
    cout << "Enter number of stacks: ";
    cin >> k;
    cout << "Enter total array size: ";
    cin >> n;
    
    MultiStack ms(k, n);
    
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter stack number (0-" << k-1 << "): ";
            cin >> stackNum;
            cout << "Enter item: ";
            cin >> item;
            ms.push(item, stackNum);
        } else if (choice == 2) {
            cout << "Enter stack number (0-" << k-1 << "): ";
            cin >> stackNum;
            item = ms.pop(stackNum);
            if (item != -1) {
                cout << "Popped: " << item << endl;
            }
        } else if (choice == 3) {
            cout << "Enter stack number (0-" << k-1 << "): ";
            cin >> stackNum;
            cout << "Stack " << stackNum << ": ";
            ms.display(stackNum);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Multiple stacks in single array using next-free array technique | Time: O(1)
