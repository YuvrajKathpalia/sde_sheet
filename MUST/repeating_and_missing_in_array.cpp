https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating

//brute..
//o(n^2)...o(1)..

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
    
    
     int n=arr.size();
     
     int missing=-1;
     int repeating=-1;
     
     for(int i=1;i<=n;i++){  //<=n ayga obvio..1 se n tk numerse check krre...
         
         int count=0;
         
         for(int j=0;j<n;j++){  //given array me traverse krke dekhre.. 
             
             if(arr[j]==i){
                 count++;
             }
         }
         
         if(count==2){
             repeating=i;
         }
         else if(count==0){
             missing=i;
         }
         
         if(missing!=-1 && repeating!=-1){  //agar missing repeating dono milgye h bahar ajao..
             break;
         }
         
     }
     
     
     return {repeating,missing};
     
     
     
     
    }
};

//approach2..
//BETTER... HASH ARRAY LELO/UNORDERED MAP LLO...



//approach..3..

//OPTIMAL...O(N...O(1))
//JAISE MBERS AARE JAISR ARRAY HAI..[4,3,1,1,2,6]... TO JAISE 4 AYA ...TO 3RD INDEX KO -VE KRDO(MARK KRDO) ASE ASE CHLTA RHEGA
///AUR AGAR KOI INDEX PHLE SE -VE HAI MTLB WO REPARTING HAII...

//FIR EK LOOP AUR LGAO MISSING NIKALNE K LIE...
//JO BHI ELEMEN TPOSITIVE PDA ...MTLB WO -VE MARKED NI HUAA...MTLB I+1 RETURN KRDO WO MISSING HUA...

//AGAR SIRF REPEATING POOCHE YHI BTANAA....AGAR SIRF MISSING POOCHE
//TAB TO BHOT TAREEKE ..(1ST APPROACH..BRUTE...BETTER..EXPECTEDSUM-ACTUALSUM....
//BEST.... 1-N KA XOR LELO , FIR WHI XOR GIVEN ARRAY SATH LELO , JO RESULT AYGA WO MISSING WALA HI HOGA..)


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        int n =arr.size();
        
        int missing=-1;
        int repeating=-1;
        
        
        for(int i=0;i<n;i++){
            
            int index = abs(arr[i])-1;
            
            if(arr[index]<0){
                repeating = abs(arr[i]);
            }
            else{
                arr[index] = -arr[index];
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(arr[i]>0){
                missing =i+1;
            }
        }
        
        return {repeating,missing};
    }
};