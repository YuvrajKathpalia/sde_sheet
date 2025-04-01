//binary search..
//phle check kro konsa part sorted uspe lgao bs... agar nums[s]<=nums[mid] ro left part sorted h warna right part
//sorted hoga obvio...

//ab dono if/else ke andrr 
//individually normal binary search lgake target dhundho ..eliminate hote jayge hisse..


//o(logn)
//o(1)..



class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size();

        int s=0;
        int e=n-1;


        while(s<=e){

            int mid = s+ (e-s)/2;


            if(nums[mid]==target){
                return mid;
            }


            else if(nums[s]<=nums[mid]){ 

                if(nums[s]<=target && target<=nums[mid]){   
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }

            else{

                if(nums[mid]<=target && target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }

        return -1;
        
    }
};