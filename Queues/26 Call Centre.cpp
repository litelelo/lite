#include <iostream>
#include <string>
using namespace std;

typedef struct SLL{
    int call_id;
    string customer_name;
    struct SLL *next;
} *node;

node front = NULL;
node rear = NULL;
int current_call_id = 1;

node accept(){
    node a = new SLL;
    a->call_id = current_call_id++;
    
    cout << "\nEnter customer name: ";
    cin.ignore();
    getline(cin, a->customer_name);
    
    a->next = NULL;
    return a;
}

void enqueuecall(){
    node newnode = accept();
    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }

    cout << "\nCall enqueued! Call ID: " << newnode->call_id << " from " << newnode->customer_name;
}

void dequeuecall(){
    if(front == NULL){
        cout << "\nNo calls in queue. System is waiting...";
        return;
    }

    node temp = front;
    int call_id = temp->call_id;
    string customer = temp->customer_name;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    delete temp;
    cout << "\nCall dequeued! Agent assisting Call ID: " << call_id << " from " << customer;
}

void display(){
    if(front == NULL){
        cout << "\nNo calls in queue. System is waiting...";
        return;
    }
    
    node temp = front;
    cout << "\nCurrent calls in queue: ";
    while(temp != NULL){
        cout << "\n\tCall ID: " << temp->call_id << " - Customer: " << temp->customer_name;
        temp = temp->next;
    }
    cout << "\n";
}

int main(){
    int c;
    
    cout << "=== CALL CENTER QUEUE SYSTEM ===\n";
    cout << "First-Come, First-Served Basis\n";

    do{
        cout << "\n\n========== MENU ==========\n";
        cout << "1. Enqueue Customer Call\n";
        cout << "2. Dequeue Call (Agent Assist)\n";
        cout << "3. Display Current Queue\n";
        cout << "4. Exit\n";
        cout << "=========================\n";
        cout << "Your choice: ";
        cin >> c;

        switch(c){
            case 1: 
                enqueuecall();
                break;
            
            case 2:
                dequeuecall();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "\nExiting call center system. Thanks!";
                break;

            default: 
                cout << "\nInvalid input.";
        }
    } while (c != 4);

    return 0;
}
// Priority queue (linked list) for call center management | Operations: enqueue with priority, dequeue, display | Time: O(n) enqueue, O(1) dequeue