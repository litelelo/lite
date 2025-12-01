#include <iostream>
#include <vector>
using namespace std;

struct Student {
    char name[50];
    int rollno;
    float marks;
};

bool isDuplicateRollNo(const vector<Student>& students, int rollno, int currentIndex) {
    for (int i = 0; i < currentIndex; i++) {
        if (students[i].rollno == rollno) {
            return true;
        }
    }
    return false;
}

void bubbleSort(vector<Student>& students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];          
                students[j] = students[j + 1];        
                students[j + 1] = temp;               
            }
        }
    }

    cout << "\nNew roll number list in order of highest marks:\n";
    for (int i = 0; i < n; i++) {
        students[i].rollno = i+1;
        cout << "Roll No: " << students[i].rollno << ". "  << students[i].name << " - Marks: " << students[i].marks << "\n";
    }
}

int main(){
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    vector<Student> students(n);

    cout << "Enter student details: \n";
    for(int i = 0; i < n; i++){
        cout << "For student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
    }

    bubbleSort(students, n);

    return 0;
}
// Bubble sort to assign roll numbers based on highest marks (descending) | Time: O(n²) | Space: O(1)