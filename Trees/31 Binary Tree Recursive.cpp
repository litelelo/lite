#include <iostream>
using namespace std;

typedef struct BT{
    int element;
    struct BT *left;
    struct BT *right;
} *node;

node root = NULL;

node accept(){
    node a = new BT;
    cout << "\nEnter the value stored: ";
    cin >> a->element;
    a->left = NULL;
    a->right = NULL;
    return a;
}

void insert(){
    node newnode = accept();

    if(root == NULL){
        root = newnode;
        return;
    }

    node current = root;
    node parent = NULL;
    
    while(current != NULL){
        parent = current;
        if(newnode->element < current->element){
            current = current->left;
        }
        else if(newnode->element > current->element){
            current = current->right;
        }
        else{
            cout << "Value already exists!" << endl;
            delete newnode;
            return;
        }
    }
    
    if(newnode->element < parent->element){
        parent->left = newnode;
    }
    else{
        parent->right = newnode;
    }
}

void inorder(node n){
    if(n != NULL){
        inorder(n->left);
        cout << n->element << " ";
        inorder(n->right);
    }
}

void preorder(node n){
    if(n != NULL){
        cout << n->element << " ";
        preorder(n->left);
        preorder(n->right);
    }
}

int countLeafRecursive(node n){
    if(n == NULL){
        return 0;
    }
    if(n->left == NULL && n->right == NULL){
        return 1;
    }
    return countLeafRecursive(n->left) + countLeafRecursive(n->right);
}

void mirrorRecursive(node n){
    if(n == NULL){
        return;
    }
    
    // Swap left and right children
    node temp = n->left;
    n->left = n->right;
    n->right = temp;
    
    // Recursively mirror left and right subtrees
    mirrorRecursive(n->left);
    mirrorRecursive(n->right);
}

int main(){
    int choice, value;
    
    do{
        cout << "\n=== Binary Tree Non-Recursive Operations ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Count Leaf Nodes" << endl;
        cout << "5. Mirror Image" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                insert();
                cout << "Value inserted successfully!" << endl;
                break;
                
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                break;
                
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                break;

            case 4:
                if(root == NULL){
                    cout << "Tree is empty!" << endl;
                }
                else{
                    cout << "Number of Leaf Nodes: " << countLeafRecursive(root) << endl;
                }
                break;
                
            case 5:
                if(root == NULL){
                    cout << "Tree is empty!" << endl;
                }
                else{
                    cout << "Original Tree - Inorder: ";
                    inorder(root);
                    mirrorRecursive(root);
                    cout << "Mirror Image created!" << endl;
                    cout << "Mirror Tree - Inorder: ";
                    inorder(root);
                }
                break;

             case 6:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);
    
    return 0;
}
// Binary Tree recursive operations: insert, traversals, count leaf nodes, mirror | Time: O(n) traversals | Space: O(h)