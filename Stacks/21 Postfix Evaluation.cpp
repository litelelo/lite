#include <iostream>
#include <cstring>
using namespace std;

typedef struct SLL {
    int data;
    struct SLL *next;
} *node;

node top = NULL;

void push(int val) {
    node newnode = (node)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

int pop() {
    int val;
    if (top != NULL) {
        node temp = top;
        val = temp->data;
        top = top->next;
        delete temp;
    }

    return val;
}

int evaluate_postfix(string expr) {
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            push(c - '0');
        } else {
            int op2 = pop();
            int op1 = pop();
            int result = 0;
            switch(c){
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default:
                    cout << "Invalid operator: " << c << endl;
                    return 0;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    string expr;
    cout << "Enter postfix expression (single digit operands, no spaces): ";
    cin >> expr;
    int result = evaluate_postfix(expr);
    cout << "Result: " << result << endl;
    return 0;
}
// Postfix expression evaluation using stack | Time: O(n) | Space: O(n)