#include <iostream>
using namespace std;

struct QNode {
    Node* data;
    QNode* next;
};

class Queue {
    QNode *front, *rear;
public:
    Queue() { 
        front = rear = NULL; 
    }
    
    void push(Node* val) { 
        QNode* t = new QNode{val, NULL}; 
        if(rear) 
            rear->next = t; 
        else 
            front = t; 
        rear = t; 
    }
    
    void pop() { 
        if(front) { 
            QNode* t = front; 
            front = front->next; 
            if(!front) 
                rear = NULL; 
            delete t; 
        } 
    }
    
    Node* getFront() { 
        return front ? front->data : NULL; 
    }
    
    bool empty() { 
        return front == NULL; 
    }
};

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
        Queue q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.getFront();
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
    int choice, val;
    
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display Inorder\n4. Display Level Order\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            tree.insert(val);
        } else if (choice == 2) {
            cout << "Enter value to delete: ";
            cin >> val;
            tree.remove(val);
        } else if (choice == 3) {
            cout << "Inorder: ";
            tree.display();
        } else if (choice == 4) {
            cout << "Level Order: ";
            tree.levelOrder();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// BST with insert, delete, inorder, level-order traversal | Time: O(h) where h=height
