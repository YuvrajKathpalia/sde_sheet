https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1


//brute...
//n cube..khud...

//set me insert krdo uss window ke me jitne character aaree...agar set ka size k ke barabaer
//to length caclulate kro..aur max len variable bhi bna lena...track krte rhna...


class Solution {
public:
    int longestKSubstr(string s, int k) {
        
        
        int n = s.size();
        int max_len = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                
                unordered_set<char> unique_chars;
                
                for (int l = i; l <= j; l++) {
                    
                    unique_chars.insert(s[l]);
                }
                
                if (unique_chars.size() == k) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};



//better....
//n square....



class Solution {
public:
    int longestKSubstr(string s, int k) {
        
        int n = s.size();
        int max_len = -1;
        
        for (int i = 0; i < n; i++) {
            
            unordered_set<char> unique_chars;
            
            for (int j = i; j < n; j++) {
                
                unique_chars.insert(s[j]);
                
                if (unique_chars.size() == k) {
                    max_len = max(max_len, j - i + 1);
                }
                
                else if (unique_chars.size() > k) {
                    break;
                }
            }
        }
        
        return max_len;
    }
};


//optimal///

// 2 pointer sw..
//easy doable...
//n , n

//map liaa freq store krne ke liye characters ki...
//l,r pointer... r aya , freq bdai map me..

//fir while loop me sliding window mismatch ki condition lgade...jab tk map ka size >k hai , to jo left pe pda
//uski freq-- krta rha ,aur l++ krta rhe...jab mp[s[l]]==0 hojega, wo map se remove krdio...

//aur main condition jab map ka size==k ho to length update krte rho..

//aur r++ krte rho..


//longest substring without repeating characters ke 2 pointer wale me index store krre the ek array me har position ki
//agar wo position phle se covered hai/repeating ch milgya aur wo usi window ke andar hai , l++ krte the(l=hash[s[r]]+1 krke)(jo last position thi us elemnt
//ki usse ek age lejate the l ko..)..




class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        int n=s.size();
        
        unordered_map<char,int>mp;
        
        int l=0;
        int r=0;
        
        int maxlength =-1;
        
        
        while(r<n){
            
            mp[s[r]]++;
            
            while(mp.size()>k){
                
                mp[s[l]]--;
                
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            
            
            if(mp.size()==k){
                
                maxlength = max(maxlength ,r-l+1);
            }
            
            r++;
        }
        
        return maxlength;
    
        
    }
};
    



//count no nof substrings with k different chracters...


//simpler version of longest susbtring with exactly k differne tcharacters...
//isme quesntion me no pof substring return krni..to length maintain krni ki joorat ni kuch..

//brute force..

//n^2..n..

class Solution
{
  public:
    long long int substrCount (string s, int k) {
        
        
        int n=s.length();
        int count=0;
        
        for(int i=0;i<n;i++){
            
            unordered_set<char>sett;
            
            for(int j=i;j<n;j++){
                
                sett.insert(s[j]);
                
                if(sett.size()==k){
                    count++;
                }
                else if(sett.size()>k){
                    break;
                }
            }
        }
        return count;
    	
    	
    	
    }
};