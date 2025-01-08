
https://www.geeksforgeeks.org/problems/longest-common-substring1452/1?page=2&category=Strings&sprint=a663236c31453b969852f9ea22507634&sortBy=difficulty


//ye longest common substring h...PHLE SUBSEQUNCE PDRE THE..lcs ME..
//WHI SAME TABULATION SE BHARTE...SAME MILGYA TO WHI FUNDA...AGAR DIFFERNT CHARACTER HAI TAB TO 0 HI USKA...
//we know SUBSTTRING SATH ME HONI CHAYIE LGATAR...LIKE ABDCE...DC IS SUBSTRING..DE IS SUBSEQUNCE AND NOT SUBSTRING...

//AUR ANSWER dp[n][m] pe ni hoga...beech me khi bhi askta jha same mile..to ek variable maintain krlena max ke liye...



//NOTE...ISKO EASILY SOCH BHI TABULATION(BOTTOM UP)(FILL KR KRKE)(ITERATIVE APPROACH) SE HI PAOGE ARAAM SE...
//ABCD, ABZD...SHURU SE DEKHO ..A -A MATCH COUNT+1.. DONO KO AGE BDAO..B-B MATCH AUR USSE PICHLA BHI MATCHED THA..
//ISLIYE 1+1=2...DONO KO AGE BDAO..C-Z NO..DONO KOAGE BDAO..D-D MATCH USSE PICHLAA MATCHED NI THAA..TO ASLI ANS ME NI COUNT HOGA YE

// TO YE TABULATION SE KRLETE HAI NA...2D DP FILL KRTE HAII MTLB...SATISFIED CONDITION ME 1+PICHLE WALA KA ANS(MTLN DPP[INDEX1-1][INDEX2-1])...
//AUR YE NOT EQUAL WALE ME 0 BHRDENGEE...AUR MAX WALARETURN KRENGE KHI BHI BEECH ME HOSKTA....
//ITERAATIVE APPROACHE HOGYI...ISSE SPACE PTIMISE KRDO BAD ME CHAHO TUM


// Create a table to store 
    // lengths of longest
    // common suffixes of substrings.   
    // Note that dp[i][j] contains 
    // length of longest common suffix 
    // of X[0..i-1] and Y[0..j-1].
 //ASE HI SMJHANA INTERVIEWER KO



//o(m*n)..
//o(m*n)

class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        
        
        int m=s1.size();
        int n=s2.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        //(base case tha..index1==0 ||index2==0..return 0..)
        //to  2 for loop lgadena..ek baar index1=0,index2 ki sari values 0 , and vice
        //versa , but dikhane ki joroat ni as phle se dp table ki values 0 h
        
        int ans=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                if(s1[i-1]==s2[j-1]){
                    
                    dp[i][j] = 1 +dp[i-1][j-1];
                    
                     ans= max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]= 0 ;  //lc subsequence hota to ..dp[i][j] = 1+max(dp[i][j-1) , dp[i-1][j]
                }
                
                //lc subsequence hota to return dp[m][n] krdete last me
                //but idhar ni... ans update krna pdega sath sath hi kra..if wale case me
                //kyuki lcs me to koi bhi subsequence chlta..to umse to ans last me hi aata 
                //sbse bada...
              
            }
        }
        
        return ans;
      
    }
};