
//agar sorted array hai to ,2 pointer lagjega na arram se...binary search se bhi hojega...

//brute...
//o(n^2)..
//o(1)..



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        int sum=0;

        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++){
             
             if(nums[i]+nums[j]==target){
                return {i+1,j+1};
            }

            }
        }

        return {-1,-1};
        
    }
};


//better...

//bs..

//o(nlogn)
//o(1)

class Solution {
public:
    int search(int target,vector<int>&nums,int left,int right)
    {
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else
                return mid;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>&nums,int target) 
    {
        for(int i=0;i<nums.size();i++)
        {
            int j=search(target-nums[i],nums,i+1,nums.size()-1);
            if(j!=(-1))
                return {i+1,j+1};
        }
        return {-1,-1};
    }
};


//optimal...

//2 pointer..

//o(n).
//o(1)..



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        int sum=0;

        int left=0;
        int right=n-1;

        while(left<=right){

            int sum = nums[left]+nums[right];

            if(sum==target){
                return {left+1,right+1};
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {-1,-1};
        
    }
};