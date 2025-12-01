#include <iostream>
using namespace std;

typedef struct SLL{
    int coeff;
    int pow;
    struct SLL *next;
} *node;

node first1 = NULL;
node first2 = NULL;

node accept(){
    node a = new SLL;
    cout << "\nEnter power of variable: ";
    cin >> a->pow;
    cout << "Enter coefficient: ";
    cin >> a->coeff;
    a->next = NULL;

    return a;
}

void newpoly(node &f){
    int c;
    cout << "\n\nEnter polynomial values: \n";

    do{
        node newnode = accept();

        node temp = f;
        bool found = false;
        
        while(temp != NULL){
            if(temp->pow == newnode->pow){
                temp->coeff += newnode->coeff;
                delete newnode;  
                found = true;
                cout << "Term with same power found. Coefficients combined.";
                break;
            }
            temp = temp->next;
        }
        
        if(!found){
            if(f == NULL){
                f = newnode;
            }
            else {
                node a = f;
                while (a->next != NULL){
                    a = a->next;
                }
                a->next = newnode;
            }
        }

        cout << "\nDo you continue adding to the polynomial? (0 for no, 1 for yes): ";
        cin >> c;
    } while(c != 0);
}

void display(node &f){
    if(f == NULL){
        cout << "\nNo bits entered yet.";
        return;
    }

    node temp = f;
    while(temp->next != NULL){
        cout << temp->coeff << "x^" << temp->pow << " + ";
        temp = temp->next;
    }

    cout << temp->coeff << "x^" << temp->pow;
}

void addpolynomials(){
    node result = NULL;
    node p1 = first1;
    node p2 = first2;
    
    while(p1 != NULL && p2 != NULL){
        node newnode = new SLL;
        
        if(p1->pow == p2->pow){
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->pow > p2->pow){
            newnode->coeff = p1->coeff;
            newnode->pow = p1->pow;
            p1 = p1->next;
        }
        else{
            newnode->coeff = p2->coeff;
            newnode->pow = p2->pow;
            p2 = p2->next;
        }
        
        newnode->next = NULL;
        
        if(result == NULL){
            result = newnode;
        }
        else{
            node temp = result;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    
    //if there's still elements left in p1
    while(p1 != NULL){
        node newnode = new SLL;
        newnode->coeff = p1->coeff;
        newnode->pow = p1->pow;
        newnode->next = NULL;
        
        if(result == NULL){
            result = newnode;
        }
        else{
            node temp = result;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        p1 = p1->next;
    }
    
    while(p2 != NULL){
        node newnode = new SLL;
        newnode->coeff = p2->coeff;
        newnode->pow = p2->pow;
        newnode->next = NULL;
        
        if(result == NULL){
            result = newnode;
        }
        else{
            node temp = result;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        p2 = p2->next;
    }
    
    cout << "\nSum of polynomials: ";
    display(result); 
}

int main(){
    
    cout << "\nFor first polynomial: ";
    newpoly(first1);

    cout << "\n\nFor second polynomial: ";
    newpoly(first2);
            
    cout << "\nFirst polynomial: ";
    display(first1);

    cout << "\nSecond polynomial: ";
    display(first2);

    addpolynomials();
}
// Singly linked list for polynomial addition by combining like terms | Time: O(n+m) where n, m are term counts in two polynomials