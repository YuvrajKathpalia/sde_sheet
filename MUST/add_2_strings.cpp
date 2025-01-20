
//easy..silly..imp.
//impp..

//peeche se shuru add krna..carry=0 let krlena shuru me.
//sum kro..carry update krlena..aur result string me %10 krke push back...

//last me ans reverse krlena...
//agar shuru se start krte to zeroes insert krne pdte phle..jo choti string hoti usme last me..

//o(max(m,n))
//o(max(m,n))..



class Solution {
public:
    string addStrings(string num1, string num2) {

        int m = num1.size();
        int n = num2.size();

        int carry = 0;
        string result = ""; 

        int i = m - 1, j = n - 1;

        

        while (i >= 0 || j >= 0 || carry > 0) {

            int digit1 = (i >= 0) ? (num1[i] - '0') : 0; 
            int digit2 = (j >= 0) ? (num2[j] - '0') : 0; 

            int sum = digit1 + digit2 + carry; 

            carry = sum / 10; 

            result.push_back((sum % 10) + '0'); //add charcter to final string...


            i--;
            j--;
        }

        
        reverse(result.begin(), result.end());

        return result;
    }
};
