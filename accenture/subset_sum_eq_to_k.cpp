// Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum. 
// Input :  

// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the sum. 

// Output : 

// Count all the subsets of given array with sum equal to given sum. 

// NOTE: Since result can be very large, print the value modulo 109+7. 




//QUITE DIFFERENT FROM SUBBARRAY SUM EQU TO K...SUBARRAY ME CONTAINOUS ELEMENETS HI LENE HOTE..
//ISLIE USME BRUTE FOR O(n^2)..AUR BETTER..PREFIX SUM+HASHMAP CHLJATI



//COUNT OF SUBSET BTANA..

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Recursive function to count subsets
int countWays(int i, int sum, vector<int>& nums) {
    if (sum == 0) return 1;                     // valid subset
    if (i == 0) return (nums[0] == sum ? 1 : 0); // only one element left

    // Exclude current element
    int notPick = countWays(i - 1, sum, nums);

    // Include current element if it's not greater than sum
    int pick = 0;
    if (nums[i] <= sum)
        pick = countWays(i - 1, sum - nums[i], nums);

    return (pick % MOD + notPick % MOD) % MOD;
}

int countSubsets(vector<int>& nums, int sum) {
    int n = nums.size();
    return countWays(n - 1, sum, nums);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int sum;
        cin >> sum;

        cout << countSubsets(nums, sum) << endl;
    }

    return 0;
}
