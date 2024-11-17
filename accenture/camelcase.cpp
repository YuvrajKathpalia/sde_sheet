#include <iostream>
#include <string>

using namespace std;

int main() {
    // Write C++ code here
    string s1;
    cin>>s1;
    int n=s1.length();
    string ans="";
    
    for(int i=0;i<n;i++){
        char ch=s1[i];
        
        if(islower(ch)){
            ans+=toupper(ch);
        }else{
            
        cout<<ans<<endl;
                ans="";
                ans+=tolower(ch);
            
        }
    }
    
    if(ans.length()>0){
        cout<<ans<<endl;
    }

    return 0;
}