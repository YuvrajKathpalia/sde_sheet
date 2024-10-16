https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

//brute force...


//o(n*k)..
//o(n)..




vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int K) {
                                                 
                                                 
                                                 
    vector<long long >ans;
    
    
    for(int i=0;i<=N-K;i++){
        
        bool foundnegative = false;
        
        for(int j=i;j<i+K;j++){
            
            if(arr[j]<0){
                foundnegative=true;
                ans.push_back(arr[j]);
                break;
            }
        }
        
        if(!foundnegative){
            ans.push_back(0);
        }
    }
    
    return ans;
                                                 
 }



 //optimall..

//deque.....
//o(n)..
//o(k)..


//negative hai to hi push_back..
//aur jo elements window ke bahar hote jare unko pop krdo(fornt)...

//aur baaadme jab i , k-1 thak phoch jaae tab push shuru...
//agar empty ni hai dq..to front wala push...
//aur empty hai to 0 ...



vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int k) {
                                                 
                                                 
                                                 
    vector<long long >ans;
    deque<long long>dq;
    
    
    for(int i=0;i<N;i++){
        
        
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }
        
        
        if(arr[i]<0){
            dq.push_back(i);
        }
        
        if(i>=k-1){
            
            if(dq.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[dq.front()]);
            }
        }
    }
    
    
   
    return ans;
                                                 
 }