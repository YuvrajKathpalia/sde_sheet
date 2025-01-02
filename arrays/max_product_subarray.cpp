
//brute force..
//o(n^2)..o(1)...


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxproduct = INT_MIN;

        for (int i = 0; i < n; i++) {

            int product = 1; 
            for (int j = i; j < n; j++) {

                product *= nums[j];
                maxproduct = max(maxproduct, product);
            }
        }

        return maxproduct;
    }
};



//optimal..intutitive..like kadane...



//HAR STEP PE CUR MAX, CURR MIN PRODUCT MAINTAIN KRTE RHE...(ya to include kro , ya pichle currmax/currmin se multiply kro) 
//aur agar negative element ara to currmax aur currmin ko swap krdo..
//kyuki agar currmin -ve chalra, to ek aur -ve number ane se wo currmax banskta haii isliye 
//maxproduct to hum update kr hi rhe h har iteration me..

//o(n)..o(1)..


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n=nums.size();

        int maxproduct=nums[0];

        int currmax = nums[0];
        int currmin = nums[0];

        for(int i=1;i<n;i++){

            if(nums[i]<0){

                swap(currmax,currmin);
            }


            currmax = max(nums[i], currmax*nums[i]);

            currmin = min(nums[i], currmin*nums[i]);

            maxproduct = max(maxproduct,currmax);
        }

        return maxproduct;
        
    }
};



//SIMIALRLY CODE FO MAX SUM SUBARRAY---...


//approach2...using kadane...
//easy ..logical..



class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        int n = nums.size();

        int maxSum = nums[0];  
        int currSum = nums[0]; 

        for(int i = 1; i < n; i++) {

            // Either start a new subarray at nums[i] or extend the current subarray
            currSum = max(nums[i], currSum + nums[i]);

            // Update the maximum sum encountered so far
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
