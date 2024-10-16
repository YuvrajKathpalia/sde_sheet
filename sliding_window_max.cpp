
https://leetcode.com/problems/sliding-window-maximum/

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

//brute force..

//o(n*k)..
//o(n)

class Solution {
public:
   
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int n = nums.size();


    for (int i = 0; i <= n - k; i++) {
        int max_val = nums[i];

        
        for (int j = i; j < i + k; j++) {
            max_val = max(max_val, nums[j]);
        }

      
        result.push_back(max_val);
    }

    return result;
}
};





//optimal deque...


//o(n)..
//o(k)...

//deque maintain krenge...(indexes storee krenge)

//front 1,2,3..aate jare jaise..jaise 2 aya ek ke baad to 1 pop krdengee..
//peeche wala(front wala) minimum ka koi joorat ni...

//agar front pe bda pdaa tab normal add krte rahengee..

//agr index k-1 tak phochgyaa to front pe jo index pdaa uska element return krdenge...
//aur agar window poori hogyi..to front wala pop krdengee...(push ni krte rhenge har wkt)..



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n=nums.size();
        vector<int>ans;

        deque<int>dq;

        for(int i=0;i<n;i++){

            if(!dq.empty() && dq.front() == i-k){         //agar window ke bahar aaraa..
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<=nums[i]){    //chotee wale pop krte jao..
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1){   //jab k-1 ya usse aage phoch jega..tabse har iteration me push bakc krenge..jo front pe index pda hoga uska element...
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;

        
    }
};