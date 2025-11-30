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

    int count(Node* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    int height(Node* node) {
        if (!node) return 0;
        int l = height(node->left);
        int r = height(node->right);
        return (l > r ? l : r) + 1;
    }

public:
    BST() { root = NULL; }
    void insert(int val) { root = insert(root, val); }
    void displayStats() {
        cout << "Total Nodes: " << count(root) << endl;
        cout << "Height: " << height(root) << endl;
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
    
    tree.displayStats();
    return 0;
}
// BST node count and height calculation recursively | Time: O(n)
