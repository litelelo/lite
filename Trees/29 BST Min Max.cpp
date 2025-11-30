#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node{val, NULL, NULL};
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

public:
    BST() { root = NULL; }
    void insert(int val) { root = insert(root, val); }

    int findMin() {
        if (!root) return -1;
        Node* temp = root;
        while (temp->left) temp = temp->left;
        return temp->data;
    }

    int findMax() {
        if (!root) return -1;
        Node* temp = root;
        while (temp->right) temp = temp->right;
        return temp->data;
    }
};

int main() {
    BST tree;
    int n, val;
    
    cout << "Enter number of nodes to insert: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        tree.insert(val);
    }
    
    cout << "Min: " << tree.findMin() << endl;
    cout << "Max: " << tree.findMax() << endl;
    return 0;
}
// BST find minimum and maximum values | Time: O(h) where h=height
