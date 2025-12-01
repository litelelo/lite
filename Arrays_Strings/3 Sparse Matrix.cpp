#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0,m = 0, zeroes = 0;
	cout << "Enter number of rows: ";
	cin >> n;
	cout << "Enter number of columns: ";
	cin >> m;

    cout << "Enter the elements of the matrix:" << endl;
    vector<vector<int> > matrix(n, vector<int>(m));

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++){
            cin >> matrix[i][j];

            if(matrix[i][j] == 0) {
                zeroes++;
            }
        }
    }

    //printing matrix:
    cout << "\nInput Matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if (zeroes > (n * m) / 2) {
        cout << "\nThe matrix is sparse." << endl;
    } else if (zeroes == 0) {
        cout << "\nNo non-zero elements to process." << endl;
        return 0;
    } else {
        cout << "\nThe matrix is not sparse." << endl;
        return 0;
    }

    int nonzero = n * m - zeroes;

    vector<vector<int>> sparse(nonzero+1, vector<int>(3));
    sparse[0][0] = n; 
    sparse[0][1] = m;
    sparse[0][2] = nonzero;

    cout << "\nSparse matrix representation:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    int index = 1;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(matrix[i][j] != 0) {
                sparse[index][0] = i;
                sparse[index][1] = j;
                sparse[index][2] = matrix[i][j];
                index++;
            }
        }
    }

    // printing the sparse matrix
    for(int i = 0; i < nonzero + 1; i++) {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }

    // writing simple transpose of sparse matrix:
    vector<vector<int> > transpose(nonzero + 1, vector<int>(3));
    
    transpose[0][0] = sparse[0][1]; 
    transpose[0][1] = sparse[0][0]; 
    transpose[0][2] = sparse[0][2]; 
    
    int noterms = sparse[0][2];
    int noc = sparse[0][1]; 
    
    if (noterms > 0) {
        int nxt = 1;
    
         for (int c = 0; c < noc; c++) {
            for (int term = 1; term <= noterms; term++) {
                if (sparse[term][1] == c) {
                    transpose[nxt][0] = sparse[term][1]; 
                    transpose[nxt][1] = sparse[term][0]; 
                    transpose[nxt][2] = sparse[term][2]; 
                    nxt++;
                }
            }
        }
    }

    cout << "\nTranspose of Sparse Matrix:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    for (int i = 0; i < nonzero + 1; i++) {
        cout << transpose[i][0] << "\t" << transpose[i][1] << "\t" << transpose[i][2] << endl;
    }

	return 0;
}
// Sparse matrix representation (triplet form) with simple transpose | Time: O(rows × cols × terms) | Space: O(terms)