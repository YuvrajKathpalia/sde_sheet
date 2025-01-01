https://leetcode.com/problems/max-consecutive-ones-iii/description/


//brute..easy..
//.o(n^2)..nested loops..khud.

//agar 1 ara count++ krte rho , agar 0 ara aur changes<k tab bhi krte rho , wrna k changes hochuke uske baad bhi
//zero ara to break krjao maxlength update krlena...chlte rhege aise loops.


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n=nums.size();
        int maxlength=0;

        for(int i=0;i<n;i++){
            int changes=0;
            int length=0;
            for(int j=i;j<n;j++){

                if(nums[j]==1){
                    length++;     
                }
                else if(nums[j]==0 && changes<k){
                    length++;
                    changes++;
                }
                else{
                    break;
                }
            }
            maxlength = max(maxlength,length);
        }

        return maxlength;
        
    }
};


//optimal...

//2 pointer sliding window...


//zerociunt maintain rkenge ayga ++ krenge...agar out of bound > k hogya...to shrink krna pdega lef++ (aur nums[left] bhi 0
//hua to zerocount-- bhi krna pdega..)aur left++ krdena...aur valid condition hai to maxlength update... aur right++...return
//maxlength krdena..

//o(n+n)... not o(n^2).. because both pointers travserse the array once...(forward hi chlre)(asa ni ki real wala while loop chlra)




class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n=nums.size();

        int l=0;
        int r=0;

        int zerocount=0;
        int maxlength=0;

        while(r<n){

            if(nums[r]==0){
                zerocount++;
            }

            while(zerocount >k){  //if  bhi use krskte the..
                if(nums[l]==0){
                    zerocount--;
                }
                l++;
            }

            if(zerocount<=k){

                maxlength = max(maxlength ,r-l+1);
                r++;
            }
        }
         return maxlength;
        
    }
};