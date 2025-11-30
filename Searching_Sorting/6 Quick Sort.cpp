#include <iostream>
using namespace std;

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(float arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high);
        cout << "Pivot placed at " << pi << ": ";
        printArray(arr, size);
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

void findMinMax(float arr[], int low, int high, float &min, float &max) {
    if (low == high) {
        if (min > arr[low]) min = arr[low];
        if (max < arr[low]) max = arr[low];
        return;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            if (min > arr[high]) min = arr[high];
            if (max < arr[low]) max = arr[low];
        } else {
            if (min > arr[low]) min = arr[low];
            if (max < arr[high]) max = arr[high];
        }
        return;
    }
    int mid = (low + high) / 2;
    findMinMax(arr, low, mid, min, max);
    findMinMax(arr, mid + 1, high, min, max);
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    float marks[100];
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++) cin >> marks[i];

    cout << "Initial array: ";
    printArray(marks, n);

    quickSort(marks, 0, n - 1, n);

    cout << "Sorted array: ";
    printArray(marks, n);

    float min = marks[0], max = marks[0];
    findMinMax(marks, 0, n - 1, min, max);
    cout << "Min: " << min << ", Max: " << max << endl;

    return 0;
}
// Quick sort with divide-and-conquer min/max finder | Time: O(n log n) avg, O(n²) worst
