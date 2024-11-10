https://leetcode.com/problems/longest-palindrome/


//phle to jo char even times aree , unka count add krlo..kyuki wo to araam se ajenge palindrome me..
//aur jo odd times aare..unka frequency-1 krke add up krlo..agar a 3 bar ara..to 2 add krlo..aa to palindorme aaskta na
//ek boolean pointer bhi mainain krlena , kyuki agar last me ek odd bacha hai , wo bhi palindrome ka hissa bnskta haina (agar center pe ho)

//o(n)..
//o(n).

class Solution {
public:
    int longestPalindrome(string s) {

        int n=s.size();

        unordered_map<char,int>mpp;

        for(auto x:s){
            mpp[x]++;
        }

        int count=0;
        bool hasodd=false;

        for(auto x:mpp){

            if(x.second%2==0){
                count += x.second;
            }
            else{
                count += x.second-1;
                hasodd=true;             
            }
        }

        if(hasodd){  //agar kisi bhi ek ch ka count last me 1 pda hai , wo bhi ek bar add hojega na
            count++;
        }

        return count;

    }
};