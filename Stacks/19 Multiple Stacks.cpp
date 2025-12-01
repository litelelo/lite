#include <iostream>
using namespace std;

const int SIZE = 10;
int arr[100];
int first1 = -1;
int first2 = SIZE;

void push1(){
    if (first1 + 1 == first2) {
        cout << "\nError: Stack Overflow!!" << endl;
    } else {
        int val;
        cout << "\nEnter a number to add to stack 1: ";
        cin >> val;
        arr[++first1] = val;
    }
}

void push2(){
    if (first2 - 1 == first1) {
        cout << "\nError: Stack Overflow!!" << endl;
    } else {
        int val;
        cout << "\nEnter a number to add to stack 2: ";
        cin >> val;
        arr[--first2] = val;
    }
}

void pop1(){
    if (first1 == -1) {
        cout << "\nError: Stack Underflow!!" << endl;
    } else {
        cout << "\nNumber popped from stack 1: " << arr[first1--] << endl;
    }
}

void pop2(){
    if (first2 == SIZE) {
        cout << "\nError: Stack Underflow!!" << endl;
    } else {
        cout << "\nNumber popped from stack 2: " << arr[first2++] << endl;
    }
}

void display(){
    cout << "\nStack 1: ";
    if (first1 == -1) cout << "Empty";
    for (int i = 0; i <= first1; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nStack 2: ";
    if (first2 == SIZE) cout << "Empty";
    for (int i = SIZE - 1; i >= first2; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n=== Multi-Stack Menu ===" << endl;
        cout << "1. Push Stack 1" << endl;
        cout << "2. Push Stack 2" << endl;
        cout << "3. Pop Stack 1" << endl;
        cout << "4. Pop Stack 2" << endl;
        cout << "5. Display Both Stacks" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: push1(); break;
            case 2: push2(); break;
            case 3: pop1(); break;
            case 4: pop2(); break;
            case 5: display(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);
    return 0;
}
// Two stacks in single array with opposite growth directions | Operations: push, pop, overflow, underflow, display | Time: O(1) | Space: O(n)