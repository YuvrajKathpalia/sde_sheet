

https://geeksforgeeks.org/problems/the-celebrity-problem/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//brute force...2 1d vector lelie.. iknow , knowme ..usme store krliaa
//fir loop lgaye 0 se n, jis bhi element ke lie iknow=0 aur knowme=n-1 , whi h celebrity..

//o(n^2)..
//o(n)..

class Solution {
  public:

    int celebrity(vector<vector<int> >& matrix) {
        
        
        int n=matrix.size();
        
        vector<int>iknow(n,0);
        vector<int>knowme(n,0);
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                
                if(matrix[i][j]==1){
                    
                    knowme[j]++;
                    iknow[i]++;
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            
            if(iknow[i]==0 && knowme[i]==n-1){
                return i;
            }
        }
        
        return -1;


       
    }
};


//better...

//use stack...


//The intuition here is to find the celebrity by leveraging a stack. 
//We eliminate non-celebrities through comparisons: if person `a` knows `b`, 
//`a` isn’t the celebrity; otherwise, `b` isn’t.
//After isolating one candidate, we verify it by ensuring they 
//know no one and everyone knows them. 
//This efficient approach reduces the number of checks needed.


//o(n)..
//o(n)..

class Solution {
  public:



bool knows(vector<vector<int>>&matrix ,int i ,int j){
    
    
    if(matrix[i][j]==1){
        return true;
    }
    
    return false;
}

    int celebrity(vector<vector<int> >& matrix) {
        
        int n=matrix.size();
        
        stack<int>st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            
            int a =st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            if(knows(matrix,a,b)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        int x=st.top();  //possible celebrity....
        
        
        
        int zerocount=0;
        int onecount=0;
        
        
        for(int i=0;i<n;i++){
            
            if(matrix[x][i]==0){
                zerocount++;
            }
            if(matrix[i][x]==1){
                onecount++;
            }
        }
        
        if(zerocount==n && onecount==n-1){
            return x;
        }
        
        return -1;
        
    }
};


//optimal...


//use 2 pointer...


//o(n)..
//o(1)..

class Solution {
  public:



bool knows(vector<vector<int>>&matrix ,int i ,int j){
    
    
    if(matrix[i][j]==1){
        return true;
    }
    
    return false;
}

    int celebrity(vector<vector<int> >& matrix) {
        
         int n = matrix.size();
        int i = 0, j = n - 1;

        // Narrow down to a potential celebrity
        while (i < j) {
            if (knows(matrix, i, j)) {
                i++;  // i cannot be a celebrity
            } else {
                j--;  // j cannot be a celebrity
            }
        }

        
        int x=i;  //possible celebrity....
        
        
        
        int zerocount=0;
        int onecount=0;
        
        
        for(int i=0;i<n;i++){
            
            if(matrix[x][i]==0){
                zerocount++;
            }
            if(matrix[i][x]==1){
                onecount++;
            }
        }
        
        if(zerocount==n && onecount==n-1){
            return x;
        }
        
        return -1;
        
    }
};