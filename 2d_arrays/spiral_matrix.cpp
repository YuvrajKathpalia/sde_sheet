
//acha..famous..
//use 4 pointers..


//tc..O(m*n)..traversig all elemnts only once.
//sc..(o(m*n))..storinmg all elemnts..



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;
        int m = matrix.size();
        int n =matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
      

        
        while (top <= bottom && left <= right) {


            // Traverse top row
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // Traverse right column
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // Traverse bottom row..

            //check krle top bottom se kum hi haina..top++ kra tha na..2*2 ki matrix leke dekhle 
            
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // Traverse left column
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};