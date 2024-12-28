//bhot acha...famous...


//brute force..
//o(n^2)..

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int n = arr.size();
        int count = 0;

        // Iterate through all subarrays
        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {

                sum += arr[j];  // Calculate sum of subarray from i to j
                
                if (sum == 0) {
                    count++;  // Increment count if sum is 0
                }
                // if(sum>0){  //ye ni krenge kyuki kya pta -ve numbers ki wjh se -ve hogya ho baad me dubara khi 0 hojaye
                //     break;
                // }

                //ase bhi ni krege - if(arr[i]+arr[j]==0)..2 elements ka thoda chie subbary dekhna
            
            }
        }

        return count;
    }
};



//optimal..prefix sum , unordered map..

//o(n)..
//o(n)..

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        
        
        int n=arr.size();
        int count=0;
        
        unordered_map<int,int>mpp;
        
        mpp[0]=1;
        
        int sum=0;
        
        
        for(int i=0;i<n;i++){
            
             sum += arr[i];
            
            if(mpp.find(sum)!=mpp.end()){
                
                count+= mpp[sum];
                
            }
            
            mpp[sum]++;
        }
        
        return count;
    }
    
    
};
