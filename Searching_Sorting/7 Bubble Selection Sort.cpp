#include <iostream>
using namespace std;

struct Student {
    int id;
    float marks;
    int rollNo;
};

void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) { // Descending for topper = 1
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        cout << "Pass " << i + 1 << ": ";
        for(int k=0; k<n; k++) cout << arr[k].marks << " ";
        cout << endl;
    }
}

void selectionSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].marks > arr[max_idx].marks)
                max_idx = j;
        }
        Student temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
        
        cout << "Pass " << i + 1 << ": ";
        for(int k=0; k<n; k++) cout << arr[k].marks << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student s1[100], s2[100];
    for (int i = 0; i < n; i++) {
        s1[i].id = i + 1;
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> s1[i].marks;
        s2[i] = s1[i];
    }

    cout << "\nBubble Sort (Descending):\n";
    bubbleSort(s1, n);
    
    cout << "\nSelection Sort (Descending):\n";
    selectionSort(s2, n);

    cout << "\nRoll No Assignment:\n";
    for(int i=0; i<n; i++) {
        s1[i].rollNo = i + 1;
        cout << "Rank " << s1[i].rollNo << ": Marks " << s1[i].marks << endl;
    }

    return 0;
}
