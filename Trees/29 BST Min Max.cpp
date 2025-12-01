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

void findMin(node n){
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    else{
        while(n && n->left != NULL){
            n = n->left;
        }

        cout << "Minimum value in tree = " << n->element << endl;
    }
    
}

void findMax(node n){
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    else{
        while(n && n->right != NULL){
            n = n->right;
        }

        cout << "Maximum value in tree = " << n->element << endl;
    }
}

int main(){
    int choice, value;
    
    do{
        cout << "\n=== Binary Search Tree Operations ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find minimum" << endl;
        cout << "3. Find maximum" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                insert();
                cout << "Value inserted successfully!" << endl;
                break;
                
            case 2:
                findMin(root);
                break;
                
            case 3:
                findMax(root);
                break;
                
            case 4:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);
    
    return 0;
}
// BST with insert, search, find minimum and maximum values | Time: O(h) avg O(log n) | Space: O(h)