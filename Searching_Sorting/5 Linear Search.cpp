#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string division;
    string year;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << " (RollNo Name Division Year): ";
        cin >> students[i].rollNo >> students[i].name >> students[i].division >> students[i].year;
    }

    int searchRoll;
    string searchName, searchDiv, searchYear;
    
    cout << "Enter Roll No to search: ";
    cin >> searchRoll;
    cout << "Enter Name to search: ";
    cin >> searchName;
    cout << "Enter Division to search: ";
    cin >> searchDiv;
    cout << "Enter Year to search: ";
    cin >> searchYear;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].rollNo == searchRoll && students[i].name == searchName && 
            students[i].division == searchDiv && students[i].year == searchYear) {
            cout << "Student found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }

    return 0;
}
// Linear search for student by multiple attributes | Time: O(n)
