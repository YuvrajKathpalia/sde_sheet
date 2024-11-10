


https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1?page=1&category=Strings&sprint=a663236c31453b969852f9ea22507634&sortBy=submissions


//easy,khud..
//o(n)..
//o(26)..


string firstRepChar(string s)
{
    
    int n=s.size();
    
    int freq[26] ={0};
    
    int mini=INT_MAX;
    
    for(int i=0;i<n;i++){
        
        char ch= s[i];
        
        freq[ch-'a']++;
        
        if(freq[ch-'a']>1){   //agar repating hai to index store krlo...jiska second occurnce ka index sbse kum wo return krna hai na
            mini = min(mini,i);
        }
    }
    
    if(mini==INT_MAX){
        return "-1";
    }
    
    
    return "s[mini]";  //string return krni na.. 1 length ki string of s[mini]..
    
    
}