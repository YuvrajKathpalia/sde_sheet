https://www.geeksforgeeks.org/problems/minimum-sum4058/1


//acha...
// Input: arr[] = [6, 8, 4, 5, 2, 3]
// Output: 604
// Explanation: The minimum sum is formed by numbers 358 and 246.

// min sum banana 2 numbers see array se...(string me return krna aur)
// to kya phle sort krenge...2,3,4,5,6,8
// 2 string lelenge 
// ek string me even index wale dedenge,ek me odd wale dedenge... taki dono me jitne kum aske ajae
// greedy ek treeke se

// to fir bas to adddition wala khel khelna , array string digits me...hojega..

//o(nlogn)+o(max(l1,l2))==o(nlogn)...
//o(n)...


class Solution {
  public:
    
    string minSum(vector<int> &arr) {
    
    sort(arr.begin(), arr.end());

    string num1 = "", num2 = "";


    for (int i = 0; i < arr.size(); i += 2) {
        num1 += to_string(arr[i]);  // Append digits to num1
    }
    for (int i = 1; i < arr.size(); i += 2) {
        num2 += to_string(arr[i]);  // Append digits to num2
    }

    // Reverse num1 and num2 to simplify addition of digits 
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string res="";
    int carry = 0;    

    int i = 0, j = 0; 

    while (i < num1.size() || j < num2.size()) {
        int sum = (i < num1.size() ? num1[i] - '0' : 0) +  // Get digit from num1 or 0
                  (j < num2.size() ? num2[j] - '0' : 0) +  // Get digit from num2 or 0
                  carry;                                   // Add carry
                  
                  
        carry = sum / 10;  //update carry
        sum = sum % 10;    // Store the last digit of sum
        
        res += sum + '0';  // Append the digit to the result string...

        
        if (i < num1.size()) i++;
        if (j < num2.size()) j++;
    }

    // Remove any trailing zeros (to avoid incorrect leading zeros)
    
    while (!res.empty() && res.back() == '0') res.pop_back();
    
    
    // If there's a carry left, add to result string
    
    if (carry) {
        res += to_string(carry);
    }

    // Reverse the result to get the correct number
    reverse(res.begin(), res.end());

    

    return res;  // Return the result as a string
}


};