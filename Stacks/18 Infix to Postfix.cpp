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
    Stack() { top = NULL; }
    void push(char c) { StackNode* t = new StackNode{c, top}; top = t; }
    void pop() { if(top) { StackNode* t = top; top = top->next; delete t; } }
    char getTop() { return top ? top->data : '\0'; }
    bool empty() { return top == NULL; }
};

int prec(char c) {
    if (c == '^') return 3;
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(string s) {
    Stack st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.getTop() != '(') {
                result += st.getTop();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(s[i]) <= prec(st.getTop())) {
                result += st.getTop();
                st.pop();
            }
            st.push(c);
        }
        cout << "Step " << i + 1 << ": " << result << endl;
    }

    while (!st.empty()) {
        result += st.getTop();
        st.pop();
    }

    cout << "Postfix: " << result << endl;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;
    infixToPostfix(exp);
    return 0;
}
// Infix to postfix conversion using stack and operator precedence | Time: O(n)
