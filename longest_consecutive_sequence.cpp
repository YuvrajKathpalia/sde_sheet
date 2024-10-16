https://leetcode.com/problems/longest-consecutive-sequence/





//brute...
//n square..


#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}


//betterr ..n logn..sort krddo...
// one


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;  
        }

        sort(nums.begin(), nums.end());  
        
        int longest = 1;  
        int currentCount = 1;  

        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1]) {
                // Skip duplicates
                continue;
            } 
            else if (nums[i] == nums[i - 1] + 1) {
                currentCount++;
            } else {
                // Otherwise, update the longest sequence and reset current sequence count
                longest = max(longest, currentCount);
                currentCount = 1;  // Reset for the new sequence
            }
        }

        // Return the maximum of the last sequence or the overall longest found
        return max(longest, currentCount);
    }
};









//opimtal.... n .

//LINEAR SEARCH SE SWARCH KRNE KI BAJAYE...
//SETME DAALDIAA..USME INSERTION LOOPUP CONSTANT TIME LETA NAA...

//LOOP LGAYA SETME CHECK KIAA..AGAR WOELEMENT STARTING ELEMNT HAI..MTLB USKA -ONE EXIST
//NI KRTAA TO USSE CHECK KRNA SHURU KRENGE...FIR WHILE LOOP ME CHECK KRENGEE...
//FIR STREAK BHI  STREAK UPDATE KRDENEGE..

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        

        if (nums.empty()) {
            return 0;
        }

        // Create a set to store all the numbers (for O(1) lookups)
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int longestStreak = 0;

     
        for (int num : numSet) {
            // Only check if `num` is the start of a sequence (i.e., `num - 1` doesn't exist)
            if (numSet.find(num - 1) == numSet.end()) {
                // Now this is the start of a sequence
                int currentNum = num;
                int currentStreak = 1;

                // Keep checking for consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Update the longest streak if the current one is longer
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;


    }
};