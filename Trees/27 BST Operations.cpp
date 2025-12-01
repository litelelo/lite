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

node findMin(node n){
    while(n && n->left != NULL){
        n = n->left;
    }
    return n;
}

void deleteValue(int value){
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    
    node current = root;
    node parent = NULL;
    bool isLeftChild = false;
    
    // Find the node to delete
    while(current != NULL && current->element != value){
        parent = current;
        if(value < current->element){
            current = current->left;
            isLeftChild = true;
        }
        else{
            current = current->right;
            isLeftChild = false;
        }
    }
    
    if(current == NULL){
        cout << "Value not found!" << endl;
        return;
    }
    
    // Case 1: Node has no children (leaf node)
    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        }
        else if(isLeftChild){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
        delete current;
    }
    // Case 2: Node has one child
    else if(current->left == NULL){
        if(current == root){
            root = current->right;
        }
        else if(isLeftChild){
            parent->left = current->right;
        }
        else{
            parent->right = current->right;
        }
        delete current;
    }
    else if(current->right == NULL){
        if(current == root){
            root = current->left;
        }
        else if(isLeftChild){
            parent->left = current->left;
        }
        else{
            parent->right = current->left;
        }
        delete current;
    }
    // Case 3: Node has two children
    else{
        node successor = findMin(current->right);
        current->element = successor->element;
        
        // Delete the successor
        node succParent = current;
        node succCurrent = current->right;
        
        while(succCurrent->left != NULL){
            succParent = succCurrent;
            succCurrent = succCurrent->left;
        }
        
        if(succParent != current){
            succParent->left = succCurrent->right;
        }
        else{
            succParent->right = succCurrent->right;
        }
        
        delete succCurrent;
    }
    cout << "Value deleted successfully!" << endl;
}

// Function to get height of tree
int getHeight(node n){
    if(n == NULL){
        return 0;
    }
    int leftHeight = getHeight(n->left);
    int rightHeight = getHeight(n->right);
    
    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
} 

// Function to print nodes at a given level
void printLevel(node n, int level){
    if(n == NULL){
        return;
    }
    if(level == 1){
        cout << n->element << " ";
    }
    else if(level > 1){
        printLevel(n->left, level - 1);
        printLevel(n->right, level - 1);
    }
}

void levelwiseDisplay(){
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    
    int height = getHeight(root);
    cout << "Level-wise display: ";
    
    for(int i = 1; i <= height; i++){
        printLevel(root, i);
    }
    cout << endl;
}



int main(){
    int choice, value;
    
    do{
        cout << "\n=== Binary Search Tree Operations ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Level-wise Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                insert();
                cout << "Value inserted successfully!" << endl;
                break;
                
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteValue(value);
                break;
                
            case 3:
                levelwiseDisplay();
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
// Binary Search Tree with insert, delete, search operations | Time: O(h) avg O(log n), worst O(n) | Space: O(h)