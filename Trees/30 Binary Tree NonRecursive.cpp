#include <iostream>
using namespace std;

struct StackNode {
    Node* data;
    StackNode* next;
};

class Stack {
    StackNode* top;
public:
    Stack() { 
        top = NULL; 
    }
    
    void push(Node* val) { 
        StackNode* t = new StackNode{val, top}; 
        top = t; 
    }
    
    void pop() { 
        if(top) { 
            StackNode* t = top; 
            top = top->next; 
            delete t; 
        } 
    }
    
    Node* getTop() { 
        return top ? top->data : NULL; 
    }
    
    bool empty() { 
        return top == NULL; 
    }
};

struct Node {
    int data;
    Node *left, *right;
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = NULL; }

    void insert(int val) {
        if (!root) { 
            root = new Node{val, NULL, NULL}; 
            return; 
        }
        Node* temp = root;
        while (temp->left) 
            temp = temp->left;
        temp->left = new Node{val, NULL, NULL};
    }

    void inorderNonRecursive() {
        Stack s;
        Node* curr = root;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.getTop();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    bt.root = new Node{1, NULL, NULL};
    bt.root->left = new Node{2, NULL, NULL};
    bt.root->right = new Node{3, NULL, NULL};
    bt.root->left->left = new Node{4, NULL, NULL};
    
    cout << "Inorder Non-Recursive: ";
    bt.inorderNonRecursive();
    return 0;
}
// Non-recursive inorder traversal using stack | Time: O(n)
