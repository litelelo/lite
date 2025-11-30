#include <iostream>
using namespace std;

class SparseMatrix {
    int row, col, len;
    int data[100][3];

public:
    void read() {
        cout << "Enter rows and columns: ";
        cin >> row >> col;
        cout << "Enter number of non-zero elements: ";
        cin >> len;
        data[0][0] = row;
        data[0][1] = col;
        data[0][2] = len;
        cout << "Enter row, column, and value for each element:\n";
        for (int i = 1; i <= len; i++) {
            cin >> data[i][0] >> data[i][1] >> data[i][2];
        }
    }

    void display() {
        cout << "\nSparse Matrix Representation:\n";
        for (int i = 0; i <= len; i++) {
            cout << data[i][0] << " " << data[i][1] << " " << data[i][2] << endl;
        }
    }

    void fastTranspose() {
        SparseMatrix trans;
        trans.row = col;
        trans.col = row;
        trans.len = len;
        trans.data[0][0] = col;
        trans.data[0][1] = row;
        trans.data[0][2] = len;

        int total[100] = {0}, index[100] = {0};

        for (int i = 1; i <= len; i++) {
            total[data[i][1]]++;
        }

        index[0] = 1;
        for (int i = 1; i < col; i++) {
            index[i] = index[i - 1] + total[i - 1];
        }

        for (int i = 1; i <= len; i++) {
            int colIndex = data[i][1];
            int loc = index[colIndex];
            trans.data[loc][0] = data[i][1];
            trans.data[loc][1] = data[i][0];
            trans.data[loc][2] = data[i][2];
            index[colIndex]++;
        }
        trans.display();
    }
};

int main() {
    SparseMatrix s;
    s.read();
    s.display();
    cout << "\nFast Transpose: ";
    s.fastTranspose();
    return 0;
}
// Fast transpose of sparse matrix using index and total arrays | Time: O(cols + nonzero)
