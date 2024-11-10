
https://leetcode.com/problems/integer-to-roman/description/

//easy..silly...


//jitne diff roman numerls bante the unko string me add krlia..aur unke coresponding ek values array me uski value stori krli
//fir loop lgaya
//jab tak num ki value[i] se bdi ati jari uske coresponding roman+= krte rhe , aur num me se uski value minus...

//o(1).
//o(1)..


class Solution {
public:
    string intToRoman(int num) {


        int values[] ={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]  ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string ans="";

        for(int i=0;i<13;i++){

            while(num>=values[i]){

                ans += roman[i];
                num -= values[i];
            }

        }

        return ans;
        
    }
};