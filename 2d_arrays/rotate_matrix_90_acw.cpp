
https://www.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//first transpose...reverse very column...


//o(n^2)..
//o(1)..

class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& matrix, int n) {
	    
	    
	    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each column
    
    
    for (int j = 0; j < n; j++) {
        
        int top = 0, bottom = n - 1;
        
        
        while (top < bottom) {
            
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    
	}
	
	}
};