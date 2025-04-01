
//BRUTE..LINEAR SEARCH...O(N)..



class Solution {
    public:
        int findMin(vector<int>& nums) {
            
            int minElem = nums[0]; 
    
    
            for (int i = 1; i < nums.size(); i++) {
                minElem = min(minElem, nums[i]);
            }
    
            return minElem;  // Return the minimum element found
        }
    };
  
    
    //APPROACH 2 BINARY SEARCH...
    
    //yhi thoda alag jisme..s<e ..aur e=mid lagra..baki jadakar me...s<=e ,aur s=mid+1,e=mid-1..

//binary search..optimal..
//o(logn)..o(1)..


//mid nikalo.. agar mid end wale se nada hai..to mtlb smallest mid aur e ke beech hai , s ko aage leao..
//else e ko peeche leaao..

//last me nums[s]/nnums[e] return krdena.. usi pe min pda hoga dry run krke dekhlo obvio...

//isme..s<e lgana pdega..aur e=mid krna pdega...yaad rkhna..ek edge case phas jayga warna..
//aur koi base condition jaise if(mid==0)return min something like that bhi nhi krna..
//kyuki hume pta thodi abhi konsa min hoskta...koi target thodi find krre h mbinary search ke through..
//bas search space kum krre..

//last me s,e same jagah pe ajge..wo element reutrn krna..whi minimum element hai...

//o(logn)..
//o(1)..


class Solution {
public:
    int findMin(vector<int>& nums) {

        int n= nums.size();

        int s=0;
        int e=n-1;

        while(s<e){

            int mid = s+(e-s)/2;

            if(nums[mid]>nums[e]){

                s=mid+1;
            }
            else{
                e=mid;    

            }
        }     

        return nums[s];   
    }
};



