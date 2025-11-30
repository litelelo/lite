#include <iostream>
using namespace std;

struct Appointment {
    int start, end;
    Appointment* next;
};

class Schedule {
    Appointment* head;
    int minDur, maxDur;
public:
    Schedule(int min, int max) : minDur(min), maxDur(max), head(NULL) {}

    void book(int start, int end) {
        int duration = end - start;
        if (duration < minDur || duration > maxDur) {
            cout << "Invalid duration.\n";
            return;
        }
        
        Appointment* newNode = new Appointment{start, end, NULL};
        if (!head || head->start >= end) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Appointment* temp = head;
        while (temp->next && temp->next->start < start) {
            temp = temp->next;
        }
        
        if (temp->end > start || (temp->next && temp->next->start < end)) {
            cout << "Overlap detected.\n";
            delete newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Booked.\n";
        }
    }

    void cancel(int start) {
        if (!head) return;
        if (head->start == start) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Appointment* temp = head;
        while (temp->next && temp->next->start != start) {
            temp = temp->next;
        }
        if (temp->next) {
            Appointment* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void display() {
        Appointment* temp = head;
        while (temp) {
            cout << "[" << temp->start << "-" << temp->end << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    void sort() {
        // Already sorted by insertion logic, but implementing bubble sort for completeness if needed
        // Since insertion maintains order, this is redundant but per problem statement:
        if (!head) return;
        for (Appointment* i = head; i->next != NULL; i = i->next) {
            for (Appointment* j = i->next; j != NULL; j = j->next) {
                if (i->start > j->start) {
                    swap(i->start, j->start);
                    swap(i->end, j->end);
                }
            }
        }
    }
};

int main() {
    int minDur, maxDur, choice, start, end;
    
    cout << "Enter minimum appointment duration (hours): ";
    cin >> minDur;
    cout << "Enter maximum appointment duration (hours): ";
    cin >> maxDur;
    
    Schedule s(minDur, maxDur);
    
    while (true) {
        cout << "\n1. Book Appointment\n2. Cancel Appointment\n3. Display Schedule\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter start time: ";
            cin >> start;
            cout << "Enter end time: ";
            cin >> end;
            s.book(start, end);
        } else if (choice == 2) {
            cout << "Enter start time of appointment to cancel: ";
            cin >> start;
            s.cancel(start);
        } else if (choice == 3) {
            s.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Linked list appointment scheduler with time validation and overlap detection | Time: O(n)
