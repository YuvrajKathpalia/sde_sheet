//ase index btana jha...0 sse wha tk ka sum= wha se end tak ka sum...

//brute..aproach..prefix..suffix..

//o(n)..o(n)


class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n=nums.size();

        vector<int>prefix(n);
        vector<int>suffix(n);

        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){

            prefix[i] = nums[i]+ prefix[i-1];
        }

         for(int i=n-2;i>=0;i--){

            suffix[i]=  nums[i]+ suffix[i+1];
        }

        for(int i=0;i<n;i++){

            if(prefix[i]==suffix[i]){
                return i;
            }
        }


        return -1;
    }
};


//better..o(n)..o(1)...totalsum nikalke rkhlia phle hi....fir loop lgaya...
//agr us index pe..totalsum-uske wha se phle tak ka sum-us elemnt ka sum== usse phle ka sum..to mtlb wo pivot index
//easy dry run..


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;  // Found the pivot index
            }
            leftSum += nums[i];
        }

        return -1;  // No pivot index found
    }
};
