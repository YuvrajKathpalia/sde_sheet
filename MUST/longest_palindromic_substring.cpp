https://leetcode.com/problems/longest-palindromic-substring/description/

//brute...n cube..


class Solution {
public:

bool checkPal(const string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

string longestPalindrome(string& s) {

    int n = s.size();
    int maxLen = 1, start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

        
            if (checkPal(s, i, j)) {

                start = i;
                maxLen = max(maxLen,j-i+1);
            }
        }
    }

    return s.substr(start, maxLen);  //substring return krni na..to start uar maxlength pointer bhi save rkhna hoga phle se..
}
};




///optimal...
//dp...

//n square , n square...


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // Create a DP table
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLength = 1;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for palindromes of length 3 and above...phle three ki check hogi fir four ki ase ase..

        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {  //start index kya hoskta..agar length=l hai..

                int j = i + length - 1;  //us i ke lie finishing index of substring of that length....

                if (s[i] == s[j] && dp[i + 1][j - 1]) {   //phle outer wala check fir andar wala humpe pda hoga phle se..hum solve kr chuke honge use phle se hi..dp hai na..yhi to hota..chota chota hisso me batke solve krte rhte hai..

                    dp[i][j] = true;
                    start = i;
                    maxLength = length;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;
    string s = "babad";
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s) << endl;
    return 0;
}
