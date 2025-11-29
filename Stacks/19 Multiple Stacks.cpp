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
    int k = 3, n = 10;
    MultiStack ms(k, n);
    ms.push(10, 0); ms.push(20, 0);
    ms.push(30, 1);
    ms.push(40, 2);
    
    cout << "Stack 0: "; ms.display(0);
    cout << "Stack 1: "; ms.display(1);
    cout << "Stack 2: "; ms.display(2);
    
    cout << "Popped from 0: " << ms.pop(0) << endl;
    return 0;
}
