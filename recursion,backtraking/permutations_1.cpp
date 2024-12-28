
// The code generates all permutations of a list by fixing each element
// and recursively swapping it with every other element. 

//After each swap, it explores the remaining list, and when a complete permutation is formed, 
//it's added to the result. 

//Backtracking ensures all possibilities are explored by restoring the list's original state after
// each recursive call, systematically covering every permutation of the input list.


//o(n*n!)=o(n!)
//o(n)


class Solution {
public:

void solve(vector<int>&nums, vector<vector<int>>&ans, int i){

    int n=nums.size();

    if(i==n){
        ans.push_back(nums); 
        return; //silly..
    }


    for(int j=i; j<n;j++){

        swap(nums[i],nums[j]);
        solve(nums,ans,i+1);

        swap(nums[i],nums[j]);  //backtrack..
    }


}
    vector<vector<int>> permute(vector<int>& nums) {


        vector<vector<int>>ans;
        int index=0;

        solve(nums,ans,index);

        return ans;
        
    }
};