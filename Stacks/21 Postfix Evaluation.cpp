#include <iostream>
#include <string>
using namespace std;

struct StackNode {
    int data;
    StackNode* next;
};

class Stack {
    StackNode* top;
public:
    Stack() { top = NULL; }
    void push(int val) { StackNode* t = new StackNode{val, top}; top = t; }
    void pop() { if(top) { StackNode* t = top; top = top->next; delete t; } }
    int getTop() { return top ? top->data : 0; }
    bool empty() { return top == NULL; }
};

int evaluatePostfix(string exp) {
    Stack st;

    for (int i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');
        else {
            int val1 = st.getTop(); st.pop();
            int val2 = st.getTop(); st.pop();
            switch (exp[i]) {
            case '+': st.push(val2 + val1); break;
            case '-': st.push(val2 - val1); break;
            case '*': st.push(val2 * val1); break;
            case '/': st.push(val2 / val1); break;
            }
        }
    }
    return st.getTop();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;
    cout << "postfix evaluation: " << evaluatePostfix(exp);
    return 0;
}
// Postfix expression evaluation using stack | Time: O(n)
