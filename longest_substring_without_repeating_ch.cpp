//brute force..
//approach1..


//o(n^2)..
//o(1)..

//har substring generate krke dekho.
//set me store krte jao..aur length,maxlength pointer bnalena...

//agar phle se hai setme to whi break krjao kyuki substring ekdum continuous hoti ,subsequenceki tarah ni


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxLength = 0;
        int n = s.length();

        // Iterate over all possible starting points
        for (int i = 0; i < n; ++i) {
            unordered_set<char> seen; // Set to track characters in the current substring
            int length = 0;

            // Iterate over all possible ending points for the current start point
            for (int j = i; j < n; ++j) {
                if (seen.find(s[j]) != seen.end()) {
                    // If we find a repeating character, break
                    break;
                }

                // Add the character to the set and update the length of the current substring
                seen.insert(s[j]);
                length++;
                maxLength = max(maxLength, length); // Update maximum length if necessary
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
        
       int hash[256];    //pta tha ki values yhi hngi ch ki..isliye hahs array hi lelia.
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

            length = r-l+1;  //length update...

            maxi=max(maxi,length);

            hash[s[r]]=r;  //store krlo..character ka index..
            
            r++;


        }

        return maxi;
    }

};