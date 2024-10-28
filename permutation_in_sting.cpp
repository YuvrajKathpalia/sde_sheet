
https://leetcode.com/problems/permutation-in-string/description/



//brute force..


//o(n2-n1+1* n1)==o(n2*n1)
//o(1)..

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if (n1 > n2){
            return false;
        }
        
        
        vector<int> freqS1(26, 0);

        for (char c : s1) {
            freqS1[c - 'a']++;
        }
        

        //s2 me loop lgao..n1 length ki substring extract krte rho.. .substr se...us substring ka freq count vector bnao
        //freq store kro...

        //agar us substring ka freq vector==s1 ka freq vector
        //return true..
        
        for (int i = 0; i <= n2 - n1; i++) {

            string substring = s2.substr(i, n1);  // Extract substring of length n1

            vector<int> freqSub(26, 0);
            
            // Calculate frequency of the substring  ..//o(n1)..
            for (char c : substring) {
                freqSub[c - 'a']++;
            }
            
            if (freqS1 == freqSub) {
                return true;
            }
        }
        
        return false;
    }
};


//optimal ...2 pointer sliding window...

//2 freq vector bnalenge..freq store krlenge ..phle s1 ki...
//fir loop lgayge..r<n2..

//freq ++ krenge r pe jo charcter h uski s2 string me..
//fir ek if condition window se bahr jane ki...agar bahr ho to left pe jo char uski freq--..aur l++..

//aur agar dono vector equal hai (aur substring ka length n1 ke barabar hi hai.)..to true return krdo...

//doale.hogya tha..

//o(n2)..
//o(1)...o(26)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        
        int n1=s1.length();
        int n2=s2.length();

        if(n1>n2){
         return false;
        }

        vector<int>freq_s1(26,0);   //0-1,1-1..(for ab)
        vector<int>freq_s2(26,0);

        for(char c:s1){
            freq_s1[c-'a']++;
        }

        int l=0;
        int r=0;


        while(r<n2){

            freq_s2[s2[r]-'a']++;

            while(r-l+1>n1){

                freq_s2[s2[l]-'a']--;

                l++;
            }

            if(r - l + 1 == n1 && freq_s2==freq_s1){
                return true;
            }

            r++;
        }

        return false;
        
    }
};