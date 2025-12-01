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

int count(){
    int count = 0;
    node temp = first;
    while(temp != NULL){
        count++;
        temp = temp->next; 
    }
    return count;
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

void insertAtBeginning(){
    node newnode = accept();
    
    if(first == NULL){
        first = newnode;
    }
    else{
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
    cout << "\nInserted at beginning!";
}

void insertAtEnd(){
    node newnode = accept();
    
    if(first == NULL){
        first = newnode;
    }
    else{
        node temp = first;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    cout << "\nInserted at end!";
}

void insertAtPosition(){
    int pos;
    cout << "\nEnter position (1 to " << count()+1 << "): ";
    cin >> pos;
    
    if(pos == 1){
        insertAtBeginning();
        return;
    }
    
    node newnode = accept();
    node temp = first;
    
    for(int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        cout << "\nPosition out of bounds!";
        delete newnode;
        return;
    }
    
    newnode->next = temp->next;
    newnode->prev = temp;
    
    if(temp->next != NULL){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    
    cout << "\nInserted at position " << pos << "!";
}

void deleteFromBeginning(){
    if(first == NULL){
        cout << "\nList is empty!";
        return;
    }
    
    node temp = first;
    first = first->next;
    
    if(first != NULL){
        first->prev = NULL;
    }
    
    cout << "\nDeleted " << temp->data << " from beginning!";
    delete temp;
}

void deleteFromEnd(){
    if(first == NULL){
        cout << "\nList is empty!";
        return;
    }
    
    if(first->next == NULL){
        cout << "\nDeleted " << first->data << " from end!";
        delete first;
        first = NULL;
        return;
    }
    
    node temp = first;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    cout << "\nDeleted " << temp->data << " from end!";
    delete temp;
}

void deleteFromPosition(){
    if(first == NULL){
        cout << "\nList is empty!";
        return;
    }
    
    int pos;
    cout << "\nEnter position (1 to " << count() << "): ";
    cin >> pos;
    
    if(pos == 1){
        deleteFromBeginning();
        return;
    }
    
    node temp = first;
    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        cout << "\nPosition out of bounds!";
        return;
    }
    
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    
    cout << "\nDeleted " << temp->data << " from position " << pos << "!";
    delete temp;
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


int main(){
    int c;

    do{
        cout << "\n========== MENU ==========\n";
        cout << "1. Add new element (at end)\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at end\n";
        cout << "4. Insert at position\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete from position\n";
        cout << "8. Display list\n";
        cout << "9. Count elements\n";
        cout << "10. Exit\n";
        cout << "=========================\n";
        cout << "Your choice: ";
        cin >> c;

        switch(c){
            case 1:
                addnew();
                break;
                
            case 2: 
                insertAtBeginning();
                break;
            
            case 3:
                insertAtEnd();
                break;

            case 4:
                insertAtPosition();
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                deleteFromPosition();
                break;

            case 8:
                display();
                break;

            case 9:
                cout << "\nTotal elements: " << count();
                break;

            case 10:
                cout << "\nExiting...\n";
                break;

            default: 
                cout << "\nInvalid choice!";
        }
    } while (c != 10);

    return 0;
}
// Doubly linked list with insert (beginning, end, position) and delete (beginning, end, position) operations | Time: O(n) for position ops, O(1) for ends