#include <iostream>
using namespace std;

class TwoQueues {
    int *arr;
    int f1, r1, f2, r2, maxSize;
public:
    TwoQueues(int size) {
        maxSize = size;
        arr = new int[maxSize];
        f1 = -1;
        r1 = -1;
        f2 = maxSize;
        r2 = maxSize;
    }

    void addQ1(int val) {
        if (r1 < r2 - 1) {
            if (f1 == -1) {
                f1 = 0;
            }
            arr[++r1] = val;
            cout << "Added to Q1.\n";
        } else {
            cout << "Overflow\n";
        }
    }

    void addQ2(int val) {
        if (r1 < r2 - 1) {
            if (f2 == maxSize) {
                f2 = maxSize - 1;
            }
            arr[--r2] = val;
            cout << "Added to Q2.\n";
        } else {
            cout << "Overflow\n";
        }
    }

    void delQ1() {
        if (f1 != -1 && f1 <= r1) {
            cout << "Deleted Q1: " << arr[f1++] << endl;
            if (f1 > r1) {
                f1 = -1;
                r1 = -1;
            }
        } else {
            cout << "Underflow\n";
        }
    }

    void delQ2() {
        if (f2 != maxSize && f2 >= r2) {
            cout << "Deleted Q2: " << arr[f2--] << endl;
            if (f2 < r2) {
                f2 = maxSize;
                r2 = maxSize;
            }
        } else {
            cout << "Underflow\n";
        }
    }

    void display() {
        cout << "Q1: ";
        for (int i = f1; i != -1 && i <= r1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Q2: ";
        for (int i = f2; i != maxSize && i >= r2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, val;
    
    cout << "Enter array size: ";
    cin >> size;
    TwoQueues tq(size);
    
    while (true) {
        cout << "\n1. Add to Q1\n2. Add to Q2\n3. Delete from Q1\n4. Delete from Q2\n5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            tq.addQ1(val);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            tq.addQ2(val);
        } else if (choice == 3) {
            tq.delQ1();
        } else if (choice == 4) {
            tq.delQ2();
        } else if (choice == 5) {
            tq.display();
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Two queues in single array from opposite ends | Time: O(1)
