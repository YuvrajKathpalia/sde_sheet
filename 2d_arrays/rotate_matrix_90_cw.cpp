https://leetcode.com/problems/rotate-image/description/

/// BRUTE FORCE...

//Iterative...
//Ek naya matrix lia..
//Last column ko phli row ke.elemnts se replace krdia...
//For second last column ko second row ke elements se...and vice versa...ye matrix return krdenga..poora hi brute force ye to...extra space bhi leli matrix ki


//N^2,n^2...

#include<bits/stdc++.h>

using namespace std;
vector < vector < int >> rotate(vector < vector < int >> & matrix) {

    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));


    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

        rotated[j][n - i - 1] = matrix[i][j];            ///for first iteration... 02,12,22 ko 00,01,02 se replace krna...
    }
    }
    return rotated;
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "n";
    }

}


//OPTIMAL ...
//transpose leke...
//sari rows apne me reverse(loop lgadena)...

// Why j < i?

// In the transpose operation, you want to swap only the elements above the main diagonal (where i > j). If you swap all elements (j < m), you will end up swapping twice and revert the matrix to its original form.
// To avoid unnecessary operations, the loop runs with j < i, ensuring that each pair (i, j) is swapped only once.


//o(m^2)..
//o(1)..



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int m =matrix.size();

        for(int i=0; i<m;i++){
            for(int j=0;j<i;j++){  //silly... j<i .... saare thdi  change krdoge...            
                  
                  swap(matrix[i][j] , matrix[j][i]);

            
            }
        }

        for(int i=0; i<m;i++){

            reverse(matrix[i].begin() , matrix[i].end());
        }
        
    }
};


#include<bits/stdc++.h>
using namespace std;


    void solve(vector<vector<int>>& matrix) {

        int m =matrix.size();

        for(int i=0; i<m;i++){
            for(int j=0;j<i;j++){  //silly... j<i .... saare thdi  change krdoge...            
                  
                  swap(matrix[i][j] , matrix[j][i]);

            
            }
        }

        for(int i=0; i<m;i++){

            reverse(matrix[i].begin() , matrix[i].end());
        }
        
    }


int main()
{
    int m;
    int n;
    cin>>m;
    cin>>n;
    
    vector<vector<int>>mat(m,vector<int>(n));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            cin>>mat[i][j];
        }
    }
    
     solve(mat);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            cout<<mat[i][j]<<" ";
            
        }
        cout<<endl;
    }
    

    return 0;
}