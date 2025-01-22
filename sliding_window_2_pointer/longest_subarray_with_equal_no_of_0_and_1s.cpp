//brute...o(n^2)..
//o(1)..

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        
        int n=arr.size();
        
        int maxlength=0;
        
        for(int i=0;i<n;i++){
            
            int zerocount=0;
            int onecount=0;
            
            for(int j=i;j<n;j++){
                
                if(arr[j]==0){
                    zerocount++;
                }
                else{
                    onecount++;
                }
                
                if(zerocount==onecount){
                    maxlength = max(maxlength ,j-i+1);
                }
            }
        }
        
        return maxlength;
    }
    
    
};

//optimal..unordered map,prefix sum..
//o(n)..
//o(n)...


//ISME KYA KRAA JO JO 0 THE UN SABKO -1 KRDIA...
//AUR LOOP LGAKE CUMULATIVE SUM ++ KRTE RAHE , AGAR 0 ARA
//TO MAXLEN UPDATE KRRE...

//AUR AGAR WO SUM PHLE KA MAPPED HAI...
//TO ISKA MATLAB USKE BEECH ME TOTAL SUM 0 BNRA HAI NA MTLB USKE
//BEECH EQUAL NUMBER OF 1 AUR -1 AYE TABHI TO..
//IS CASE ME BHI MAXLEN UODATE KRDENGE...


//AUR AGAR SUM PHLI BAAR DIKHRA KOI TO MAP ME STORE KRLENGE 
//KONSE INDEX PE AYA...


class Solution {
  public:
    int maxLen(vector<int> &arr) {
       
       
       int n=arr.size();
       
       for(int i=0;i<n;i++){
           if(arr[i]==0){
               arr[i]=-1;
           }
       }
       
       unordered_map<int,int>mp;
       
       int sum=0;
       int maxlen=0;
       
      
       
       for(int i=0;i<n;i++){
           
           sum += arr[i];
           
           if(sum==0){
               maxlen = max(maxlen ,i+1);
           }
           
           if(mp.find(sum)!=mp.end()){
               maxlen = max(maxlen , i- mp[sum]);
           }
           
           if(mp.find(sum)==mp.end()){
               mp[sum]=i;
           }
       }
       
       return maxlen;
    }
};