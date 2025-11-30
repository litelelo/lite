#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    float height;
    float weight;
    float avg;
};

void merge(Employee arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Employee L[50], R[50];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Employee arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee emp[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter Name, Height, Weight for employee " << i + 1 << ": ";
        cin >> emp[i].name >> emp[i].height >> emp[i].weight;
        emp[i].avg = (emp[i].height + emp[i].weight) / 2.0;
    }

    mergeSort(emp, 0, n - 1);

    cout << "\nSorted List based on Average of Height and Weight:\n";
    for (int i = 0; i < n; i++) {
        cout << emp[i].name << " - Avg: " << emp[i].avg << endl;
    }

    return 0;
}
// Merge sort on employee records by average height/weight | Time: O(n log n)
