#include <iostream>
#include <string>
using namespace std;

typedef struct SLL {
    char data;
    struct SLL *next;
} *node;

node top = nullptr;

void push(char ch) {
    node newnode = new SLL;
    newnode->data = ch;
    newnode->next = top;
    top = newnode;
}

char pop() {
    if (top == nullptr) return '\0';
    char ch = top->data;
    node temp = top;
    top = top->next;
    delete temp;
    return ch;
}

char peek() {
    if (top == nullptr) return '\0';
    return top->data;
}

bool isEmpty() {
    return top == nullptr;
}

int getWeight(char ch) {
    switch (ch) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

void displayStack() {
    if (isEmpty()) {
        cout << "Stack: (empty)";
        return;
    }
    cout << "Stack (top->bottom): ";
    node temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool isSpace(char ch) {
    return (ch == ' ' || ch == '\t');
}

bool isOperand(char ch) {
    // Accept any character that is NOT operator or parenthesis
    return !(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')');
}

void infix2postfix(const string &infix, string &postfix) {
    postfix.clear();
    cout << "\n--- Step-by-step conversion trace ---\n";

    for (int i = 0; i < (int)infix.size(); i++) {
        char ch = infix[i];

        if (isSpace(ch)) continue;   // skip spaces manually

        cout << "\nRead char: '" << ch << "'\n";

        // --------- CASE 1: '(' ----------
        if (ch == '(') {
            push(ch);
            cout << "Action: push '('\n";
            displayStack(); cout << "\nPostfix so far: " << postfix << "\n";
            continue;
        }

        // --------- CASE 2: ')' ----------
        if (ch == ')') {
            cout << "Action: pop until '('\n";
            while (!isEmpty() && peek() != '(') {
                char p = pop();
                postfix.push_back(p);
                cout << "  popped '" << p << "' -> appended\n";
            }
            if (!isEmpty() && peek() == '(') {
                pop();
                cout << "  popped '(' and discarded\n";
            }
            displayStack(); cout << "\nPostfix so far: " << postfix << "\n";
            continue;
        }

        // --------- CASE 3: Operand ----------
        if (isOperand(ch)) {
            postfix.push_back(ch);
            cout << "Action: operand -> append '" << ch << "'\n";
            displayStack(); cout << "\nPostfix so far: " << postfix << "\n";
            continue;
        }

        // --------- CASE 4: Operator + - * / ----------
        int weight = getWeight(ch);
        cout << "Action: operator (weight=" << weight << ")\n";

        while (!isEmpty() && peek() != '(' && weight <= getWeight(peek())) {
            char p = pop();
            postfix.push_back(p);
            cout << "  popped '" << p << "' (>= precedence) -> appended\n";
        }

        push(ch);
        cout << "  push '" << ch << "'\n";
        displayStack(); cout << "\nPostfix so far: " << postfix << "\n";
    }

    // --------- END: pop all remaining ----------
    cout << "\nEnd of expression: popping remaining operators\n";
    while (!isEmpty()) {
        char p = pop();
        if (p != '(') {
            postfix.push_back(p);
            cout << "  popped '" << p << "' -> appended\n";
        }
    }

    cout << "--- End trace ---\n\n";
}

int main() {
    string infix;
    cout << "Enter the Infix Expression: ";
    getline(cin, infix);

    string postfix;
    infix2postfix(infix, postfix);

    cout << "Infix  : " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}
