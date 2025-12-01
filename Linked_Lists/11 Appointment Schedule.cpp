#include <iostream>
using namespace std;

typedef struct SLL{
    int start;
    int end;
    struct SLL *next;
} *node;

node first = NULL;
const int MINDURATION = 1;
const int MAXDURATION = 2;

void displayoccupied(){
    cout << "\nOccupied slots: ";
    if(first == NULL){
        cout << "\nThere are no scheduled appointments.";
    }

    node current = first;
    while(current != NULL){
        cout << "\t\n" << current->start << "-" << current->end;
        current = current->next;
    }
}

bool checkconflicts(int start, int end){
    node current = first;
    while(current != NULL){
        if(!(end <= current->start || start >=current->end)){
            cout << "\nERROR: There is another appointment scheduled for " << current->start << "-" << current->end << " !!!";
            return false;
        }

        current = current->next;
    }

    return true;
}

node accept(){
    cout << "\n ----- ENTER APPOINTMENT TIMINGS ----- ";
    cout << "\n\nWorking hours: 08:00 - 18:00";
    bool valid = false;
    int start, end;
    do{
        cout << "\nEnter start time: ";
        cin >> start;
        cout << "Enter end time: ";
        cin >> end;

        int duration = end-start;
        if(duration < MINDURATION || duration > MAXDURATION){
            cout << "\nERROR: Invalid duration. All appointments must be " << MINDURATION << "-" << MAXDURATION << "hours long !!";
        }

        if(start<8 || end>18 || start>=end){
            cout << "\nERROR: The working hours are between 08:00 and 18:00. The end timing must be 1-3 hours after the start timing.";
        }

        if(duration >= MINDURATION && duration <= MAXDURATION && 
           start >= 8 && end <= 18 && start < end && 
           checkconflicts(start, end)){
            valid = true;
        }
    } while (valid == false);

    node a = new SLL;
    a->start = start;
    a->end = end;
    a->next = first;
    first = a;

    cout << "\nAppointment booked: " << start << "-" << end;
}

void cancelappointment() {
    displayoccupied();
    
    if (first == NULL) {
        cout << "No appointments to cancel!\n";
        return;
    }
    
    int start, end;
    cout << "\nEnter start time to cancel: ";
    cin >> start;
    cout << "Enter end time to cancel: ";
    cin >> end;

    node temp = first;
    //removing first
    if (first->start == start && first->end == end) {
        first = first->next;
        delete temp;
        cout << "\nCancelled appointment: " << start << "-" << end;
        return;
    }

    node current = first;
    while(current->next != NULL){
        if(current->next->start == start && current->next->end == end){
            node temp = current-> next;
            current->next = temp->next;
            delete temp;
            cout << "\nCancelled appointment: " << start << "-" << end;
            return; 
        }

        current = current->next;
    }

    cout << "\nAppointment not found!";
}

// d) Sort by swapping data values (bubble sort)
void sort_dataswap() {
    if (first == NULL || first->next == NULL) {
        cout << "Nothing to sort!\n";
        return;
    }
    
    bool swapped = true;
    while (swapped) {
        swapped = false;
        node current = first;
        
        while (current->next) {
            if (current->start > current->next->start) {
                // Swap data values
                int tempStart = current->start;
                int tempEnd = current->end;
                current->start = current->next->start;
                current->end = current->next->end;
                current->next->start = tempStart;
                current->next->end = tempEnd;
                swapped = true;
            }
            current = current->next;
        }
    }
    cout << "Appointments sorted by data swap!\n";
}

void sortByPointerManipulation() {
    if (first == NULL || first->next == NULL) {
        cout << "Nothing to sort!\n";
        return;
    }
    
    node sorted = NULL;
    
    while (first != NULL) {
        node current = first;
        first = first->next;
        
        // Insert current node in sorted list
        if (!sorted || current->start < sorted->start) {
            // Insert at beginning
            current->next = sorted;
            sorted = current;
        } else {
            // Find correct position and insert
            node temp = sorted;
            while (temp->next && temp->next->start < current->start) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    
    first = sorted;
    cout << "Appointments sorted by pointer manipulation!\n";
}

void displayAllAppointments() {
    cout << "\nAll scheduled appointments:\n";
    if (first == NULL) {
        cout << "No appointments scheduled.\n";
        return;
    }
    
    int index = 0;
    node current = first;
    while (current != NULL) {
        cout << "Appointment " << index << ": " << current->start 
             << "-" << current->end << " (duration: " 
             << (current->end - current->start) << " hours)\n";
        current = current->next;
        index++;
    }
}

int main() {
    int choice;
    
    cout << "=== APPOINTMENT SCHEDULER ===\n";
    cout << "Working hours: 8-18 (24-hour format)\n";
    cout << "Duration requirements: " << MINDURATION << "-" << MAXDURATION << " hours\n";
    
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Display occupied slots\n";
        cout << "2. Book new appointment\n";
        cout << "3. Cancel existing appointment\n";
        cout << "4. Sort appointments (data swap)\n";
        cout << "5. Sort appointments (pointer manipulation)\n";
        cout << "6. Display all appointments\n";
        cout << "7. Exit\n";
        cout << "=========================\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        
        switch (choice) {
            case 1: 
                displayoccupied(); 
                break;
                
            case 2: 
                accept(); 
                break;
                
            case 3: 
                cancelappointment(); 
                break;
                
            case 4: 
                sort_dataswap(); 
                break;
                
            case 5: 
                sortByPointerManipulation(); 
                break;
                
            case 6: 
                displayAllAppointments(); 
                break;
                
            case 7: 
                cout << "\nThank you for using Appointment Scheduler!\n";
                cout << "Goodbye!\n"; 
                break;
                
            default: 
                cout << "\nInvalid choice! Please enter a number between 1-7.\n";
                break;
        }
        
        if (choice != 7) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 7);
    
    return 0;
}
// Singly linked list for appointment scheduling with time slot management, conflict checking, sorting (data swap & pointer manipulation) | Time: O(n) per operation