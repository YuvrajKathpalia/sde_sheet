
https://leetcode.com/problems/powx-n/submissions/1407269410/

//brute force... n..
//agar sirrf for loop lgate ..to usme negative ower wala case handle ni hota..wo alag se handlekra hai...


class Solution {
public:
    double myPow(double x, int n) {
        
        long long N = n;  // Use long long to avoid overflow for large negative n

        if (N < 0) {
            x = 1 / x;  // Take the reciprocal of x
            N = -N;     // Convert n to positive
        }

        double ans = 1.0;

        for (long long i = 0; i < N; i++) {
            ans = ans * x;
        }
        return ans;
    }
};




//optimal...
//binary exponentation

//nlogn....



class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case when n is INT_MIN
        if (n == INT_MIN) {
            // To avoid overflow, use long long for n
            return (1 / (x * myPow(x, -(n + 1))));
        }
        
        if (n == 0) return 1; 
        if (n < 0) {
            x = 1 / x; 
            n = -n;    
        }
        
        double result = 1.0;
        while (n > 0) {
            
            if (n % 2 == 1) {
                result *= x;
            }
            x *= x;
            n /= 2;
        }
        
        return result;
    }
};
