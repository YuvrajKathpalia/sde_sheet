

//brute..o(n^3)..

class Solution {
public:

bool isPalindrome(string s, int i , int j){

    int start=i;
    int end=j;

    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

    int countSubstrings(string s) {

        int n=s.size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                if(isPalindrome(s,i,j)){
                    ans++;
                }
            }
        }

        return ans;
        
    }
};



//better....recursive...

// The algorithm counts palindromic substrings by expanding around each character as a center. It checks both odd-length and even-length palindromes, recursively exploring matching characters to the left and right until mismatches or bounds are encountered.

//o(n^2)..
//o(n)..


class Solution {
public:

int countpalindrome(string s, int left,int right){

    if(left<0 || right>=s.length() || s[left]!=s[right]){
        return 0;
    }
    return 1+countpalindrome(s,left-1,right+1);  //expand bahr ki trf
}


    int countSubstrings(string s) {


        int n=s.size();
        int count=0;

        for(int i=0;i<n;i++){  //sare possible combination dekhne..even length ke bhi , odd length ke bhi..

            count += countpalindrome(s,i,i);  //odd length..centered at i..

            count +=countpalindrome(s,i,i+1);  //even length..centered at i,i+1


        }

     return count;
     
    }
};



//optimsing sc..

//o(n^2)..
//o(1)..


class Solution {
public:

int countpalindrome(string s, int left,int right){

    int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {

            left--;
            right++;
            count++;
        }
        return count;
}


    int countSubstrings(string s) {


        int n=s.size();
        int count=0;

        for(int i=0;i<n;i++){  //sare possible combination dekhne..even length ke bhi , odd length ke bhi..

            count += countpalindrome(s,i,i);  //odd length..centered at i..

            count +=countpalindrome(s,i,i+1);  //even length..centered at i,i+1


        }

     return count;
     
    }
};