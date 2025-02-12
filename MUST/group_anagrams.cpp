

//brute...
//string aayi , usko har usse comapre kia... aur ek griup bnadenge un string inka agar wo anagram, ek group wali ek jagah hojegi aur ek visited bhi maintain krlenge ase baar baar bhi repeat hoti jaygi warna...


// This brute-force solution groups anagrams by comparing each string with every other string. For each string, it forms a new group, then checks if any remaining strings are anagrams by using the helper function `isAnagram`, which sorts and compares strings. The `visited` array tracks which strings are already part of a group, preventing duplicates. Each group of anagrams is added to the final result. This approach is less efficient due to repeated comparisons.



//o(n^2 * klogk)... (where n is length of vector<vector<string>> and k is size of each string)
//o(n*k)...  


class Solution {
public:

 bool isAnagram(const string& s1, const string& s2) {

        if (s1.size() != s2.size()) return false;

        string sorted_s1 = s1;
        string sorted_s2 = s2;
        
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());

        
        return sorted_s1 == sorted_s2;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        vector<vector<string>> result;
        vector<bool> visited(n, false); // To keep track of already grouped strings


        for (int i = 0; i < n; i++) {

            // Skip if the current string is already part of a group
            if (visited[i]) continue;

            // Create a new group for the current string
            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            // Compare with other strings to find anagrams
            for (int j = i + 1; j < n; j++) {
            
                if (!visited[j] && isAnagram(strs[i], strs[j])) {
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

        
            result.push_back(group);
        }

        return result;
    }
   
};


//optimal...
//map..
//map lia string.vector<string> ka...
//anagram strings ko differnt vector<string>me map krdiaa... 

//fir mapp me loop lgake ko vector<string>ko push back krdia ek ek krke in vector<vector<string>>ans..

//o(n * klogk).....o(N(KLOGK+1))+O(N*K)==O(NKLOGK).
//o(n*k)....STORING ATMOST N KEYS AND EACH KEY HAS K WORDS..+O(N*K) OF RESULT VECTOR ALSO...


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n=strs.size();

        unordered_map<string,vector<string>>mpp;

        for(auto x:strs){

            string word= x; //word store krlia..
            sort(word.begin(),word.end());
            mpp[word].push_back(x);   //sorted word jo bna uski mapping krdi original string sath
        }

        vector<vector<string>>ans;

        for(auto x : mpp){
          
          ans.push_back(x.second);      //where x.second is vector<string>(anagrams)..

        }

        return ans;
        
    }
};
