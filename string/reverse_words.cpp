
#include <bits/stdc++.h>
using namespace std;


string solve(string& s){
    
   int left=0;
   int right=s.length()-1;
   
   string ans="";
   string temp="";
   
   while(left<=right && s[left]==' '){
       left++;
   }
   
   while(left<=right){
       
       char ch=s[left];
       
        if (ch != ' ') {
                temp += ch;
            } 
        
        else if( ch==' '){
            
            if(!ans.empty()){
                if(!temp.empty()){
                    
                    ans = temp + " " + ans;
                }
            }
            
            else{
                ans = temp;
            }
            
            temp="";
        }
        
        left++;
   }
   
   
   if(!ans.empty()){
    if(!temp.empty()){
                    
         ans = temp + " " + ans;
                }
            }
       
       return ans;
   
}
int main()
{
    string s;
    getline(cin,s);
    
    string ans=solve(s);
    
    cout<<ans;

    return 0;
}