
https://leetcode.com/problems/reverse-pairs/description/

//brute..
//n^2
//1

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(nums[i]>2*nums[j]){
                    count++;
                }
            }
        }

        return count;
        
    }
};



//optimal..
//nlogn
//n


#include <vector>
using namespace std;

class Solution {
public:
    


//o(n) hi hai iski bhi..kyuki ek loop left half me chlra, ek right half me..
    void countPairs(vector<int>& nums, int low, int mid, int high, int& count) {
        int right = mid + 1;

        // Count how many elements in the right half
        // are such that nums[i] > 2 * nums[right] for every low...(nested loops)

        for (int i = low; i <= mid; i++) {

            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1)); // Count valid pairs for each nums[i]
        }
    }

    // Merge function to merge two halves of the array
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy the merged elements back to the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    
    int mergesort(vector<int>& nums, int low, int high, int& count) {
        if (low >= high) {
            return count;
        }

        int mid = low + (high - low) / 2;

        mergesort(nums, low, mid, count);
        mergesort(nums, mid + 1, high, count);
        
        // Count pairs before merging the two halves
        countPairs(nums, low, mid, high, count);

        // Merge the two halves
        merge(nums, low, mid, high);

        return count;
    }

    // Main function to find the number of reverse pairs
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        mergesort(nums, 0, n - 1, count);

        return count;
    }
};