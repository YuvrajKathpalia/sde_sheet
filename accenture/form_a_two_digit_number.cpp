

Given an array of integers, find the most frequent and second most frequent elements. Return a number formed by concatenating the second most frequent element and the most frequent element.


#include <bits/stdc++.h>
using namespace std;

int solve(int arr[] , int n){
    
    
    unordered_map<int,int>mpp;
    
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    
    
    int maxfreq=-1;
    int secondmaxfreq=-1;
    int mostfreq=-1;
    int secondmostfreq=-1;
    
    for(auto x:mpp){
        
        int count=x.second;
        int num =x.first;
        
        
        if(count>maxfreq){  //update second max wala phle..(uske jo purana maxfreqmostfreq tha usse replace rkdo)
        
        secondmostfreq = mostfreq;
        secondmaxfreq=maxfreq;
        
        
        mostfreq=num;
        maxfreq=count;
            
        }
        
        else if(count>secondmaxfreq || (count==secondmaxfreq && num < secondmostfreq)){  //ab agar sirf second,axfreq se jada ayi hai freq tb bhi update krna pdega...sirf secondmax wala.....agar same freq milti aur number chota purane wale se to wo chuno
        
        secondmostfreq = num;
        secondmaxfreq=count;
        
            
        }
    
        
    }
    
    return secondmostfreq*10 + mostfreq;
    
    //example... 2 , 3 hai respectievly..to 23 krna na..
}

int main()
{
    
    int n;
    cin>>n;
    
    int arr[n];
    
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int ans =solve(arr,n);
    
    cout<<ans;
    
    
    return 0;
}