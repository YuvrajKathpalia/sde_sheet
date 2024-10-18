


//brute force...
//nested loop lgake substring generate kro , har substring ke liee loop lagake check kro , 
//agar possible ans hai to store krvalo(ek minlength bhi maintain krna pdega..agar ans ki length min length se kum to hi update krna ans)

//o(n^3)..
//o(n)..


class Solution {
public:


bool solve(string& substring , string& t){

    unordered_map<char,int>mp;

    for(auto x:t){
        mp[x]++;
    }

    for(auto x: substring){

        if(mp.find(x)!=mp.end()){
            mp[x]--;
            if(mp[x]==0){
                mp.erase(x);
            }
        }
    }

    return mp.empty();

}
    string minWindow(string s, string t) {

        int m=s.length();
        int n=t.length();

        if(m<n){
            return "";
        }

        string ans="";
        int minlength= INT_MAX;

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){

                string substring = s.substr(i,j-i+1);

                if(solve(substring,t)){

                    int length =substring.length();

                    if(length<minlength){

                        minlength=length;
                        ans=substring;
                    }             
                }
            }
        }
        
         return ans;
    }
};

//LEETCODE HARD..

//OPTIMAL...
//2 pointer sliding window...

//smjne walaa///hashmap lia..phle t ke charcters ka count++ krdia...

//fir window chlayi s string me..agar charcter ka map phle se hai..to count bda do ..wrna rhne do..
//aur jaise jaise character aate jare unka count decrement krte rho , mtlb pta chlte rhe wo hote jare hai..

//fir jaise hi count , t length ki string jitna hoga..to mtlb window milgyi , ye possibe window hai ptani min hai ya ni...
//agar min hai to update kro minlength , startindex note krlena taki .substr nikalpaye baad me

//ab window shrink krni hai...
//dubara count bada do hashmap mee(undo krdia na)..
//l++ krdo..(aur agar uska freq dubara >0 hogya to count bhi -- krdo )

//bas khtm strtindex se minlength me .substr lagado nikalgyi min window substring...



// Outer Loop (Right Pointer Expansion):

// Iterate through the input string s using the right pointer r.
// For each character at index r:
// Increment the count of the current character in the hash map.
// If the current character is in the target string t and its count becomes equal to the desired count, increment a counter count.
// If count becomes equal to the length of the target string t, it indicates a valid window.
// Update the minimum window length and starting index if necessary.
// Inner Loop (Left Pointer Contraction):

// While the left pointer l is less than the right pointer r and the current window is still valid:
// If the character at index l is in the target string t and its count is greater than 1, decrement its count in the hash map and decrement the count counter.
// If the character at index l is not in the target string t or its count becomes 0, it means the window is no longer valid.
// Update the minimum window length and starting index if necessary.
// Increment the left pointer l.
// Continue Expansion and Contraction:

// Repeat steps 1 and 2 until the right pointer reaches the end of the input string s.
// Final Result:

// The smallest window containing all characters of the target string t is the one with the minimum length found during the process.

class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        int hash[256] = {0};

        for (int i = 0; i < n; i++) {
            hash[t[i]]++;
        }

        int startindex = -1;
        int count = 0;
        int minlength = INT_MAX;

        int l = 0; 
        int r = 0; 

        while (r < m) {
            
            if (hash[s[r]] > 0) {   //valid character hai..
                count++;
            }
            hash[s[r]]--;   

            // Contract the window when we have a valid window
            while (count == n) {

                if (r - l + 1 < minlength) {
                    minlength = r - l + 1;
                    startindex = l;
                }

                // Move the left pointer to shrink the window

                hash[s[l]]++;

                if (hash[s[l]] > 0) {
                    count--;
                }

                l++;
            }
            r++;
        }

        return startindex == -1 ? "" : s.substr(startindex, minlength);
        
    }
};