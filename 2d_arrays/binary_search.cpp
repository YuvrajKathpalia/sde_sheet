#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int s = 0;
    int e = m * n - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (matrix[mid / n][mid % n] == target) {
            return true;
        } else if (matrix[mid / n][mid % n] < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return false;
}

int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    

    cout << "Enter matrix elements row by row:\n";
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    bool result = searchMatrix(matrix, target);
    if (result) {
        cout << "Target found in the matrix\n";
    } else {
        cout << "Target not found in the matrix\n";
    }

    return 0;
}
