#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    int id;
    string name;
    string problem;

    Patient() {}
    Patient(int i, const string &n, const string &p) {
        id = i;
        name = n;
        problem = p;
    }
};

class Node {
public:
    Patient info;
    Node *next;

    Node(const Patient &p) {
        info = p;
        next = NULL;
    }
};

class PatientQueue {
    Node *front;
    Node *rear;
    int nextId;    // for ticket number

public:
    PatientQueue() {
        front = rear = NULL;
        nextId = 1;
    }

    bool isEmpty() {
        return front == NULL;
    }

    // Check-in patient (enqueue)
    void checkIn(const string &name, const string &problem) {
        Patient p(nextId++, name, problem);
        Node *n = new Node(p);

        if (rear == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }

        cout << "Patient checked in. Ticket/ID = " << p.id << "\n";
    }

    // Assign next patient to doctor (dequeue)
    void assignPatient(const string &doctorName) {
        if (isEmpty()) {
            cout << "No patients waiting.\n";
            return;
        }

        Node *temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;

        Patient p = temp->info;
        delete temp;

        cout << "Assigned Patient ID " << p.id
             << " (" << p.name << ", " << p.problem << ") "
             << "to Doctor " << doctorName << ".\n";
    }

    // Display waiting patients
    void displayWaiting() {
        if (isEmpty()) {
            cout << "No patients in the waiting list.\n";
            return;
        }

        cout << "Waiting Patients (First-Come, First-Served):\n";
        Node *t = front;
        while (t != NULL) {
            cout << "ID: " << t->info.id
                 << ", Name: " << t->info.name
                 << ", Problem: " << t->info.problem << "\n";
            t = t->next;
        }
    }
};

string inputLine() {
    string s;
    cin >> ws;
    getline(cin, s);
    return s;
}

int main() {
    PatientQueue pq;
    int choice;

    do {
        cout << "\n--- Medical Clinic Patient Queue ---\n";
        cout << "1. Check-in new patient\n";
        cout << "2. Assign next patient to doctor\n";
        cout << "3. Display waiting patients\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient name: ";
            string name = inputLine();
            cout << "Enter patient problem: ";
            string problem = inputLine();
            pq.checkIn(name, problem);

        } else if (choice == 2) {
            cout << "Enter doctor name: ";
            string dname = inputLine();
            pq.assignPatient(dname);

        } else if (choice == 3) {
            pq.displayWaiting();
        }

    } while (choice != 0);

    return 0;
}
