//o(n)..
//o(1)..
//very famous..vimp quesn..

//iterative whileloop...
//very doable..

// In C++:

// - **`int`** typically has a size of 4 bytes (32 bits), with a range of `-2,147,483,648` to `2,147,483,647`.
// - **`long`** also usually has 4 bytes (32 bits) on most systems but can be 8 bytes on others.
// - **`long long`** is at least 8 bytes (64 bits), with a much larger range.


class Solution {
public:
    int myAtoi(string s) {

        int n=s.length();
        int i=0;

        long long ans=0; //int ni smbhal paraaa..

        int sign=1;

        while(i<n && s[i]==' '){
            i++;
        }

        if(s[i]== '-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){  //if ni lgayge agar dono agye to kuchni krenge..0 return
            i++;
        }


        while(i<s.length()){

            if(s[i]>='0' && s[i] <='9'){

                ans = ans*10 + (s[i]-'0');  //phle 0*10+4=4...fir 4*10+2=42...
                
                if(ans>INT_MAX && sign==1){   //iske bina nii(agar ans*10 krke limit se bahr hoga to.)
                    return INT_MAX;
                }
                if(ans>INT_MAX && sign==-1){
                    return INT_MIN;
                }
                i++;
            }

            else{  //0-9ke beech ni hai..whi return krdo ans jo bnrkha abhi tkkk
                
                return ans*sign;  //retun break; bhi chljata...
            }
        }


        return ans*sign;



        
    }
};