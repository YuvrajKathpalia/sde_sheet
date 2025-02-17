//o(n^2)..o(1)..

#include<bits/stdc++.h>
using namespace std;
    
bool containsDuplicate(vector<int> nums) {
 
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] == nums[j]) {
                return true;
            }
        }
    }

    return false;
}


//o(nlogn)+o(n)..
//o(1)..

#include<bits/stdc++.h>
using namespace std;
    
bool containsDuplicate(vector<int> nums) {
 
    sort(nums.begin(),nums.end());
    
    for(int index = 1; index < nums.size(); index++) {
        if(nums[index ] == nums[index - 1]) {
            return true;
        }
    }

    return false;
}
  


//o(n)..
//o(n)...

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){

            mp[nums[i]]++;
        }

        for(auto x:mp){
            if(x.second>1){
                return true;
            }
        }


    return false;
    }
};