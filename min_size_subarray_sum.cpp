https://leetcode.com/problems/minimum-size-subarray-sum/description/


//BRUTE FORCE.
//O(N^2)...O(1).

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();

        int minlength=INT_MAX;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){

                sum += nums[j];

                if(sum>=target){
                    minlength =min(minlength,j-i+1);
                    break;   //shortest length jo milni thi milchuki ab
                }


            }
        }

        return minlength ==INT_MAX ?0 :minlength;
        
    }
};



//optimal..

//2 pointer sw...

//l,r..sum nikalo..while loop..agar sum>=tagret condition satisfy hori hai..window shrink krke dekho tab bhi hori h kya
//kyuki hume min size chayie na subarray ka..

//o(n)..
//o(N)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();

        int minlength=INT_MAX;

        int l=0;
        int r=0;

        int sum=0;

        while(r<n){
  
            sum += nums[r];
           
             while(l<=r && sum>=target){
                minlength = min(minlength ,r-l+1);
                sum -= nums[l];
                l++;
             }  

             r++;
           
        }

        return minlength == INT_MAX ? 0:minlength;
        
    }
};