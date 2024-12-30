https://www.geeksforgeeks.org/problems/single-number1014/1


//koi ek number ki frequency odd hai wo return krna...
//brute force ..unirdered map..o(N)..o(n)..

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int,int>mpp;
        
        for(auto x:arr){
            mpp[x]++;
        }
        
        for(auto x:mpp){
            if(x.second%2==1){
                return x.first;
            }
        }
        
        return -1;
    }
};


// User function template for C++


//optimal approach...xor lelo poore array ka...jo even times aare hinge wo to cancel out 
//hojege...
//jo ek rehjayga whi odd hoyga..

//o(n)..o(1)..

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        
        int result =0;
        
        for(auto x:arr){
            result ^= x;
        }
        
        return result;
        
        
    }
};