//first repeating elemnt....mtlb jo element doosri baar are
//unka phla occuring sbse kum hona chiye..
//aur quesn me index 1-based type hai..



//brute..o(n^2)..o(1)..

class Solution {
  public:
    int firstRepeated(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    return i + 1; // Return 1-based index
                }
            }
        }
        return -1; 
    }
};


//optimal..use unordered map...
//agar mapped ni..to map krdo elemnt uske index se..
//agar mapped..to ans update kro..min ans chiye..ans=min(ans,mp[arr[i]])..



class Solution {
  public:

    int firstRepeated(vector<int> &arr) {
        
        
        int n=arr.size();
        
        unordered_map<int,int>mp;
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
        
        
            if(mp.find(arr[i])!=mp.end()){
                ans = min(ans,mp[arr[i]]);
            }
            
            else{
                mp[arr[i]]=i;
            }
        }
        
        
        if(ans==INT_MAX){
            return -1;
        }
        
        else{
            return ans+1;
        }
    

    
    }
};
