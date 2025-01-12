https://leetcode.com/problems/construct-k-palindrome-strings/submissions/1505048264/?envType=daily-question&envId=2025-01-11


//freq cont krlo...
//fir jitne characters ki frequency odd hai.. 
//unse deal krna pdega..kyuki even wale to palindrome banadenge..
//odd waale bnadenge agar beech me place krde unhe..but agar ye oddcount >k hogye to k different palindrome to
//ni bna paenge...


//also k ki length to s hi kum honi chiee..

//o(n)..
//o(1)..

class Solution {
public:
    bool canConstruct(string s, int k) {

        int n=s.length();

        if(k>n){
            return false;
        }

        vector<int>freq(26,0);

        for(int i=0;i<n;i++){

            freq[s[i]-'a']++;
        }

        int oddcount=0;


        for(int x:freq){

            if(x%2!=0){
                oddcount++;
            }
        }

        return oddcount<=k;
        
        
        
    }
};