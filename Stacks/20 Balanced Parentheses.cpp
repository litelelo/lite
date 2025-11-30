#include <iostream>
#include <string>
using namespace std;

struct StackNode {
    char data;
    StackNode* next;
};

class Stack {
    StackNode* top;
public:
    Stack() { 
        top = NULL; 
    }
    
    void push(char c) { 
        StackNode* t = new StackNode{c, top}; 
        top = t; 
    }
    
    void pop() { 
        if(top) { 
            StackNode* t = top; 
            top = top->next; 
            delete t; 
        } 
    }
    
    char getTop() { 
        return top ? top->data : '\0'; 
    }
    
    bool empty() { 
        return top == NULL; 
    }
};

bool isBalanced(string expr) {
    Stack s;
    char x;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }

        if (s.empty()) return false;

        switch (expr[i]) {
        case ')':
            x = s.getTop();
            s.pop();
            if (x == '{' || x == '[') return false;
            break;
        case '}':
            x = s.getTop();
            s.pop();
            if (x == '(' || x == '[') return false;
            break;
        case ']':
            x = s.getTop();
            s.pop();
            if (x == '(' || x == '{') return false;
            break;
        }
    }
    return (s.empty());
}

int main() {
    string expr;
    cout << "Enter expression with parentheses: ";
    cin >> expr;
    if (isBalanced(expr)) cout << "Balanced";
    else cout << "Not Balanced";
    return 0;
}
// Balanced parentheses checker using stack | Time: O(n)
