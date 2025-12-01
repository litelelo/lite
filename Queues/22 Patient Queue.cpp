#include <iostream>
using namespace std;

typedef struct SLL{
    int doc_id;
    struct SLL *next;
} *node;

node front = NULL;
node rear = NULL;
int current_doc = 1;
const int totaldocs = 10;

node accept(){
    node a  = new SLL;
    a->doc_id = current_doc;
    
    current_doc++;
    if(current_doc > totaldocs){
        current_doc = 1;
    }
    
    a->next = NULL;
    return a;
}

void addpatient(){
    node newnode = accept();
    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }

    cout << "\nPatient added! Patient has been assigned to doctor #" << newnode->doc_id;
}

void removepatient(){
    if(front == NULL){
        cout << "\nThere are no patients!";
        return;
    }

    node temp = front;
    int dequeuedValue = temp->doc_id;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    delete temp;
    cout << "\nPatient with doctor ID #" << dequeuedValue << " removed.";
}

void display(){
    if(front == NULL){
        cout << "\nNo patients in queue!";
        return;
    }
    
    node temp = front;
    cout << "\nPatients have been assigned to these doctors: ";
    while(temp != NULL){
        cout << "Dr." << temp->doc_id;
        if(temp->next != NULL){
            cout << " <- ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

int main(){
    int c;
    
    cout << "=== PATIENT-DOCTOR ASSIGNMENT SYSTEM ===\n";
    cout << "Total doctors available: " << totaldocs << "\n";

    do{
        cout << "\n\n========== MENU ==========\n";
        cout << "1. Add a patient\n";
        cout << "2. Remove the first patient\n";
        cout << "3. Display current waiting queue\n";
        cout << "4. Exit\n";
        cout << "=========================\n";
        cout << "Your choice: ";
        cin >> c;

        switch(c){
            case 1: 
                addpatient();
                break;
            
            case 2:
                removepatient();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "\nExiting the system. Thanks!";
                break;

            default: 
                cout << "\nInvalid input.";
        }
    } while (c != 4);

    return 0;
}
// Circular queue for hospital patient management | Operations: enqueue, dequeue, display | Time: O(1) | Space: O(n)