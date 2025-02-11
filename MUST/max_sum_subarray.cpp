//brutr force...o(n^3)...
//o(1)..


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                int sum=0; 

                for(int k=i;k<=j;k++){
                    sum += nums[k];
                }

                maxi= max(maxi,sum);


            }
        }

        return maxi;
        
    }
};




//better ...o(n^2)...
//o(1)..


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){

            int sum=0;
            for(int j=i;j<n;j++){

               sum += nums[j];
               maxi= max(maxi,sum);
        }
               
            }

        return maxi;
        
    }
};

//The brute force approach uses three nested loops to generate all possible subarrays 
//and calculate their sums, leading to a time complexity of O(n³). 
//In contrast, the optimized approach uses two loops,
// where the sum is accumulated progressively for each subarray, 
//reducing the time complexity to O(n²). Both approaches use O(1) space complexity.





//optimaal...o(n)...kadane algorithm...logical hai poora..
//o(1)..

//ek hi lloop lgaege...at any point you have to choices include it in the subarray or start a new subarray...


// The intuition of the algorithm is not to consider the subarray as a part of the answer
//  if its sum is less than 0. A subarray with a sum less than 0 will 
// always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum...
//matlab 2 WAYS HOSKTE HAR ELEMENT PE YA CURRSUM ME ADD UP KRTE JAO , YA WHA SE NAYA SUM SHURU KRO...



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




//FOLLOW-UP-QUESTION...AGAR SUBARRAY PRINT KRANE KO BHI BOLE...




class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {


        int n = nums.size();
        int maxSum = nums[0];  
        int currSum = nums[0];  


        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < n; i++) {

            // If starting a new subarray is better, update tempStart
            if (nums[i] > currSum + nums[i]) {
                currSum = nums[i];
                tempStart = i;  // Start a new subarray at index i
            } else {
                currSum += nums[i];
            }

            // If we found a new maximum, update maxSum and the subarray boundaries
            if (currSum > maxSum) {
                maxSum = currSum;
                start = tempStart;
                end = i;  // The end of the subarray is at index 
                
            }
        }

        // Return the subarray from start to end
        vector<int> result(nums.begin() + start, nums.begin() + end + 1);


        return result;
    }
};
