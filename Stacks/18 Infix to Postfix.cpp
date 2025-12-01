#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct SLL {
    char data;
    struct SLL *next;
} *node;

node top = NULL;

void push(char ch) {
    node newnode = (node)malloc(sizeof(node));
    newnode->data = ch;
    newnode->next = top;
    top = newnode;
}

char pop() {
    if (top == NULL) {
        return '\0'; 
    } else {
        char ch = top->data;
        node temp = top;
        top = top->next;
        free(temp);
        return ch;
    }
}

char peek() {
    if (top == NULL) {
        return '\0';
    } else {
        return top->data;
    }
}

bool isEmpty() {
    return (top == NULL);
}

int getWeight(char ch) {
    switch (ch) {
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

void infix2postfix(char infix[], char postfix[], int size) {
    int weight;
    int i = 0;
    int k = 0;
    char ch;
      
    while (i < size) {
        ch = infix[i];
        
        if (ch == '(') {
            push(ch);
            i++;
            continue;
        }
        
        if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            // Pop off the opening parenthesis also
            if (!isEmpty()) {
                pop();
            }
            i++;
            continue;
        }
        
        weight = getWeight(ch);
        if (weight == 0) {
            postfix[k++] = ch;
        } else {
            if (isEmpty()) {
                push(ch);
            } else {
                while (!isEmpty() && peek() != '(' && weight <= getWeight(peek())) {
                    postfix[k++] = pop();
                }
                push(ch);
            }
        }
        i++;
    }
    
    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; 
}

void displayStack() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        node temp = top;
        cout << "Stack contents (top to bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    char infix[50];
    cout << "\nEnter the Infix Expression: ";
    cin >> infix;
    
    int size = strlen(infix);
    char postfix[50]; 
    
    infix2postfix(infix, postfix, size);
    
    cout << "\nInfix Expression  : " << infix;
    cout << "\nPostfix Expression: " << postfix;
    cout << endl;
    
    return 0;
}
// Infix to postfix conversion using stack with operator precedence | Time: O(n) | Space: O(n)