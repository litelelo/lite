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
    if(n == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    
    node stack[100];
    int top = -1;
    node current = n;
    
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        
        current = stack[top--];
        cout << current->element << " ";
        current = current->right;
    }
    cout << endl;
}

void preorder(node n){
    if(n == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    
    node stack[100];
    int top = -1;
    stack[++top] = n;
    
    while(top != -1){
        node current = stack[top--];
        cout << current->element << " ";
        
        if(current->right != NULL){
            stack[++top] = current->right;
        }
        if(current->left != NULL){
            stack[++top] = current->left;
        }
    }
    cout << endl;
}

int countLeafNonRecursive(node n){
    if(n == NULL){
        return 0;
    }
    
    node stack[100];
    int top = -1;
    stack[++top] = n;
    int count = 0;
    
    while(top != -1){
        node current = stack[top--];
        
        if(current->left == NULL && current->right == NULL){
            count++;
        }
        
        if(current->right != NULL){
            stack[++top] = current->right;
        }
        if(current->left != NULL){
            stack[++top] = current->left;
        }
    }
    return count;
}

void mirrorNonRecursive(node n){
    if(n == NULL){
        return;
    }
    
    node stack[100];
    int top = -1;
    stack[++top] = n;
    
    while(top != -1){
        node current = stack[top--];
        
        // Swap left and right children
        node temp = current->left;
        current->left = current->right;
        current->right = temp;
        
        if(current->left != NULL){
            stack[++top] = current->left;
        }
        if(current->right != NULL){
            stack[++top] = current->right;
        }
    }
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
                    cout << "Number of Leaf Nodes: " << countLeafNonRecursive(root) << endl;
                }
                break;
                
            case 5:
                if(root == NULL){
                    cout << "Tree is empty!" << endl;
                }
                else{
                    cout << "Original Tree - Inorder: ";
                    inorder(root);
                    mirrorNonRecursive(root);
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
// Binary Tree non-recursive traversals using stack, count leaf nodes, mirror image | Time: O(n) | Space: O(h)