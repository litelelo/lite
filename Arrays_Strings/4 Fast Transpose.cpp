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
    } else {
        cout << "\nThe matrix is not sparse." << endl;
    }

    int nonzero = n * m - zeroes;

    if (nonzero == 0) {
        cout << "\nNo non-zero elements to process." << endl;
        return 0;
    }

    vector<vector<int> > sparse(nonzero+1, vector<int>(3));
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

    // writing fast transpose of sparse matrix:
    vector<vector<int> > transpose(nonzero+1, vector<int>(3));  
    transpose[0][0] = sparse[0][1];  
    transpose[0][1] = sparse[0][0];   
    transpose[0][2] = sparse[0][2];

    int num_cols = sparse[0][1];     
    int num_terms = sparse[0][2];    
    if (num_terms > 0) {  
        vector<int> row_terms(num_cols, 0);
        vector<int> starting_pos(num_cols);

        
        for (int i = 1; i <= num_terms; i++) {
            row_terms[sparse[i][1]]++;  
        }

        
        starting_pos[0] = 1;
        for (int i = 1; i < num_cols; i++) {
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }

        for (int i = 1; i <= num_terms; i++) {
            int j = starting_pos[sparse[i][1]];  
            transpose[j][0] = sparse[i][1];      
            transpose[j][1] = sparse[i][0];      
            transpose[j][2] = sparse[i][2];      
            starting_pos[sparse[i][1]]++;        
        }
    }

    cout << "\nFast Transpose of Sparse Matrix:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    for (int i = 0; i < nonzero + 1; i++) {
        cout << transpose[i][0] << "\t" << transpose[i][1] << "\t" << transpose[i][2] << endl;
    }

	return 0;
}
// Fast transpose of sparse matrix using row counting | Time: O(cols + terms) | Space: O(terms)