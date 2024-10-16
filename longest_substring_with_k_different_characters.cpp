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


//optima;\l///

// 2 pointer sw..

//n , n

class Solution {
public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> freq_map; // To store the frequency of characters
        int left = 0;                       // Left pointer for the window
        int max_len = -1;                  // To keep track of the maximum length
        int right = 0;                      // Right pointer for the window

        int n=s.size();

        // Use while loop for the right pointer
        while (right < n) {
            // Increment the count of the current character
            freq_map[s[right]]++;

            // If the size of the frequency map exceeds k, shrink the window
            while (freq_map.size() > k) {
                // Decrease the count of the leftmost character
                freq_map[s[left]]--;
                // If the count becomes zero, remove it from the map
                if (freq_map[s[left]] == 0) {
                    freq_map.erase(s[left]);
                }
                // Move the left pointer to the right
                left++;
            }

            // If the size of the frequency map is exactly k, update max_len
            if (freq_map.size() == k) {
                max_len = max(max_len, right - left + 1);
            }
            
            // Move the right pointer to the right
            right++;
        }

        return max_len; // Return the maximum length found
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