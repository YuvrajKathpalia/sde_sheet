//brute force..

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){

                sum+=nums[j];

                if(sum==k){
                    count++;
                }

                
            }
        }
        return count;
    }
};


//optimal..o(n)..o(1)...cumulative sum,unordered map..
//easy...
//sum add krte gye..agar sum-k phle se mapped to mtlb beech me sum k ke equal banra hai..

// nums = [1, 2, 3], k = 3
// prefix sums = [1, 3, 6]

// → At i=1 (prefix = 3), sum - k = 0 → mp[0] = 1 → subarray [1, 2] has sum 3
// ✅ It works perfectly because subarrays are continuous, and prefix sums are meant for tracking running totals from left to right.
//ye approach SUBSET ME NI SKTE KYUKI USME CONITUOUS DHOONNDA JROORI NI...



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n=nums.size();
        int sum=0;

        int count=0;


        unordered_map<int,int>mp;

        mp[0]=1;  //silly..agr phla element hi k ke barabar agya..to k-k=0..islie 0 phle se mapped rkha..

        for(int i=0;i<n;i++){

            sum +=nums[i];

            if(mp.find(sum-k)!=mp.end()){
               count += mp[sum-k];
            }

            mp[sum]++;
        }
        return count;
    }
};