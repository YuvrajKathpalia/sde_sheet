//DP ON STRINGS START FROM HERE..
//LENGTH OF LCS OF2 STRINGS S1,S2..ex..acd, ced...length of lcs..2 (which would be cd)...


//LENGTH OF LCS..
//approach1..
//RECURRSION...
//o(2^m* 2^n)...o(n)..


//(BRUTE FORCE SOLUTION BHI HAI SBSE NEECHE...).

class Solution {
public:


int f(int index1, int index2, string s1, string s2 ){

    if(index1<0 || index2<0){
        return 0;
    }
    if(s1[index1]==s2[index2]){
        return 1+ f(index1-1 , index2-1 , s1, s2);
    }
    else{
    return max(f(index1-1,index2,s1,s2), f(index1, index2-1,s1,s2));
    }
}
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();

        return f(m-1,n-1,text1 , text2);
        
    }
};

//approach2..
//MEMOIZATION...
//o(M*N))...
//o(M+N)+O(M*N)....sily

class Solution {
public:


int f(int index1, int index2, string s1, string s2 , vector<vector<int>>&dp ){

    if(index1<0 || index2<0){
        return 0;
    }
    if (dp[index1][index2] != -1)
        return dp[index1][index2];


    if(s1[index1]==s2[index2]){
        return dp[index1][index2] = 1+ f(index1-1 , index2-1 , s1, s2,dp);
    }
    return dp[index1][index2]=  max(f(index1-1,index2,s1,s2, dp), f(index1, index2-1,s1,s2 ,dp));
}
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return f(m-1,n-1,text1 ,text2, dp);
        
    }
};

//ya fir ase indexing theek krdo..m+1,n+1 ki dp hi leli..
//mtlb phle 0 se m-1 , aur 0 se n-1 tak cover krre the
//ab 1 se m , aue 0 se n kr re hai...


//aur base case bhi equal to zero hogya
//aur if cindtion me index check -1 krke krlia...


// class Solution {
// public:


// int f(int index1, int index2, string s1, string s2 , vector<vector<int>>&dp ){

//     if(index1==0 ||  index2==0){
//         return 0;
//     }
//     if (dp[index1][index2] != -1)
//         return dp[index1][index2];


//     if(s1[index1-1]==s2[index2-1]){
//         return dp[index1][index2] = 1+ f(index1-1 , index2-1 , s1, s2,dp);
//     }
//     return dp[index1][index2]=  max(f(index1-1,index2,s1,s2, dp), f(index1, index2-1,s1,s2 ,dp));
// }
//     int longestCommonSubsequence(string text1, string text2) {

//         int m = text1.length();
//         int n = text2.length();

//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

//         return f(m,n,text1 ,text2, dp);
        
//     }
// };

//approach3..
//tabulationTION...
//o(M*N))...O(M*N)..


class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//BASE CASE DP FILL...
//wse to dp[-1] wale zero krne the...but -ve thodi bhrskte array me..
//isliye ekek position right shift..-1 0 hogya..0 1 hogya...n-1 n hogya..dp array bhi isliye n+1,m+1 ki li
//dp[0] wale me 0 bhrdenge..

        for(int j=0;j<=m;j++){
            dp[0][j]= 0;
        }
        for(int i=0;i<=n;i++){         //asal me to ye index1||index2<0 checkk rrena
            dp[i][0]= 0;
        }
////asal me ye krne ki joorat thi ni..set to zero hi krre na..initallydp ke elements 0 hi to the

        for(int index1 =1; index1<=n; index1++){
            for(int index2=1; index2<=m; index2++){

                if(s1[index1-1]==s2[index2-1]){          //obviosuly.. asal me to 0 se n-1 krna tha..loop 1 sen aur 1 se m chlra to aselikhna pda
                    dp[index1][index2] = 1 +dp[index1-1][index2-1];
                }
                else{
                    dp[index1][index2] = 0 + max(dp[index1-1][index2], dp[index1][index2-1]);
                }
            }
        }

        return dp[n][m]; //obvio..n+1,m+1 size ki thi na.. jo 2d dp bnegi n+1,m+1 ki..agr 5 lentgh ki h dono..to 0 se 5 rowsaur 0 se 5 columns....ase hi batenge na(LCS ME PDA THA USSE HI YAD KRLO)...
                         //answer LCS TO last wale element PE BAITHJATA THA NA...mtlb...dp[n][m]
    }
};

//approach4..
//SPACE OPTIMIZATION...
//o(M*N))...O(M)..

class Solution {
public:


    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);

        for(int j=0;j<=m;j++){
            prev[j]=0;
        }

        // for(int j=0;j<=m;j++){
        //     dp[0][j]= 0;
        // }
        // for(int i=0;i<=n;i++){
        //     dp[i][0]= 0;
        // }

        for(int index1 =1; index1<=n; index1++){
            for(int index2=1; index2<=m; index2++){

                if(s1[index1-1]==s2[index2-1]){
                    curr[index2] = 1 +prev[index2-1];
                }
                else{
                    curr[index2] = 0 + max(prev[index2], curr[index2-1]);
                }
            }
            prev =curr;
        }

        return curr[m]; 
        
    }
};




//BRUTE FORCE APPROACH....
//(s1,s2 dono ke sare subsequence nikaldie(include/exclude,backtrack)aur store kralie vector<string>me...
//fir nested loop lgake common subsequence nikala max lengthwala

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to generate all subsequences of a string
void generateSubsequences(const string& str, int index, string& subsequence, vector<string>& subsequences) {
    if (index == str.length()) {
        subsequences.push_back(subsequence);
        return;
    }

    // Exclude current character
    generateSubsequences(str, index + 1, subsequence, subsequences);

    // Include current character
    subsequence.push_back(str[index]);
    generateSubsequences(str, index + 1, subsequence, subsequences);

    // Backtrack
    subsequence.pop_back();
}

// Function to find the length of the longest common subsequence
int longestCommonSubsequenceLength(const string& str1, const string& str2) {
    vector<string> subsequences1, subsequences2;
    string subsequence;

    // Generate all subsequences for both strings
    generateSubsequences(str1, 0, subsequence, subsequences1);
    generateSubsequences(str2, 0, subsequence, subsequences2);

    int maxLength = 0;

    // Compare all subsequences to find the longest common subsequence
    for (const string& subseq1 : subsequences1) {
        for (const string& subseq2 : subsequences2) {
            if (subseq1 == subseq2) {
                int length = subseq1.length();
                maxLength = max(maxLength, length);
            }
        }
    }

    return maxLength;
}

int main() {
    string str1 = "ABCD";
    string str2 = "ACD";
    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequenceLength(str1, str2) << endl;
    return 0;
}


