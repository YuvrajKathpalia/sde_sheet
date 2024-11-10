https://leetcode.com/problems/reverse-integer/description/

//o(log10(x))  ...jitni digits utni baar loop chlega...
//o(1)...


class Solution {
public:
    int reverse(int x) {

        int ans=0;

        while(x!=0){

            if(ans >INT_MAX/10 || ans <INT_MIN/10){  //out of constrint agar hora hoga to 0 ..derkha quesn me..
                return 0;
            }

            int digit = x%10;

            ans = ans*10 + digit;
            x=x/10;
        }

        return ans;
        
    }
};