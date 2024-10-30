
https://leetcode.com/problems/isomorphic-strings/

//acha..imp..silly..

//use 2 unordered maps..ek se ni hoga..(badc , babe)test case dekho..t me dubara agya b, asa ni sirf ek hi mapping krni
//dono ke lie map bnana pdega..khi se bhi inconsistent maping milgyi to false..

//o(n)..
//o(26)==o(1)..

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (m != n) {
            return false;
        }

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < n; i++) {

            // Check for s to t mapping

            if (mp1.find(s[i]) != mp1.end()) {

                if (mp1[s[i]] != t[i]) {
                    return false; 
                }
            } 
            
            else {
                mp1[s[i]] = t[i]; 
            }

            // Check for t to s mapping
            if (mp2.find(t[i]) != mp2.end()) {
                if (mp2[t[i]] != s[i]) {
                    return false; 
                }
            }
            
             else {
                mp2[t[i]] = s[i]; 
            }
        }

        return true;
    }
};