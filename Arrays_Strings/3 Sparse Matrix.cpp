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

    void simpleTranspose() {
        SparseMatrix trans;
        trans.row = col;
        trans.col = row;
        trans.len = len;
        trans.data[0][0] = col;
        trans.data[0][1] = row;
        trans.data[0][2] = len;

        int k = 1;
        for (int i = 0; i < col; i++) {
            for (int j = 1; j <= len; j++) {
                if (data[j][1] == i) {
                    trans.data[k][0] = data[j][1];
                    trans.data[k][1] = data[j][0];
                    trans.data[k][2] = data[j][2];
                    k++;
                }
            }
        }
        trans.display();
    }
};

int main() {
    SparseMatrix s;
    s.read();
    s.display();
    cout << "\nTranspose: ";
    s.simpleTranspose();
    return 0;
}
