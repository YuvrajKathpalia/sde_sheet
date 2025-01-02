https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02


// Example 1:

// Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
// Output: [2,3,0]
// Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
// The answer to the query [0,2] is 2 (strings "aba" and "ece").
// to query [1,4] is 3 (strings "ece", "aa", "e").
// to query [1,1] is 0.
// We return [2,3,0].

// The approach calculates prefix sums for words starting and ending with vowels.
//  A helper function checks vowel validity. 
//  For each query, it computes the difference in prefix sums to count vowel-based strings
//   within the specified range efficiently.


class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {


        vector<int> prefix;

        int count = 0;


//prefix array...for coutning number of strings with starting ,and endding with a vowel...


        for (auto& word : words) { 

            if (isVowel(word[0]) && isVowel(word.back())) {
                count++;
            }
            prefix.push_back(count);
        }

        vector<int>res;

        for (auto query : queries) {

            int l = query[0], r = query[1];

            if (l == 0) {                    
                res.push_back(prefix[r]);     //obvio..
            } else {
                res.push_back(prefix[r] - prefix[l - 1]);   //obvio..dry run se sochlo..
            }
        }

        return res;
    }
};
