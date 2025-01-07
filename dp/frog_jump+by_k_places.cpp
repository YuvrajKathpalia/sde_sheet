//SOLUTION TO -FROG JUMP(NORMAL)(1 JUMP YA 2 JUMP)...

#include <bits/stdc++.h> 
using namespace std;

int f(int index, vector<int> &heights) {

    if (index == 0) {
        return 0;
    }

///left--1 jump...right--2 jump...dono me se jo min usppe jaygaa

    int left = f(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX; //taki jab index=1 mtlb phli pekhda to hmesha 1 jump wala option hi ho(minimum chie na)..

    if (index > 1) {
        right = f(index - 2, heights) + abs(heights[index] - heights[index - 2]);
    }

    return min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    
    return f(n - 1, heights);
}

















https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/


//pichle me 1 ya 2 jump marsktatha...isme till k jumps marskta...k ki value di hogi...if k=4..
///to mtlb wo 1/2/3/4 jump marskta jisse min ayga uspe jayga...
//same process...wse..f(index-1)ki call dete the 1jump ke lie...isme f(index-i) ki denge aur i ke
//le liye loop chlra hoga 1 se k tak.. jo min ayga wo lenge..

//recursive..o(n*k)

int f(int index , int k , vector<int>& height){

if(index==0){
    return 0;
}
int minSteps =INT_MAX;

for(int i=1;i<=k;i++){

    if(index-i>=0){

    int jump = f(index-i,k,height)+abs(height[index]-height[index-i]);  //index-i ki call
    
    minSteps= min(jump,minSteps);
    }
}

return minSteps;
    
}

int minimizeCost(int n, int k, vector<int> &height){


   return f(n-1,k ,height);

}

//memoization.
//memoization..
//o(n*k), o(n)+0(n)=o(n)

int f(int index , int k , vector<int>& height,vector<int>& dp){

if(index==0){
    return 0;
}
int minSteps =INT_MAX;

for(int i=1;i<=k;i++){

    if(dp[index]!=-1){
        return dp[index];
    }
    if(index-i>=0){

    int jump = f(index-i,k,height,dp)+abs(height[index]-height[index-i]);
    minSteps= min(jump,minSteps);
    }
}
//2
dp[index]= minSteps;
    
}

int minimizeCost(int n, int k, vector<int> &height){

//1
   vector<int>dp(n+1,-1);
   return f(n-1,k ,height,dp);



//tabulation

//Tabulation.....
//o(n*k), o(n)


int minimizeCost(int n, int k, vector<int> &height){


   vector<int>dp(n,0);
   dp[0]=0;

    // Loop through the array to fill in the dp array...

    for (int i = 1; i < n; i++) {

        int minSteps = INT_MAX;

        // Loop to try all possible jumps from '1' to 'k'
        for (int j = 1; j <= k; j++) {

            if (i - j >= 0) {

                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                minSteps = min(jump, minSteps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1]; // The result is stored in the last element of dp
}
