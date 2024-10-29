

https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1?page=1&sortBy=submissions


///easy...optimal..
//use unordered map...
//phle a1 array ke ele,nts map krlo..
//fir a2 me loop lgao aur check kro , wo elemnt mapped hai na(aur mapped h to count >0))
//hai na...tabhi uska count-- kro...warna ye valid ni to invalid situation return no...


string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int,int>mp;
    
    for(int i=0; i<n;i++){
        mp[a1[i]]++;
    }
    
    
    for(int j=0;j<m;j++){
        
        if(mp.find(a2[j])!=mp.end() && mp[a2[j]]!=0){
            
            mp[a2[j]]--;
            
        }
        
        else{
            return "No";
        }
    }
    
    return "Yes";
    
    
}