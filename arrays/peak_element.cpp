
https://www.geeksforgeeks.org/problems/peak-element/1?page=1&sortBy=submissions

//brute..o(n)..o(1)

class Solution
{
public:
    int peakElement(vector<int>&arr){
        
        
        int n=arr.size();
        
        
       
        if (n == 1){
            return 0;
        }
            
            

        for (int i = 0; i < n; i++)
        {      
            if (i == 0)
            {
                if (arr[i] >= arr[i + 1])
                    return i;
            }
            else if (i == n - 1)
            {
                if (arr[i] >= arr[i - 1])
                    return i;
            }
            else
            {
                if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
                    return i;
            }
        }


        return -1;
    }
};



//optimal..o(logn)..o(1)

class Solution {
public:

    int peakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0; // Only one element, it must be the peak
        }

        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;


            
            if ((mid == 0 || nums[mid] >= nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] >= nums[mid + 1])) {
                return mid;
            }


            // If mid is in a rising slope, move right
            if (mid < n - 1 && nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            }
            // Else move left
            else {
                e = mid - 1;
            }
        }

        return -1; // This return should technically never be hit
    }
};
