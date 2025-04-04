
//An anagram is a word or phrase formed by rearranging the letters 
//of a different word or phrase, using all the original letters exactly once.

//approach1..
//nlogn..
//o(1)..


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//apporach2..
//o(n)..
//o(1).

class Solution {
public:
    bool isAnagram(string s, string t) {


        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a'] += 1;
        }

        for (char c : t) {

            count[c - 'a'] -= 1; 
        }

        for(auto x: count){
            if(x!=0){
                return false;
            }
        }   

        return true;    
    }
};


// class Solution {
//     public:
//         bool isAnagram(string s, string t) {
    
//             int m=s.length();
//             int n=t.length();
    
//             if(m!=n){
//                 return false;
//             }
    
//             vector<int>freq(26,0);
    
//             for(int i=0;i<m;i++){
//                 freq[s[i]-'a']++;
//             }
    
//             for(int i=0;i<m;i++){
//                 freq[t[i]-'a']--;
//             }
    
//             for(auto x:freq){
    
//                 if(x!=0){
//                     return false;
//                 }
//             }
//             return true;
//         }
//     };

