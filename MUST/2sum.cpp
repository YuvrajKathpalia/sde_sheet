//brute force...
//o(n^2)..
//o(1)..


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        

        int n=nums.size();


        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }

        return {-1,-1};
    }
};


//better...
//o(n)...
//o(n)...


#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        int sum = nums[i];
        int left = target - sum;

        if (mpp.find(left) != mpp.end()) {
            return {i, mpp[left]};
        }
        mpp[sum] = i;
    }

    return {-1, -1};
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    // Print the result
    if (ans[0] == -1 && ans[1] == -1) {
        cout << "No solution found" << endl;
    } else {
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
    
}
