
//iterative brute forcee..
//arr[i]>arr[i-1]) && (arr[i]>arr[i+1] ...loop lgake ye condition check krni bas...
//aur first or last eleemnt ka bhi handle krlenaa...


//o(n)..
//o(1)..



class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n=nums.size();

        for(int i=0;i<n;i++){

            if((i==0 || nums[i]>nums[i-1]) &&
               (i==n-1 || nums[i]>nums[i+1])){

                return i;
               }
        }

        return -1;
        
    }
};



//optimal...bs...o(logn)..o(1)..


class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n=nums.size();

        if(n==1){
            return 0;
        }

        int s=0;
        int e=n-1;

        while(s<=e){

            int mid= s+ (e-s)/2;

            if(mid==0 || nums[mid]>nums[mid-1] &&
               mid==n-1 || nums[mid]>nums[mid+1]){

                return mid;
               }

            else if(nums[mid]<nums[mid+1]){
                s =mid+1;
            }

            else{
                e=mid-1;
            }
        }

        return -1;
        
    }
};