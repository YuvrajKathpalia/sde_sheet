//dp

//approach1..
//recursive...

//smallr subproblems... jaise 15 ka nikalna... pta hai 1,2,3 ke squares se hi aaskta..
// jaise 3^2=9.. 1 + solve(6)... 1 square + 6 ke lie kitne squares...aur minimum maintain krna bas ek aur 


//exponential...
//o(n)..


class Solution {
  public:
    int MinSquares(int n) {
        
        if(n==0){
            return 0;
        }
        
        int ans =INT_MAX;
        
        for(int i=1; i*i<=n;i++){
            
            int square = i*i;
            
            ans = min(ans , 1+ MinSquares(n-square));
        }
        
        return ans;
    }
};



class Solution {
public:
  
    int solve(int n, vector<int>& dp) {
       
        if (n == 0) {
            return 0;
        }
        
        
        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = INT_MAX;
        
       
        for (int i = 1; i * i <= n; i++) {

            int square = i * i;
            ans = min(ans, 1 + solve(n - square, dp));
        }
        
       
        dp[n] = ans;
        return ans;   
    }
  
    int MinSquares(int n) {
       
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
