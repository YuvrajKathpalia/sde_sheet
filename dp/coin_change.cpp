//RECURSSION..
//TAKE/NOT_TAKE..

//O(2^N)..O(N)..

//take/not take..not/take = 0+index-1..
//take(if coins[index]<=amount)..1+f(index)....index-1 ki call ni denge index ki hi denge..as 1 coin multiple times
//select krskte hai..

//return min (take,not take)..



class Solution {
public:

int f(int index, vector<int>& coins , int amount){

    //base..
    if(index==0){

    if(amount==0){
        return 0;
    }
    if(amount%coins[0]==0){
        return amount/coins[0];
    }
    else{
        return 1e9;  //not possible case hogya na..return any large number..
    }
    }

    

    int not_take = 0+f(index-1,coins,amount);

    int take =1e9; //default value high..silly..

    if(coins[index]<=amount){
        take = 1+ f(index, coins , amount - coins[index]);
    }

    return min(not_take, take);

}
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        
        int ans= f(n-1,coins,amount);

        if(ans>=1e9){
         return -1;

        }

        return ans;
    
    }
};



//approach2..memo..
//use 2d dp... index,amount...mtlb kis index pe kitne amount ke liye kitne index use hore..

// Memoization (top-down approach) is used to avoid redundant calculations by storing results in a dp table.

// We use recursion + memoization to explore two possibilities for each coin:

// Not Take: Skip the current coin and move to the next coin.
// Take: Use the current coin, reduce the remaining amount, and continue using the same coin.

//tc..o(n*amount)..
//sc..(n*amount)+ o(amount)....O(n * amount) for the dp table + O(amount) for the recursion stack.





class Solution {
public:

int f(int index, vector<int>&nums,int amount,vector<vector<int>>&dp){


    if(index==0){

        if(amount==0){
            return 0;
        }

        if(amount%nums[0]==0){
            return amount/nums[0];
        }

        else{

            return 1e9;
        }
    }

    if(dp[index][amount]!=-1){
        return dp[index][amount];
    }

    int not_take = 0+ f(index-1,nums,amount,dp);

    int take=1e9;

    if(nums[index]<=amount){

        take = 1+ f(index,nums,amount-nums[index],dp);
    }

    return dp[index][amount]= min(take,not_take);
}


    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();

        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

        int ans = f(n-1,coins,amount,dp);


        if(ans>=1e9){
            return -1;
        }

        return ans;
        
    }
};



//APPROACH3...
//TABULATION
//O(N*AMOUNT)...o(n*amount)..

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,0));


 //base case fill...index==0..mtlb ek elemnt bcha aur..to 0 se leke amount tak 
 //agar amount phle element se divisible...to bhrdo usmo amount/nums[0];

 for(int i=0; i<=amount ;i++){

     if(i%coins[0]==0){
         dp[0][i] = i/coins[0];
     }
     else{
         dp[0][i] = 1e9;
     }
 }

     for(int index=1; index<n;index++){
         for(int target =0; target <=amount ; target++ ){


    int not_take = 0 + dp[index-1][target];

    int take= 1e9;

    if(coins[index] <=target){
         take = 1 + dp[index][target-coins[index]];   
    }

    dp[index][target] = min(take,not_take);

         }
     }

     int ans =dp[n-1][amount];

     if(ans>=1e9){
         return -1;
     }


     return ans;
    
    }
};