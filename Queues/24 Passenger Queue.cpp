#include <iostream>
using namespace std;

typedef struct SLL{
    int passenger_id;
    struct SLL *next;
} *node;

node front = NULL;
node rear = NULL;
int current_passenger = 1;

node accept(){
    node a  = new SLL;
    a->passenger_id = current_passenger++;
    
    a->next = NULL;
    return a;
}

void addpassenger(){
    node newnode = accept();
    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }

    cout << "\nPassenger added! Passenger #" << newnode->passenger_id << " is now in the queue.";
}

void removepassenger(){
    if(front == NULL){
        cout << "\nThere are no passengers waiting!";
        return;
    }

    node temp = front;
    int dequeuedValue = temp->passenger_id;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    delete temp;
    cout << "\nPassenger #" << dequeuedValue << " has been served and removed.";
}

void displayfront(){
    if(front == NULL){
        cout << "\nNo passengers in queue!";
        return;
    }
    
    cout << "\nPassenger at the front of the queue: Passenger #" << front->passenger_id;
}

void display(){
    if(front == NULL){
        cout << "\nNo passengers in queue!";
        return;
    }
    
    node temp = front;
    cout << "\nCurrent queue of passengers waiting: ";
    while(temp != NULL){
        cout << "P#" << temp->passenger_id;
        if(temp->next != NULL){
            cout << " <- ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

int countpassengers(){
    int count = 0;
    node temp = front;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    int c;
    
    cout << "=== TICKET AGENT QUEUE SYSTEM ===\n";
    cout << "Passengers will be served on first-come, first-served basis\n";

    do{
        cout << "\n\n========== MENU ==========\n";
        cout << "1. Add a passenger to queue\n";
        cout << "2. Display front passenger\n";
        cout << "3. Serve front passenger (remove)\n";
        cout << "4. Display entire queue\n";
        cout << "5. Exit\n";
        cout << "=========================\n";
        cout << "Your choice: ";
        cin >> c;

        switch(c){
            case 1: 
                addpassenger();
                break;
            
            case 2:
                displayfront();
                break;

            case 3:
                removepassenger();
                break;

            case 4:
                display();
                break;

            case 5:
                {
                    int remaining = countpassengers();
                    cout << "\nExiting the system.";
                    cout << "\nNumber of passengers left in queue: " << remaining;
                    cout << "\nThanks for using the ticket system!";
                    break;
                }

            default: 
                cout << "\nInvalid input.";
        }
    } while (c != 5);

    return 0;
}
// Queue using linked list for passenger ticketing system | Operations: book ticket, cancel, display queue | Time: O(1) | Space: O(n)
