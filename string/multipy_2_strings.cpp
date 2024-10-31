
//acha...famous..silly..vimp..doable

// This solution simulates manual multiplication using arrays. Each digit of `num1` is multiplied by each digit of `num2`, with results stored in an array (`ans`) at positions based on digit indices. The array accumulates results and handles carry-over between positions. Finally, the array is converted to a string, ignoring leading zeros, to form the product efficiently.

//o(m*n)..
//o(m+n)...

class Solution {
public:
    string multiply(string num1, string num2) {

        int m=num1.length();
        int n=num2.length();

        vector<int>ans(m+n,0); //at max itni hi length hogi vector ki..

        if(num1=="0" || num2=="0"){
            return "0";
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                int temp = (num1[i]-'0')*(num2[j]-'0');
                int sum =  temp+ ans[i+j+1];             //jo us position pe phle se hoga(carry)(initally 0)+product..ex..3*6=18 agya phle..(agar phle se 1 pda hota to 19 hojata)..

                ans[i+j+1] = sum%10;  //18 ko 8 krdia.., aur carry agle me jod dia..

                ans[i+j] += sum/10;
            }
        }
        
         string result = "";
        bool leadingZero = true;
        
        for (int i = 0; i < ans.size(); i++) {

            if (leadingZero && ans[i] == 0){   //shuru me ate jare 0..next iteratin pe jate rho..jse hi non zero aya boolean=false..
             continue; // 
            }
            leadingZero = false;

            result.push_back(ans[i] + '0'); // Convert to character and add to result string
        }
        
        return result.empty() ? "0" : result;
    }
};