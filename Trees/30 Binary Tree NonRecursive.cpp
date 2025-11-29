#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = NULL; }

    void insert(int val) {
        // Simple insert for demo
        if (!root) { root = new Node{val, NULL, NULL}; return; }
        // Just inserting to left for simplicity or use queue for level order insert
        Node* temp = root;
        while (temp->left) temp = temp->left;
        temp->left = new Node{val, NULL, NULL};
    }

    void inorderNonRecursive() {
        stack<Node*> s;
        Node* curr = root;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
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
