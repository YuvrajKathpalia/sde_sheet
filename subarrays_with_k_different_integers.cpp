

//brute force..
//o(n^2)..


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){

            unordered_set<int>s;
            for(int j=i;j<n;j++){

                s.insert(nums[j]);

                if(s.size()==k){
                    count++;
                }
                if(s.size()>k){
                    break;
                }
            }
        }

        return count;


        
    }
};


//OPTIMAL..


//traditional 2 pointer sw ni lg payga...

//khud hi dry run krke dekho k=3 ke lie koi bhi array me , jab k se jada hojayga map size,  tum shrink kroge ,
// but guarantee to abhi bhi ni ki ab size 3 hogya kya pta ek-do aur number ho same left wale aage kahi...

//islie approach.. no of subarray with <=k differnt integrs - no of subarray with <=k-1 different integrs

//(2*2n)==o(4n)..
//o(n)..


class Solution {
public:

int solve(vector<int>&nums , int k){

        int n=nums.size();

        unordered_map<int,int>mp;

        int l=0;
        int r=0;

        int count=0;  

        while(r<n){

            mp[nums[r]]++;

           while(mp.size()>k){

            mp[nums[l]]--;

            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;

           }

           count += r-l+1;
           r++;
        }

        return count;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return solve(nums,k)-solve(nums,k-1);

       
    }
};