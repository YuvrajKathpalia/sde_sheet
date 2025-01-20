
//approach1..recursion
//RECURSSION... O(2^N)..
//take not take...
//call 0 ki denge current index aur -1 denge prev index...


class Solution {
public:



int f(int index , int prev , vector<int>& nums){


    if(index==nums.size()){
        return 0;
    }

    int not_take = 0+ f(index+1,prev,nums);

    int take=0;

    if(prev ==-1 || nums[prev]< nums[index]){

        take += 1 + f(index+1, index, nums);
    }

    return max(not_take , take);

}
    int lengthOfLIS(vector<int>& nums) {
        
        return f(0,-1,nums);
    }
};




//MEMO..
//o(n*n)....
//o(n*n)+o(n)..


int f(int index , int prev , vector<int>& nums, vector<vector<int>>&dp){


    if(index==nums.size()){
        return 0;
    }

    if(dp[index][prev+1]!=-1){
        return dp[index][prev+1];
    }

    int not_take = 0+ f(index+1,prev,nums,dp);

    int take=0;

    if(prev ==-1 || nums[prev]< nums[index]){   //idhar ni krna joorat ni..as -1 wala sambhal to lega prev==-1 me..

        take += 1 + f(index+1, index, nums,dp);
    }

    return dp[index][prev+1]= max(not_take , take);

}
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)); 
        //obvio...index,prev do paramter..prev ki value -1 to n-1...islie..n+1 size..aur arr[-1] kuchni hota islie jab prev sekhelege prev+1 krkekhelege
        //index wala bhi n+1 size ka lelia easy handling k lie..n bhi chljata thoiugh..
        
        return f(0,-1,nums,dp);
    }
 



//TABU..
//O(N*N)..
//O(N*N).....recursion wala o(n) bchgya space...





    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0)); 

        //base case..joorat ni..

        

        //n-1 se 0 chlaenge..

        for(int index=n-1; index>=0;index--){
            for(int prev=index-1;prev>=-1;prev--){

        int not_take=0;
        int take=0;


        not_take = 0+  dp[index+1][prev+1];  // prev +1 krdia..

        if(prev ==-1 || nums[prev]< nums[index]){   //idhar ni krna joorat ni..as -1 wala sambhal to loa prev==-1 me..

        take += 1 + dp[index+1][index+1];  //idhar bhi index+1 doosra wala bhi...
        }

        dp[index][prev+1]= max(not_take , take);

        }

            }
        
         return dp[0][-1+1];
               
       
    }
 
 


//SPACE OPTIMISED..
//O(N*N)..
//O(N)...


// int lengthOfLIS(vector<int>& nums) {

// int n = nums.size();

//         vector<int> next(n+1,0);
//         vector<int> curr(n+1,0); 

//         for (int index = n - 1; index >= 0; index--) {
//             for (int prev = index - 1; prev >= -1; prev--) {


//                 int take = 0;

//                 int not_take = next[prev + 1];

//                 if (prev == -1 || nums[index] > nums[prev]) {
//                     take = 1 + next[index + 1];
//                 }

//                 // Store the maximum of taking and not taking the current element
//                 curr[prev + 1] = max(not_take, take);
//             }
//             next = curr;
//         }

//         return curr[-1+1];
//     }
// };



//IMP..
//TABU 2.....0-n-1 fill... same complexity..
//o(n*n)..o(n)

// //0 to n-1..
// //i-1 to 

int lengthOfLIS(vector<int>& nums) {

int n = nums.size();

vector<int>dp(n,1);

for(int i=0; i<=n-1;i++){
    for(int prev=0;prev<=i;prev++){

        if(nums[prev]<nums[i]){

            dp[i] = max(dp[i],1+dp[prev]);
        }
    }
}

//max return krnaa..dp array me ab..(khi bhi pada hosktaa)..

int maxi=0;

for(auto x:dp){

    maxi = max(maxi,x);
}

return maxi;

    // int ans = 0;
    
    // for(int i=0; i<=n-1; i++){
    //     ans = max(ans, dp[i]);
    // }
    
    // return ans;


        
    }
};



//PRINT LIS BHI ISI ME..
//PHLE WHI DP ARRAY BNAO...FIR USSE BACKTRACK KRKE ANS NIKALO..

// int printLIS(vector<int>&nums){

//     int n=nums.size();
//     vector<int>dp(n,1);
//     vector<int>hash(n);


//     for(int i=0; i<=n-1; i++){
//         hash[i]=i;                      //initially apne index se hi  bhrdo..vaise to ye prev index store krega...jab dp update hori..mtlb liska part milra..to usse pichle walaindex jaha se milra wo save krlegaa ye..


//         for(intprev =0; prev<=i;prev++){

//             if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){

//                 dp[i] = 1+dp[prev];
//                 hash[i] =prev;
//             }
//         }
//     }

//     int ans=0;
//     int lastindex=-1;

//     for(int i=0; i<n;i++){

//         ans = max(ans,dp[i]);
//         lastindex=i;          //ab yha se eeche backtrack krege hash array me
//     }

//     vector<int>temp;
//     temp.push_back(nums[lastindex]);

//     while(hash[lastindex]!=lastindex)  //jab tk starting value of lis pe ni phoch jaata..

//     {
//         lastindex=hash[lastindex];
//         temp.push_back(nums[lastindex]);
//     }

//     reverse(temp.begin(),temp.end());

//     return temp;



// }