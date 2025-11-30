#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class BinaryTree {
    Node* root;

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    int countLeaves(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

public:
    BinaryTree() { root = NULL; }

    void buildTree() {
        root = new Node{1, new Node{2, NULL, NULL}, new Node{3, NULL, NULL}};
        root->left->left = new Node{4, NULL, NULL};
        root->right->right = new Node{5, NULL, NULL};
    }

    void display() {
        cout << "Inorder: "; inorder(root); cout << endl;
        cout << "Preorder: "; preorder(root); cout << endl;
        cout << "Leaf Nodes: " << countLeaves(root) << endl;
    }
};

int main() {
    BinaryTree bt;
    bt.buildTree();
    bt.display();
    return 0;
}
// Recursive inorder, preorder traversal and leaf node count | Time: O(n)
