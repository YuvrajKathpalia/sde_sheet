#include<bits/stdc++.h>
using namespace std;


bool isprime(int n){
    
    if(n==0 || n==1){
        return false;
    }
    
    for(int i=2;i<=sqrt(n);i++){
        
        if(n%i==0){
            return false;
        }
    }
    
    return true;
}
int solve(vector<int>&nums, int n){
    
    int sum=0;
    
    for(int i=0;i<n;i++){
        if(isprime(i)){
            
            sum += nums[i];
        }
    }
    
    return sum;
}
int main()
{
    int n;
    cin>>n;
    
    vector<int>nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    int sum = solve(nums,n);
    
    cout<<sum;

    return 0;
}