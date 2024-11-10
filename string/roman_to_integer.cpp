https://leetcode.com/problems/roman-to-integer/

//thek...SILLYY
//o(n)..o(n)..

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int>map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

int ans=0;

        for(int i =0; i<s.length(); i++){
            //AGR AGE WALE KI VALUE JDA HAI..
            //LIKE IX..TO ISME...9 ANA CHIE NA..TO HUM -1+10=9KRDETE..IDHAR IF ME MINUS KRLETE
            //FIR JAB X AKELA AYGA TB + KRLENGE 
            if(map[s[i]] < map[s[i+1]]){
                ans=ans- map[s[i]];
            }
            else{
                //normal case JAB SINGLE character h ya age wale ki value kum..to simple add
                //like sirf c aya..ya III aya
                  //like LVII... =57
                ans=ans+ map[s[i]];

            }
        }
return ans;
       
    }
};