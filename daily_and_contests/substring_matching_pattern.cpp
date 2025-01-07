
https://leetcode.com/problems/substring-matching-pattern/description/

// You are given a string s and a pattern string p, where p contains exactly one '*' character.

// The '*' in p can be replaced with any sequence of zero or more characters.

// Return true if p can be made a substring of s, and false otherwise.

// A substring is a contiguous non-empty sequence of characters within a string.

 

// Example 1:

// Input: s = "leetcode", p = "ee*e"

// Output: true

// Explanation:

// By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.


class Solution {
public:
    bool hasMatch(string s, string p) {


        int x = p.find('*');

        string b = p.substr(0, x);  //left part 
        string e = p.substr(x + 1); //right part..


        int i = s.find(b);
        int j = s.rfind(e);   //rfind-- last occurence btata..
      
      //ab conditions lgado...i ,j -1 ni hone chiee..
      //aur i+b.size() (jha prefix khtm hora) wo should be less than <=j..


        return i != -1 && j != -1 && i + b.size() <= j;
    }
};