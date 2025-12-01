// Write a program to construct and verify a magic square of order 'n' (for both even & odd) such that all rows, columns, and diagonals sum to the same value.

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int magicNumber(int n){
    return n * (n * n + 1) / 2;
}

vector<vector<int>> oddOrder(int n){
    vector<vector<int>> magicSquare(n, vector<int>(n,0));

    int i = n/2;
    int j = n-1;

    for (int num = 1; num<=n*n; num++){
        if (magicSquare[i][j] != 0){
            j = (j-1+n)%n;
            i = (i+2)%n;
        }

        magicSquare[i][j] = num;

        j = (j+1)%n;
        i = (i-1+n)%n;
    }

    return magicSquare;
}

void doublyEvenOrder(int n){
    vector<vector<int>> magicSquare(n, vector<int>(n,0));

    int num = 1;
    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            magicSquare[i][j] = num;
            num++;
        }
    }

    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if((i%4 == j%4) || (i%4 + j%4 == 3)){
                magicSquare[i][j] = (n*n +1) - magicSquare[i][j]; 
            }
        }
    }
    
    cout << "Magic Square of order " << n << " is: " << endl;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(4) <<magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

void singlyEvenOrder(int n) {
    int half = n / 2;
    int subSquareSize = half * half;
    vector<vector<int>> oddSquare = oddOrder(half);
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    // Fill 4 quadrants with offsets
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            int val = oddSquare[i][j];
            magicSquare[i][j] = val;
            magicSquare[i + half][j + half] = val + subSquareSize;
            magicSquare[i][j + half] = val + 2 * subSquareSize;
            magicSquare[i + half][j] = val + 3 * subSquareSize;
        }
    }

    // Swap columns according to the algorithm
    int k = (n - 2) / 4;
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < k; j++) {
            swap(magicSquare[i][j], magicSquare[i + half][j]);
        }
    }
    for (int i = 0; i < half; i++) {
        for (int j = n - k + 1; j < n; j++) {
            swap(magicSquare[i][j], magicSquare[i + half][j]);
        }
    }
    // Special middle column swap
    swap(magicSquare[k][k], magicSquare[k + half][k]);

    // Print the result
    cout << "Magic Square of order " << n << " is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n = 0;
    cout << "Enter the order of the magic square: ";
    cin >> n;

    int m = magicNumber(n);

    if(n%2 == 0 && n%4 == 0){
        doublyEvenOrder(n);
    } else if (n%2 == 0 && n%4 != 0){
        singlyEvenOrder(n);
    } else {
        vector<vector<int>> magicSquare = oddOrder(n);
        cout << "Magic Square of order " << n << " is: " << endl;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << setw(4) <<magicSquare[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;

}
// Magic square generation for odd, singly-even, and doubly-even orders | Time: O(n²) | Space: O(n²)