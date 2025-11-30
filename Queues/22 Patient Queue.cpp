#include <iostream>
#include <string>
using namespace std;

class PatientQueue {
    string *patients;
    int front, rear, maxSize;
public:
    PatientQueue(int size) {
        maxSize = size;
        patients = new string[maxSize];
        front = -1;
        rear = -1;
    }

    void checkIn(string name) {
        if (rear == maxSize - 1) {
            cout << "Queue Full\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        patients[++rear] = name;
        cout << "Patient " << name << " checked in.\n";
    }

    void assignDoctor() {
        if (front == -1 || front > rear) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "Patient " << patients[front++] << " assigned to doctor.\n";
    }
};

int main() {
    int size, choice;
    string name;
    
    cout << "Enter queue size: ";
    cin >> size;
    PatientQueue q(size);
    
    while (true) {
        cout << "\n1. Check In Patient\n2. Assign Doctor\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter patient name: ";
            cin >> name;
            q.checkIn(name);
        } else if (choice == 2) {
            q.assignDoctor();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
// Linear queue for patient-doctor assignment (FCFS) | Time: O(1)
