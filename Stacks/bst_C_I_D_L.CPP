
//Write a program to perform Binary Search Tree (BST) operations (Create, Insert,
//Delete, Levelwise display )
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class BST {
    Node *root;

    Node* insertRec(Node *node, int key) {
        if (node == NULL) return new Node(key);
        if (key < node->data)
            node->left = insertRec(node->left, key);
        else if (key > node->data)
            node->right = insertRec(node->right, key);
        return node;
    }

    Node* minValueNode(Node *node) {
        Node *curr = node;
        while (curr && curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    Node* deleteRec(Node *node, int key) {
        if (node == NULL) return node;

        if (key < node->data)
            node->left = deleteRec(node->left, key);
        else if (key > node->data)
            node->right = deleteRec(node->right, key);
        else {
            // node found
            if (node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node *temp = node->left;
                delete node;
                return temp;
            } else {
                Node *succ = minValueNode(node->right);
                node->data = succ->data;
                node->right = deleteRec(node->right, succ->data);
            }
        }
        return node;
    }

public:
    BST() { root = NULL; }

    void create() {
        int n, x;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter " << n << " values:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            root = insertRec(root, x);
        }
    }

    void insertKey(int key) {
        root = insertRec(root, key);
    }

    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

    void levelOrder() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        queue<Node*> q;
        q.push(root);
        cout << "Level-wise display: ";
        while (!q.empty()) {
            Node *cur = q.front(); q.pop();
            cout << cur->data << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << "\n";
    }
};

int main() {
    BST tree;
    int ch, x;

    do {
        cout << "\n--- BST Menu ---\n";
        cout << "1. Create tree\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Level-wise display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            tree.create();
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> x;
            tree.insertKey(x);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> x;
            tree.deleteKey(x);
            break;
        case 4:
            tree.levelOrder();
            break;
        }
    } while (ch != 0);

    return 0;
}
