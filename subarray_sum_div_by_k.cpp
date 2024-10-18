
https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

//brute...n square...

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){

            int sum=0;
            for(int j=i;j<n;j++){

                sum +=nums[j];

                if(sum%k==0){
                    count++;
                }
            }
        }

        return count;
        
    }
};


//APPROACH2... PREFIXSUM ,HASHMAP

//similar to 523 and 560..
//cumuative sum nikalte jayge... remainder/mod nkalenge..
//fir agar wo mod phle se mapped hoga to wo apne subaray ka part bnaega uska mapped count add krlenege..
//aur uska mapped bhi ++ krdenge bad me
// by default 0 ko 1 se map krke rkheneg we know...


//sliding window  isme ni lgpaygi khud hi socho..
//kabhi condition match hoygi kbhi ni hoygi ,ase predefined rules ni ..khud hi krna shuru kro ni smj ayga
//r kese age leke jaye , kse peeche laye...sirf sum ka hota to dekh skte the...

//o(n)..o(n)..

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
   

     unordered_map<int,int>mp;
     int sum=0;
     int count=0;

     mp[0]=1;

     for(int i=0;i<nums.size();i++){

        sum +=nums[i];

        int mod= sum%k;

        if(mod<0){    //handle if mod is negative(remainder)krke dekhlo.-2 ko 5 se divide ana 3 chie..but % -2 dega..
            mod += k; 
        }

        if(mp.find(mod)!=mp.end()){

            count += mp[mod];
        }

        mp[mod]++;

     }

     return count;

        
    }
};