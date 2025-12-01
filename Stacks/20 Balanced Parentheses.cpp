#include <iostream>
using namespace std;

typedef struct sll {
    char bracket;
    struct sll *next;
} *node;

node top = NULL;

void push(char c) {
    node newnode = (node)malloc(sizeof(node));;
    newnode->bracket = c;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top != NULL) {
        node temp = top;
        top = top->next;
        delete temp;
    }
}

char peek() {
    if (top != NULL)
        return top->bracket;
    return '\0';
}

bool isempty() {
    return top == NULL;
}

bool isbalanced(string s) {
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isempty())
                return false;
            char t = peek();
            if ((c == ')' && t == '(') ||
                (c == '}' && t == '{') ||
                (c == ']' && t == '[')) {
                pop();
            } else {
                return false;
            }
        }
    }
    return isempty();
}

bool onlybrackets(string s) {
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']')
            return false;
    }
    return true;
}

int main() {
    string s;
    do {
        cout << "Enter a string of brackets: ";
        cin >> s;
        if (!onlybrackets(s)) {
            cout << "Invalid input! Please enter only brackets () {} []\n";
        }
    } while (!onlybrackets(s));
    
    if (isbalanced(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}
// Stack to check balanced parentheses ((), {}, []) | Time: O(n) | Space: O(n)