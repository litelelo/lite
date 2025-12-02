#include <iostream>
using namespace std;

int passCount = 0;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


int partitionArray(int a[], int low, int high, int n) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {       
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    
    passCount++;
    cout << "Pass " << passCount << ": ";
    printArray(a, n);

    return i + 1;
}

// Quick Sort (recursive)
void quickSort(int a[], int low, int high, int n) {
    if (low < high) {
        int p = partitionArray(a, low, high, n);
        quickSort(a, low, p - 1, n);
        quickSort(a, p + 1, high, n);
    }
}


void findMinMax(int a[], int low, int high, int &mn, int &mx) {
    // single element
    if (low == high) {
        mn = mx = a[low];
        return;
    }

    // two elements
    if (high == low + 1) {
        if (a[low] < a[high]) {
            mn = a[low];
            mx = a[high];
        } else {
            mn = a[high];
            mx = a[low];
        }
        return;
    }

    
    int mid = (low + high) / 2;
    int mn1, mx1, mn2, mx2;

    findMinMax(a, low, mid, mn1, mx1);
    findMinMax(a, mid + 1, high, mn2, mx2);

   
    mn = (mn1 < mn2) ? mn1 : mn2;
    mx = (mx1 > mx2) ? mx1 : mx2;
}

int main() {
    int n;
    int marks[100];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    cout << "\nInitial marks:\n";
    printArray(marks, n);

    
    quickSort(marks, 0, n - 1, n);

    cout << "\nSorted marks in ascending order:\n";
    printArray(marks, n);

    
    int mn, mx;
    findMinMax(marks, 0, n - 1, mn, mx);

    cout << "\nMinimum marks = " << mn << endl;
    cout << "Maximum marks = " << mx << endl;

    return 0;
}
