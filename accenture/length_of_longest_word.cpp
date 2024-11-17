

//ex .. hi my name is yuvraj
//ans =6...

//jab string user se loge tab..string s; getline(cin,s);
//krna pdega..sirf cin>>s nhi krskte... getline se se poori string 
//pdletaa spaces bhi...


#include <bits/stdc++.h>
using namespace std;


int solve(string& s){
    
    int maxlength=-1;
    int length=0;
    
    for(int i=0;i<s.length();i++){
        
        
        if(s[i]!=' '){
            length++;
            maxlength=max(maxlength,length);
        }
        else{
            length=0;
        }
    }
    
    return maxlength;
}
int main()
{
    string s;
    getline(cin,s);
    
    int ans=solve(s);
    
    cout<<ans;

    return 0;
}