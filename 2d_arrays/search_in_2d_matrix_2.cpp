//search_1.me normally suru se leke last elemnt tak sorted tha...
//but is quetion me har row ascendingly sorted , aur har col me ascendingly sorted....


//isme bhi hum bs jaisa kuch khelge...
//matrix[0][n-1] se shuru krege..agar element target se bada..to colindex-- 
//warna agr elemnt chota hai to neeche ajege rowindex++..

//o(m+n)..
//o(1)..



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row=matrix.size();
        int col=matrix[0].size();

        int rowIndex=0;
        int colIndex=col-1;
         
    while(colIndex>=0  && rowIndex<row){
           
        int element =matrix[rowIndex][colIndex];

        if(element==target){
            return true;
        }
        if(element>target){
        colIndex--;
        }
         else{
        rowIndex++;
        }
        
    }
    return false;
    }
};