#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct DCLL{
    int seatNumber;
    bool isBooked;
    struct DCLL *next;
    struct DCLL *prev;
} *node;

node rowHeads[8] = {NULL}; //because 8 rows
const int ROWS = 8;
const int SEATS_PER_ROW = 8;

node createSeat(int seatNum) {
    node newSeat = new DCLL;
    newSeat->seatNumber = seatNum;
    newSeat->isBooked = false;
    newSeat->next = NULL;
    newSeat->prev = NULL;
    return newSeat;
}

void initializeSeats() {
    for (int row = 0; row < ROWS; row++) {
        node first = createSeat(1);
        rowHeads[row] = first;
        node current = first;
        
        // create remaining seats for this row
        for (int seat = 2; seat <= SEATS_PER_ROW; seat++) {
            node newSeat = createSeat(seat);
            current->next = newSeat;
            newSeat->prev = current;
            current = newSeat;
        }
        
        current->next = first;
        first->prev = current;
    }
}

// function to randomly book some seats initially
void randomlyBookSeats() {
    srand(time(NULL));
    
    for (int row = 0; row < ROWS; row++) {
        int numBookings = rand() % 4; //booking 0-3 random seats in any row
        
        for (int i = 0; i < numBookings; i++) {
            int seatToBook = (rand() % SEATS_PER_ROW) + 1;
            
            node temp = rowHeads[row];
            do {
                if (temp->seatNumber == seatToBook) {
                    temp->isBooked = true;
                    break;
                }
                temp = temp->next;
            } while (temp != rowHeads[row]);
        }
    }
}


void displaySeats() {
    cout << "\n=== GALAXY MULTIPLEX SEATING ===\n\n";
    cout << "  Seat: 1  2  3  4  5  6  7  8\n";
    cout << "        ----------------------\n";
    
    for (int row = 0; row < ROWS; row++) {
        cout << "Row " << (row + 1) << ": ";
        
        node temp = rowHeads[row];
        do {
            if (temp->isBooked) {
                cout << " X ";
            } else {
                cout << " O ";
            }
            temp = temp->next;
        } while (temp != rowHeads[row]);
        
        cout << "\n";
    }
    
    cout << "\nLegend: O = Available, X = Booked\n";
}

void bookSeat() {
    int row, seat;
    
    cout << "\nEnter row number (1-8): ";
    cin >> row;
    
    if (row < 1 || row > ROWS) {
        cout << "Invalid row number!\n";
        return;
    }
    
    cout << "Enter seat number (1-8): ";
    cin >> seat;
    
    if (seat < 1 || seat > SEATS_PER_ROW) {
        cout << "Invalid seat number!\n";
        return;
    }
    
    node temp = rowHeads[row - 1];
    do {
        if (temp->seatNumber == seat) {
            if (temp->isBooked) {
                cout << "Seat " << seat << " in Row " << row << " is already booked!\n";
            } else {
                temp->isBooked = true;
                cout << "Seat " << seat << " in Row " << row << " has been successfully booked!\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != rowHeads[row - 1]);
}

void cancelBooking() {
    int row, seat;
    
    cout << "\nEnter row number (1-8): ";
    cin >> row;
    
    if (row < 1 || row > ROWS) {
        cout << "Invalid row number!\n";
        return;
    }
    
    cout << "Enter seat number (1-8): ";
    cin >> seat;
    
    if (seat < 1 || seat > SEATS_PER_ROW) {
        cout << "Invalid seat number!\n";
        return;
    }
    
    node temp = rowHeads[row - 1];
    do {
        if (temp->seatNumber == seat) {
            if (!temp->isBooked) {
                cout << "Seat " << seat << " in Row " << row << " is not booked!\n";
            } else {
                temp->isBooked = false;
                cout << "Booking for Seat " << seat << " in Row " << row << " has been cancelled!\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != rowHeads[row - 1]);
}

void bookMultipleSeats() {
    int numSeats;
    cout << "\nHow many seats do you want to book? ";
    cin >> numSeats;
    
    for (int i = 0; i < numSeats; i++) {
        cout << "\nBooking seat " << (i + 1) << " of " << numSeats << ":\n";
        bookSeat();
    }
}

int main() {
    int choice;
    
    cout << "=== GALAXY MULTIPLEX TICKET RESERVATION SYSTEM ===\n";
    cout << "Initializing seating arrangement...\n";
    
    initializeSeats();
    
    randomlyBookSeats();
    
    cout << "System initialized with random bookings!\n";
    
    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Display current seat availability\n";
        cout << "2. Book a single seat\n";
        cout << "3. Book multiple seats\n";
        cout << "4. Cancel a booking\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displaySeats();
                break;
                
            case 2:
                bookSeat();
                break;
                
            case 3:
                bookMultipleSeats();
                break;
                
            case 4:
                cancelBooking();
                break;
                
            case 5:
                cout << "\nThank you for using Galaxy Multiplex Reservation System!\n";
                break;
                
            default:
                cout << "\nInvalid choice! Please try again.\n";
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}
// Doubly circular linked list for 8x8 seat reservation system | Operations: display, book, cancel | Time: O(n) for search, O(1) for insert/delete