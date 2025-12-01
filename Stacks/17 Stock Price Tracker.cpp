#include <iostream>
using namespace std;

typedef struct SLL{
    int price;
    struct SLL *next;
} *node;

node top = NULL;

void record(int p){
    node newnode = (node)malloc(sizeof(node));
    newnode->price = p;
    newnode->next = top;
    top = newnode;
}

void remove(){
    if(top==NULL){
        cout << "\nERROR!! STACK UNDERFLOW!" << endl;
    }
    else{
        cout << "\nPrice being removed: " << top->price << endl;
        top = top->next;
    }
}

void latest(){
    if(top==NULL){
        cout << "\nStack is empty! Whoops!" << endl;
    }
    else{
        cout << "\nLatest recorded price: " << top->price << endl;
    }
}

void isEmpty(){
    if(top==NULL){
        cout << "\nStack is empty!" << endl;
    }
    else{
        cout << "\nStack is NOT empty!" <<endl;
    }
}

void display(){
    if(top==NULL){
        cout << "\nStack is empty! Whoops!" << endl;
    }
    else{
        node temp = top;
        cout << endl;
        while(temp->next != NULL){
            cout << "\t" << temp->price << endl;
            cout << "\t|" << endl;
            temp = temp->next;
        }
        cout << "\t" << temp->price << endl;
    }
}

int main(){
    cout << "---------- STOCK PRICE RECORDS ----------" << endl;

    int c = 0;

    do{
        cout << "\nWhat operation would you like to perform?\n 1. Record new price\n 2. Delete last price\n 3. Retrieve latest price\n 4. Check if price stack is empty\n 5. Display prices\n 6. Exit\nYour choice: ";
        cin >> c;

        switch(c){
            case 1: 
                cout << "\nEnter new price: ";   
                int p;
                cin >> p; 
                record(p);
                break;
            
            case 2: 
                remove();
                break;
            
            case 3:
                latest();
                break;

            case 4: 
                isEmpty();
                break;
            
            case 5: 
                display();
                break;
            
            case 6:
                cout << "Exiting. Thanks!";
                break;

            default: 
                cout << "Invalid choice!";
        }
    } while (c!=6);
}
// Stack (linked list) for stock price tracking | Operations: record, remove, latest, isEmpty, display | Time: O(1) for all operations