#include <iostream>
using namespace std;

struct Seat {
    int seatNo;
    bool isBooked;
    Seat* next;
    Seat* prev;
};

class Row {
    Seat* head;
public:
    Row() {
        head = NULL;
        for (int i = 1; i <= 8; i++) {
            Seat* newSeat = new Seat{i, false, NULL, NULL};
            if (!head) {
                head = newSeat;
                head->next = head;
                head->prev = head;
            } else {
                Seat* tail = head->prev;
                tail->next = newSeat;
                newSeat->prev = tail;
                newSeat->next = head;
                head->prev = newSeat;
            }
        }
    }

    void display() {
        Seat* temp = head;
        do {
            cout << (temp->isBooked ? "[B]" : "[_]") << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void bookSeat(int seatNo) {
        Seat* temp = head;
        do {
            if (temp->seatNo == seatNo) {
                if (temp->isBooked) cout << "Already booked.\n";
                else {
                    temp->isBooked = true;
                    cout << "Booked.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Invalid seat.\n";
    }

    void cancelSeat(int seatNo) {
        Seat* temp = head;
        do {
            if (temp->seatNo == seatNo) {
                if (!temp->isBooked) cout << "Not booked.\n";
                else {
                    temp->isBooked = false;
                    cout << "Cancelled.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Invalid seat.\n";
    }
};

int main() {
    Row rows[8];
    int choice, r, s;
    while (true) {
        cout << "\n1. Display 2. Book 3. Cancel 4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 4) break;
        switch (choice) {
            case 1:
                for (int i = 0; i < 8; i++) {
                    cout << "Row " << i + 1 << ": ";
                    rows[i].display();
                }
                break;
            case 2:
                cout << "Enter Row (1-8) and Seat (1-8): ";
                cin >> r >> s;
                if (r >= 1 && r <= 8) rows[r - 1].bookSeat(s);
                break;
            case 3:
                cout << "Enter Row (1-8) and Seat (1-8): ";
                cin >> r >> s;
                if (r >= 1 && r <= 8) rows[r - 1].cancelSeat(s);
                break;
        }
    }
    return 0;
}
