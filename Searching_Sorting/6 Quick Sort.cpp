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

void quickSort(vector<Student>& students, int low, int high, int& swaps) {
    if (low >= high) return;

    int pivot = students[high].marks;
    int lt = low, gt = high, i = low;

    while (i <= gt) {
        if (students[i].marks < pivot) {
            swap(students[lt], students[i]);
            swaps++;
            lt++; 
            i++;
        } else if (students[i].marks > pivot) {
            swap(students[i], students[gt]);
            swaps++;
            gt--;
        } else {
            i++;
        }
    }

    quickSort(students, low, lt - 1, swaps);
    quickSort(students, gt + 1, high, swaps);
}

int main(){
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    vector<Student> students(n);

    cout << "Enter student details: \n";
    for(int i = 0; i < n; i++){
        cout << "\nFor student " << i + 1 << ":\n";
        int rollno;
        while (true) {
            cout << "Roll No: ";
            cin >> rollno;
            
            if (rollno <= 0) {
                cout << "Error: Roll number must be positive. Please try again.\n";
                continue;
            }
            
            if (isDuplicateRollNo(students, rollno, i)) {
                cout << "Error: Roll number " << rollno << " already exists. Please enter a different roll number.\n";
                continue;
            }
            
            students[i].rollno = rollno;
            break;
        }
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
    }

    int quickSortSwaps = 0;
    quickSort(students, 0, n - 1, quickSortSwaps);

    cout << "\nSorted list of students by marks in ascending order:\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].rollno << ". " << students[i].name << " - Marks: " << students[i].marks << "\n";
    }
    
    cout << "\nMinimum marks: " << students[0].marks;
    cout << "\nMaximum marks: " << students[n-1].marks;
    
    cout << "\nTotal swaps made: " << quickSortSwaps << "\n";

    return 0;
}
// Quick sort (3-way partitioning) to sort students by marks with min/max | Time: O(n log n) avg, O(n²) worst | Space: O(log n)