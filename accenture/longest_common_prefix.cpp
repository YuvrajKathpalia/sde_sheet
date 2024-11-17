
https://leetcode.com/problems/longest-common-prefix/


//o(n.mlogn) ... sorting vector of strings...
//o(m)... (size of ans string)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {


    int n=strs.size();

    
    sort(strs.begin(),strs.end());

    string first = strs[0];
    string last  = strs[n-1];

    string ans="";


    for(int i=0; i<min(first.size() ,last.size()); i++){

        if(first[i]!=last[i]){
            break;
        }

        ans +=first[i];
    }


      return ans;
        
    }
};



//usse better..nested loops..
//o(m*n)..

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0 || strs[0].empty()) return ""; // Handle empty input or empty first string

        string ans = "";

        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            // Check if character at index `i` is the same across all strings
            for (int j = 1; j < n; j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;  // Return `ans` immediately if mismatch found
                }
            }
            
            // Add character to `ans` if it's common in all strings
            ans += ch;
        }

        return ans;
    }
};