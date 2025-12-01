#include <iostream>
#include <vector>
using namespace std;

class Employee{
    string name;
    float height;
    float weight;
    float avg;

    public:
    void accept();
    float getavg();
    void display();
};

void Employee::accept(){
    cout << "\tEnter employee name: ";
    cin >> name;
    cout << "\tEnter height: ";
    cin >> height;
    cout << "\tEnter weight: ";
    cin >> weight;
}

float Employee::getavg(){
    return (height + weight) / 2;
}

void Employee::display(){
    cout << name << " - Avg: " << getavg() << " (Height: " << height << ", Weight: " << weight << ")\n";
}

void merge(vector<Employee>& employees, int left, int mid, int right){
    int n1 = mid - left +1;
    int n2 = right - mid;

    vector<Employee> leftarr(n1);
    vector<Employee> rightarr(n2);

    for (int i = 0; i<n1; i++){
        leftarr[i] = employees[left+i];
    }

    for (int j = 0; j<n2; j++){
        rightarr[j] = employees[mid+1+j];
    }

    int i = 0, j = 0, k = left;

    while(i<n1 && j<n2){
        if(leftarr[i].getavg() < rightarr[j].getavg()){
            employees[k] = leftarr[i];
            i++;
        } else {
            employees[k] = rightarr[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        employees[k] = leftarr[i];
        i++;
        k++;
    }

    while(j < n2){
        employees[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Employee>& employees, int left, int right){
    if (left>=right){
        return;
    }

    int mid = (left+right)/2;
    mergeSort(employees, left, mid);
    mergeSort(employees, mid+1, right);
    merge(employees, left, mid, right);
}

void selectionSort(vector<Employee>& employees, int n){
    for (int i = 0; i<n; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(employees[j].getavg() < employees[min].getavg()){
                min = j;
            }
        }

        if (min != i){
            Employee temp = employees[i];
            employees[i] = employees[min];
            employees[min] = temp;
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<Employee> employees(n);
    cout << "Enter employee details:\n";
    for(int i = 0; i < n; i++){
        cout << " For employee " << i + 1 << ":\n";
        employees[i].accept();
    }

    cout << "\nChoose sorting method:\n 1. Merge Sort\n 2. Selection Sort\nYour choice: ";
    int choice;
    cin >> choice;

    switch(choice){
        case 1:
            mergeSort(employees, 0, n-1);
            cout << "\nMerge-sorted employee details (by average of height and weight):\n";
            break;
        case 2:
            selectionSort(employees, n);
            cout << "\nSelection-sorted employee details (by average of height and weight):\n";
            break;
        default:
            cout << "Invalid choice!";
            return 1;
    }

    for (int i = 0; i < n; i++){
        cout << i+1 << ". ";
        employees[i].display();
    }

    return 0;
}
// Merge sort and selection sort to arrange employees by avg(height, weight) | Time: Merge O(n log n), Selection O(n²) | Space: O(n)