#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class PatientQueue {
    string patients[MAX];
    int front, rear;
public:
    PatientQueue() { front = -1; rear = -1; }

    void checkIn(string name) {
        if (rear == MAX - 1) {
            cout << "Queue Full\n";
            return;
        }
        if (front == -1) front = 0;
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
    PatientQueue q;
    q.checkIn("John");
    q.checkIn("Doe");
    q.assignDoctor();
    q.assignDoctor();
    q.assignDoctor();
    return 0;
}
// Linear queue for patient-doctor assignment (FCFS) | Time: O(1)
