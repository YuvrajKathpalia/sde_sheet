
//brute force...

///AGAR ORIGINAL MATRIX ME HI OPERATION LAGANA SHURU KRDENGE TO NI POSSIBLE HOGAA track ni krpayge changes ache se..
//2ND EXAMPLE DRY RUN KRKE DEKHO...

//ISLIE LOOP ASLI MATRIX ME LGAAO AUR CHANGES VISITED ME KRO...FIR MATRIX=VISITED KRDO...

//tc....m*n*(m+n) +m*n == m*n*(m+n+1)...==o(m*n*(m+n)).....o(n^3)...
//sc...o(m*n)..



#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Create a visited matrix initialized as a copy of the original matrix
    vector<vector<int>> visited = matrix;

    // Iterate through the matrix to find zero elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                // Set the entire row to zero in the visited matrix
                for (int k = 0; k < n; k++) {
                    visited[i][k] = 0;
                }
                // Set the entire column to zero in the visited matrix
                for (int k = 0; k < m; k++) {
                    visited[k][j] = 0;
                }
            }
        }
    }

    // Copy the changes from visited matrix back to the original matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = visited[i][j];
        }
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "Modified matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}





///approach2...
//taking 2 1d vectors to mark  visited...

//tc..o(m*n)...
//sc...o(m+n)..

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);

    // Mark rows and columns that need to be zeroed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = -1;
                col[j] = -1;
            }
        }
    }

    // Set the required elements to zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] == -1 || col[j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "Modified matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
