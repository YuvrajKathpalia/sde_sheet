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