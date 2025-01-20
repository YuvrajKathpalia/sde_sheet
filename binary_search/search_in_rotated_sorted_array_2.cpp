//duplicate value bhi hoskti..but uski tension ni hume to true/false return krna

//ek if condition extra lgani pdegi...agar jaise mid pe ho ..
//na to wo s bada hai hai na e se bada jo hum sorted half nikalpaye
//aur wo left aur right dono ke equal hai..
//like this--..3 1 2 3 is one half, and 3 3 3 is another half and our mid is element 3 also it at index '3'

//ab kis half ko elminiate kroge??...ase me if condition lgadena..s+..e--. 
//krke next iteration pe chle jana..



class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Handle duplicates...agar mid pe jo hai wo..start ya end ke barabar hai..aur
            //target ni hai wo number...tab to araam se s++,e-- krke search space kum krskte hai..
            //hume first occuring index jaisa to mention hai ni , hume to true ya false btanna hai bas..
            
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
                continue;
            }

            // Left half is sorted
            if (nums[s] <= nums[mid]) {
                if (nums[s] <= target && target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return false;
    }
};