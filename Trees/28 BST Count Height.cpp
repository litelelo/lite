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

// Function to count total number of nodes
int countNodes(node n){
    if(n == NULL){
        return 0;
    }
    return 1 + countNodes(n->left) + countNodes(n->right);
}

// Function to compute height of BST
int computeHeight(node n){
    if(n == NULL){
        return -1; // Height of empty tree is -1
    }
    
    int leftHeight = computeHeight(n->left);
    int rightHeight = computeHeight(n->right);
    
    // Return maximum of left and right heights + 1
    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}

// Function to create mirror image of BST
node mirrorImage(node n){
    if(n == NULL){
        return NULL;
    }
    
    // Create a new node with same value
    node mirror = new BT;
    mirror->element = n->element;
    
    // Recursively mirror left and right subtrees
    mirror->left = mirrorImage(n->right);  // Left becomes right
    mirror->right = mirrorImage(n->left);  // Right becomes left
    
    return mirror;
}

// Function to display tree in inorder
void inorder(node n){
    if(n != NULL){
        inorder(n->left);
        cout << n->element << " ";
        inorder(n->right);
    }
}

void display(){
    cout << "Inorder traversal: ";
    if(root == NULL){
        cout << "Tree is empty!" << endl;
    }
    else{
        inorder(root);
        cout << endl;
    }
}

int main(){
    int choice;
    node mirrorRoot = NULL;
    
    do{ 
        cout << "\n=== Binary Search Tree Operations ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Count Total Nodes" << endl;
        cout << "3. Compute Height" << endl;
        cout << "4. Create Mirror Image (with display)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                insert();
                cout << "Value inserted successfully!" << endl;
                break;
                
            case 2:
                cout << "Total number of nodes: " << countNodes(root) << endl;
                break;
                
            case 3:
                {
                    int height = computeHeight(root);
                    cout << "Height of BST: " << height << endl;
                }
                break;
                
            case 4:
                if(root == NULL){
                    cout << "Original tree is empty!" << endl;
                }
                else{
                    mirrorRoot = mirrorImage(root);
                    cout << "Mirror image created successfully!" << endl;
                    cout << "\nOriginal Tree - ";
                    display();
                    cout << "Mirror Tree - Inorder traversal: ";
                    inorder(mirrorRoot);
                    cout << endl;
                }
                break;
                
            case 5:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 5);
    
    return 0;
}
// BST with count nodes, leaf nodes, tree height, and inorder traversal | Time: O(n) for traversals | Space: O(h)
