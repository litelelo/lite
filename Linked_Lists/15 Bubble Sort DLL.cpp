#include <iostream>
using namespace std;

typedef struct DLL{
    int data;
    struct DLL *next;
    struct DLL *prev;
} *node;

node first = NULL;
int flag = 0;

node accept(){
    node a = new DLL;
    cout << "\nEnter value: ";
    cin >> a->data;
    a->next = NULL;
    a->prev = NULL;
    return a;
}

void addnew(){
    node newnode = accept();

    if(flag == 0){
        first = newnode;
        flag = 1;
    }
    else {
        node a = first;
        while (a->next != NULL){
            a = a->next;
        }
        a->next = newnode;
        newnode->prev = a;
    }
}

int count(){
    int count = 0;
    node temp = first;
    while(temp != NULL){
        count++;
        temp = temp->next; 
    }

    return count;
}

void display(){
    node temp = first;
    cout << "\nList:\n";
    cout << "NULL <-> ";
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next; 
    }
    cout << "NULL\n";
}

void bubblesort(){
    int swapped;
    
    do{
        swapped = 0;
        node temp = first;
        node last = nullptr;

        while(temp->next != NULL){
            if(temp->data > temp->next->data){
                int x = temp->data;
                temp->data = temp->next->data;
                temp->next->data = x;

                swapped = 1;
            }

            temp = temp->next;
        }

        last = temp;
    } while(swapped != 0);
} 

int main(){
    int c, cont=1;

    do{
        cout << "\nWhat operation would you like to perform?\n 1. Add members\n 2. Display members\n 3. Sort list\n 4. Exit\nYour choice: ";
        cin >> c;

        switch(c){
            case 1: 
                addnew();
                break;
            
            case 2:
                display();
                break;

            case 3:
                bubblesort();
                display();
                break;

            case 4: break;

            default: cout << "Invalid";
        }
    } while (c != 4);

    return 0;
}
// Bubble sort implementation using doubly linked list | Time: O(n²) | Space: O(1)