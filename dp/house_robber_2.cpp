//approach1..recursion
//similar to house robber1..
//isme bs last wala aur first walasame..to ya to 1st pick kro ya last..

//to hum 2 call dendenge..ek bar last remove krke aur ekbar first remove krke jisse max ayga wo 
// return krdenge

class Solution {
public:

int solve(int index,vector<int>&nums){
        
        if(index==0) return nums[index] ; 

        if(index<0) return 0 ; 

        int pick = nums[index] ; 
    
         if(index>1)
          pick+=solve(index-2,nums);

        int notpick = 0+solve(index-1,nums);  

        return max(pick,notpick);
    }


    int rob(vector<int>& nums) {
         
        int n = nums.size();
        if(n==1) return nums[0];

    
 //2 times call 


 //once, ignoring last element(n-1th)

        nums.pop_back();
        int ans1 = solve(n-2,nums);

 //second, ignoring start element(0th)

        nums.push_back(nums[n-1]);
        nums.erase(nums.begin());
        int ans2 = solve(n-2,nums);

        return max(ans1,ans2);
    }
};