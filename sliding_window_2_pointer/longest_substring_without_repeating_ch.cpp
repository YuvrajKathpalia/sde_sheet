//brute force..
//approach1..


//o(n^2)..
//o(1)..

//har substring generate krke dekho.
//set me store krte jao..aur length,maxlength variable bnalena...

//agar phle se hai setme to whi break krjao kyuki substring ekdum continuous hoti ,subsequenceki tarah ni


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxLength = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {

            unordered_set<char> seen; 

            for (int j = i; j < n; ++j) {
                if (seen.find(s[j]) != seen.end()) {
                    break;
                }

                seen.insert(s[j]);

                maxLength = max(maxLength, j-i+1); 
            }
        }

        return maxLength;
        
    }
};



//approach2...

//2 pointer and sw(jab bhi substring ka quesn ayega 2 pointer sw sochna phle)

//left,right dono ko 0 perkhenge..
//jaise jaise ch ate jayge .. ek hash array maintain krenge usme dalte jayge(character,aur index bhi uska).


//agar repeting chracter ayaa..mtlb uska index phle se store..to check krenge
// jo uska previous stored index hai wo l se aage hai naa , mtlb ussi window me dubara aya hai kya r..
//agar aya hai to mtlb haa repeating character hai...left ko aage lejao..jo pichla stored charcter tha usse ek aage lejao..
//mtlb wo window se ek step aage badjao..

//o(n)..
//o(256)..0(1)


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.length();
        
       int hash[256];    //pta tha ki values yhi hngi ch ki(given tha string me alphbaets ,symbols,digits wgera..ye sab milake 0-255 ascii values hoti)..isliye hash array hi lelia ase jo position store krega 
     
     for (int i = 0; i < 256; ++i) {
    hash[i] = -1;
     }


        int l=0;
        int r=0;

        int maxi =0;
        int length=0;


        while(r<n){

            if(hash[s[r]]!=-1){  //repeating character..

             if(hash[s[r]] >=l){ //agar same window hai..

             l = hash[s[r]] +1;   //l ko last stored index se ek age lejo update window..
             }

         }

            hash[s[r]]=r;  //store krlo..character ka index..
            

            length = r-l+1;  //length update...

            maxi=max(maxi,length);

          
            r++;


        }

        return maxi;
    }

};