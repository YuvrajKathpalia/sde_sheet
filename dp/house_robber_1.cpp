

// recursion..o(2^n)..o(n)..

class Solution {
public:

int f(vector<int>& nums , int index){

    if(index==0){
        return nums[index];
    }
    if(index<0){
        return 0;
    }
    

    int rob = nums[index] + f(nums,index-2);
    int not_rob = 0 + f(nums,index-1);

    return max(rob,not_rob);
}

    int rob(vector<int>& nums) {

        int n= nums.size();

        return f(nums,n-1);
        
    }
};


// MEMO..
// O(N)..O(N)..

class Solution {
public:

int f(vector<int>& nums , int index , vector<int>&dp){

    if(index==0){
        return nums[index];
    }
    if(index<0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    
    int rob = nums[index] + f(nums,index-2,dp);
    int not_rob = 0 + f(nums,index-1,dp);

    return dp[index]=  max(rob,not_rob);
}

    int rob(vector<int>& nums) {

        int n= nums.size();

        vector<int>dp(n+1,-1);

        return f(nums,n-1,dp);
        
    }
};



// TABULATION..
// O(N)..
// O(N)..

class Solution {
public:

int f(vector<int>& nums , int index){

    if(index==0){
        return nums[index];
    }
    if(index<0){
        return 0;
    }
    

    int rob = nums[index] + f(nums,index-2);
    int not_rob = 0 + f(nums,index-1);

    return max(rob,not_rob);
}

    int rob(vector<int>& nums) {

        int n= nums.size();
        vector<int>dp(n,0);

        dp[0]=nums[0]; 
        //jab index -1 hojega wo sambhalna pdega..

        for(int i=1; i<n;i++){

        int rob = nums[i];

        if(i>1){

            rob += dp[i-2];
        }

        int not_rob = 0 + dp[i-1];

        dp[i] = max(rob,not_rob);

        }

        return dp[n-1];
    
        
    }
};




//approach4..
//spaceoptimised..
//o(n)..o(1)..

class Solution {
public:

    int rob(vector<int>& nums) {
        
        int n=nums.size();

        int prev=nums[0];
        int prev2= 0;

        for(int i=1;i<n;i++){

            int rob = nums[i];

            if(i>1){
             rob += prev2;          
            }
            int not_rob = 0+ prev;

            int curr =max(rob,not_rob);

            prev2=prev;
            prev=curr;
        }

        
        return prev;
        
    }
};