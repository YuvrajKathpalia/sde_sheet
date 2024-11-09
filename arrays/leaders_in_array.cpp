https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?page=1&category=Arrays&sprint=a663236c31453b969852f9ea22507634&sortBy=submissions


//brute..

//o(n^2)..o(1)...

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        
        
        int n=arr.size();
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            
            bool isleader=true;
            
            for(int j=i+1;j<n;j++){
                
                if(arr[i]<arr[j]){
                    isleader=false;
                    break;
                }
            }
            
            if(isleader){
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};



//optimal

//peeche se chlte hai...last elemnt to leader hoga hi hmesha..usse push back krlia phle hi
//aur usse maxi manlia
//second last se 0 tk loop lgaya..

//agar element maxi se bda aya to push back ans me, aur mxi update krte rhna..
//bas...

//last me ans vector reverse krdena...

//o(n)..
//o(n)..


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        
        
        int n=arr.size();
        
        vector<int>ans;
        ans.push_back(arr[n-1]);
        
        int maxi = arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};