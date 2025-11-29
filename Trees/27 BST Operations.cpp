#include <iostream>
#include <queue>
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
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int val) {
        if (!root) return root;
        if (val < root->data) root->left = deleteNode(root->left, val);
        else if (val > root->data) root->right = deleteNode(root->right, val);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

public:
    BST() { root = NULL; }
    void insert(int val) { root = insert(root, val); }
    void remove(int val) { root = deleteNode(root, val); }
    void display() { inorder(root); cout << endl; }
    
    void levelOrder() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50); tree.insert(30); tree.insert(20); tree.insert(40); tree.insert(70);
    cout << "Inorder: "; tree.display();
    cout << "Level Order: "; tree.levelOrder();
    tree.remove(20);
    cout << "After delete 20: "; tree.display();
    return 0;
}
