/practice...approach1...
//brute force...
//ek visiited matrix..,ark krdo phle row ,fir colm...fir copy krdena original matrix me..

//AGAR ORIGINAL MATRIX ME HI OPERATION LAGANA SHURU KRDENGE TO NI POSSIBLE HOGAA...
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

    // Create a copy of the matrix
    vector<vector<int>> visited = matrix;

    // Traverse the matrix and mark rows and columns to be zero in the copy
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

    // Update the original matrix with the zeroes from the visited matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = visited[i][j];
        }
    }
}

int main() {
    int m, n, value;
    
    // Input number of rows and columns
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Input the matrix values
    cout << "Enter the matrix values:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Set zeroes in the matrix
    setZeroes(matrix);

    // Output the modified matrix
    cout << "Modified matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



//optimal... 2 1d vector lelie row,aur column ke size ke... usse mark krdii ek hi iteration me jha jha zero are the.. [i][j] pe 0 to row[i]=-1, row[j]=-1 .. fir in marked zgaho pe 0 se replace krdia..
//tc..o(m*n)...
//sc...o(m+n)..


///approach2...
//taking 2 1d vectors to mark  visited...

//tc..o(m*n)...
//sc...o(m+n)..


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>row(m,0);
        vector<int>col(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(matrix[i][j]==0){

                    row[i]=-1;
                    col[j]=-1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(row[i]==-1 || col[j]==-1){

                    matrix[i][j]=0;
                }
            }
        }

        
    }
};