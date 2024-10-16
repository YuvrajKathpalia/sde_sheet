// OR NO OF SUBARRAY WITH K ODDS..

https://leetcode.com/problems/count-number-of-nice-subarrays/

//brute force..
//generate all subarrays..

//o(n^2)..
//o(1)


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int count=0;
        int n=nums.size();

        for(int i=0;i<n;i++){

            int oddcount=0;
            for(int j=i;j<n;j++){

                if(nums[j]%2==1){
                    oddcount++;
                }
                if(oddcount==k){
                    count++;
                }
                else if(oddcount>k){
                    break;
                }
            }
        }
        return count;
    }
};



//optimal..
//2 pointer ,sw

//silly...


//we can treat this question similar to binary subbaray with given sum...
//leetcode 930..
https://leetcode.com/problems/binary-subarrays-with-sum/

//usme kya thaa 1,0 ka array tha aur btanaa tha no of subbarray with sum=k...
//to 2pointer sw se kya kra...l,r maintain krenge...sum calculate krenge...
//agar sum bdaa hogya k se , shrink krdenge window ,sum bhi minus krdenge jo elemnt nikalre , 
//agar sum k ke barabar hogyaa to , count++ krenge till that length of subaaray(sare possible l to r..mtlb all subarray
//whose sum less than equal to k )
//waise hi all subarrays with sum less than eual to k-1..fir dono ko subtract krke whi milega...no of subarray with sum exactly equal to k


//ab is problem me bhi whi krskte...saare odd no ko 1 ki trh treat krte hai , aur even ko  ki trh krte hai..
//aur k ko requiredsum ki trh...same question bngya...


//o(2*2n)=o(4n)
//o(1)..

class Solution {
public:

int solve(vector<int>& nums, int k){

    int n=nums.size();

    int count=0;

    int l=0;
    int r=0;

    int sum=0;


    while(r<n){

        sum += nums[r]%2;  //0 ya 1 me krdia

        while(sum>k){

          sum = sum - nums[l]%2;  //isko bhi 0 ya 1 me krdia..
          l++;
        }

        count += r-l+1;  //sare possible add

        r++;

    }

    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {


        return solve(nums,k)-solve(nums,k-1);
        
    }
};