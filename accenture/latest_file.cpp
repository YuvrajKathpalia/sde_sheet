
#include <bits/stdc++.h>
using namespace std;


bool isvalid(string& file){
    
    if(file.substr(0,5)!="File_"){
        return false;
    }
    
    for(int i=5;i<file.size();i++){
        
        if(!isdigit(file[i])){
            return false;
        }
    }
    
    return true;
}
int latest(vector<string>&words,int size){
    
    if(size==0){
        return -1;
    }
    
    int maxversion =INT_MIN;;
    
    for(auto file: words){
        if(isvalid(file)){
            
            
            int version = stoi(file.substr(5));
            maxversion =max(maxversion,version);
        }
    }
    
    return maxversion;
}
int main()
{
    
    int n;
    cin>>n;
    
    
    vector<string>input(n);

    
    for(int i=0;i<n;i++){
        
        cin >> input[i];
    }
    
    int ans = latest(input,n);
    
    cout<<ans;
    

    return 0;
}