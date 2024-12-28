
//iterative..optimal.o(N)..o(1)...

//ek pointer se hi hojega...loop lgao,pointer maintain kro..zero ata jara to chlte jao..non zero aya to swap krdo.aur pointer ko age lechlo...ase krte krte non zero shuru me ajege..aur zero last me..


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n=nums.size();

        int index=0;

        for(int i=0;i<n;i++){

            if(nums[i]!=0){
                swap(nums[i],nums[index]);
                index++;

            }
        }
        
    }
};