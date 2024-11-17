

You are given an encoded string where each letter of the alphabet is represented as a sequence of 1s. The number of 1s corresponds to the position of the letter in the alphabet.

For example:

a is represented as 1
b is represented as 11
c is represented as 111
d is represented as 1111
...
z is represented as 11111111111111111111111111 (26 ones)
The encoded string is a sequence of 1s, where 0 acts as a separator between different characters. The task is to decode the string and return the corresponding alphabetic sequence.

Write a function solve that decodes the given string and returns the corresponding alphabetic sequence.


...exampple... 11101 = cb...


//mapping krdi phle to ...0-25 tak a-z ki ki...char array leke...


#include <bits/stdc++.h>
using namespace std;

string solve(string &s){
    
    int count=0;
    string ans="";
    

    
    char freq[26];
    
    for(int i=0;i<26;i++){
        
        freq[i]= 'a' +i;
    }
    
    for(int i=0;i<s.length();i++){
        
        if(s[i]=='1'){
            count++;
        }
        else{
            if(count>0){
            ans += freq[count-1];
            count=0;
        }
        }
    }
    
    
    // Handle any remaining '1's at the end of the string...akhri set of 1s ko handle krne ke lie..
    
    if (count > 0) {
        ans += freq[count - 1];
    }

    
    return ans;
}

int main()
{
    
   string s;
   cin>>s;
   
   string ans=solve(s);
   
   cout<<ans;
   
    return 0;
}