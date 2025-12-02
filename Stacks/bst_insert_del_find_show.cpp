#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

class BST {
    Node *root;

    Node* insertRec(Node *node, int k) {
        if (node == NULL) return new Node(k);
        if (k < node->key)
            node->left = insertRec(node->left, k);
        else if (k > node->key)
            node->right = insertRec(node->right, k);
        // ignore if equal (no duplicates)
        return node;
    }

    Node* minValueNode(Node *node) {
        Node *cur = node;
        while (cur && cur->left != NULL)
            cur = cur->left;
        return cur;
    }

    Node* deleteRec(Node *node, int k) {
        if (node == NULL) return node;

        if (k < node->key)
            node->left = deleteRec(node->left, k);
        else if (k > node->key)
            node->right = deleteRec(node->right, k);
        else {
            // node to delete found
            if (node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node *temp = node->left;
                delete node;
                return temp;
            } else {
                // two children
                Node *succ = minValueNode(node->right);
                node->key = succ->key;
                node->right = deleteRec(node->right, succ->key);
            }
        }
        return node;
    }

    Node* findRec(Node *node, int k) {
        if (node == NULL || node->key == k) return node;
        if (k < node->key) return findRec(node->left, k);
        else return findRec(node->right, k);
    }

    void inorderRec(Node *node) {
        if (node == NULL) return;
        inorderRec(node->left);
        cout << node->key << " ";
        inorderRec(node->right);
    }

public:
    BST() { root = NULL; }

    void insertKey(int k) { root = insertRec(root, k); }

    void deleteKey(int k) { root = deleteRec(root, k); }

    bool findKey(int k) {
        return findRec(root, k) != NULL;
    }

    void show() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "BST (inorder): ";
        inorderRec(root);
        cout << "\n";
    }
};

int main() {
    BST tree;
    int ch, x;

    do {
        cout << "\n--- BST Operations ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Show (inorder)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> x;
            tree.insertKey(x);
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> x;
            tree.deleteKey(x);
            break;

        case 3:
            cout << "Enter key to find: ";
            cin >> x;
            if (tree.findKey(x))
                cout << "Key found in BST.\n";
            else
                cout << "Key NOT found.\n";
            break;

        case 4:
            tree.show();
            break;
        }
    } while (ch != 0);

    return 0;
}
