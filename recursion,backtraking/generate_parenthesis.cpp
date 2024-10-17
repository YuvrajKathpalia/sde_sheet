https://leetcode.com/problems/generate-parentheses/


//Recurssion...

//condition , recursive call , base call...

//ek khali string se start kro.,opening,closing bracket ka count lo 0 shuru me
//.(agr opening bracket ka count<n , to call do usme string me ="(" krdena aur opeing ka count++..
//aur agar ye match ni hori to dekho agar closingbracket ka count opeing bracket se kum hai to call deke s me +")"
//krdena aur closing ka count++ krdena..ase chlte rhnaa..

//basecase agar dono ka count n hogya to vector,string>me push krdena string..



// tc..o(2^n)..2 option hai naopening/closing..
//o(n)..


class Solution {
public:

void solve(vector<string>&ans, string s , int n , int openingcount , int closingcount){

    if(openingcount==n && closingcount==n){
        ans.push_back(s);
        return;
    }
    if(openingcount<n){
        solve(ans,s+"(",n,openingcount+1,closingcount);
    }

    if(closingcount<openingcount){
        solve(ans,s+")",n,openingcount,closingcount+1);
    }
}
    vector<string> generateParenthesis(int n) {
        
        int openingcount=0;
        int closingcount=0;

        vector<string>ans;

        string s="";

        solve(ans,s,n,openingcount,closingcount);

        return ans;
    }
};