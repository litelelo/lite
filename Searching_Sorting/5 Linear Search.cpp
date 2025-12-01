#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Student{
    char name[50];
    int rollno;

    public:
    void getdata();
    void printdata();
    int checkroll();
    string checkname();
    void sortStudents(vector<Student>& students, int n);
};

void Student::getdata(){
    cout << " Roll No: ";
    cin >> rollno;
    cout << " Name: ";
    cin >> name;
}

int Student::checkroll(){
    return rollno;
}

string Student::checkname(){
    return string(name);
}

void Student::printdata(){
    cout << " Name: " << name << "\n";
    cout << " Roll No: " << rollno << "\n";
}

void Student::sortStudents(vector<Student>& students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].checkroll() > students[j + 1].checkroll()) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main(){
    system("cls");
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    vector<Student> students(n);

    cout << "Enter student details: \n";
    for(int i = 0; i<n; i++){
        cout << " For student " << i+1 << ":\n";
        students[i].getdata();
    }

    char searchName[50];
    int searchRollNo;
    cout << "\nEnter details of student to search: \n";
    cout << " Roll No: ";
    cin >> searchRollNo;
    cout << " Name: ";
    cin >> searchName;

    int low = 0, high = n - 1;
    int mid;

    bool found = false;
   
    while(low<=high){
        mid = (low + high) / 2;
        if(students[mid].checkroll() == searchRollNo && students[mid].checkname() == string(searchName)){
            found = true;
            cout << "\nStudent found:\n";
            students[mid].printdata();
            break;
        }
        else if(students[mid].checkroll() < searchRollNo){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(!found){
        cout << "Student not found.\n";
    }

    return 0;
}
// Binary search to find student by roll number and name | Time: O(log n) | Space: O(1)