https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?page=1&company=Accenture&sortBy=submissions

//brute force...

//ex... m=9 , n=2..ans =3...
//to hum kya krte ek bahar loop chlate 1 se m , 
//aur andar 0 se n...mtlb n times power nikalege 1 se m sbhi number ki...khi to..3^2=9..ajega..


//o(n^2)..
//o(1)..


class Solution {
public:
    int NthRoot(int n, int m) {
        
        
        
        for (int i = 1; i <= m; ++i) {
            
            long long power = 1;
            
            for (int j = 0; j < n; ++j) {
                
                power *= i;
                
                if (power > m) {
                    break;
                }
            }
            
            if (power == m) {
                return i;
            }
        }
        return -1; // not found..
    }
};


//optiml..boianry search..
//o(logm)..
//o(1)...

//1 se m ke beech binary search lgadenge...mid calculate krenge..
//mid^n nikalnege har mid ke lie loop lgake...
//fir whi bs wala funda..


class Solution {
public:
    int NthRoot(int n, int m) {
        if (m == 0) {
            return 0;
        }

        int low = 1, high = m;
        
        
        while (low <= high) {
            
            int mid = low + (high - low) / 2;
            
            long long product = 1;
            
            for (int i = 0; i < n; ++i) {
                product *= mid;
                if(product>m){
                    break;
                }
            }

            if (product == m) {
                return mid;
            } else if (product < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // Root not found
    }
};
