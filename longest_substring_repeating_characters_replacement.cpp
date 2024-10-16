//brute force..generate all substrings...

//nested loops..hash array lia freq store krne ke lie....maxfreq maintain krii particular substring length tak...

//fir obviosuly changes that have to be made = total length till that POint - maxfreq( ABAB , maxfreq=2..totalchanges =4-2=2)..2 changes se YA TO AAAA KRDO YA BBBB TAKI LENGTH MAX KRDO...

//AGAR WO CHANGES LESS THAN EQUAL TO K(atmost k) hai to naa to length return krdo(maxlenght bhi maintain krni pdegi)...
//agar k se jada changes lagre tb to break , possible ni us iteration me agli iteration me dekhna..


//o(n^2)..
//o(256)..


class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.length();
        int maxfreq=-1;

        int maxlength=0;

        for(int i=0;i<n;i++){

            int hash[26]={0};
            int changes=0;

            for(int j=i;j<n;j++){

                hash[s[j]-'A']++;

                maxfreq=max(maxfreq,hash[s[j]-'A']);

                changes = j-i+1 - maxfreq; //changes required for making substring of same letters... length-maxfreq...

                if(changes<=k){

                    maxlength = max(maxlength , j-i+1);
                }
                else if(changes>k){  //2 pointer bhi idhar sw is condition me shrink krdete bas yhi differnce hai(aur freq-- left ch ki)
                    break;
                }

            }
        }

        return maxlength;
        
    }
};



//optimal...

//2 pointer slidiwing window....same approach main condition whi hai length-maxfreq us point tak should be <=k to hi valid..


//O(N+N)...NOT O(N^2)... The algorithm uses a sliding window approach, processing each character at most twice(JADA SE JADA
//EK BAR RIGHT.LEFT DONO POINTER SE USSE JADAA NI CHANCES), resulting in a linear time complexity of O(n), avoiding the O(n²) complexity of nested loops...ASA TO HAI NI EK R KE LIE HAR JAGAH L MOVE KRRA VICE VERSA...
//(ISLIE WO ANDAR OUTOF BOUND WALA LOOP WHILE KI JAGAH IF BHI KRSKTE HAI)


class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.size();

        int l=0;
        int r=0;

        int hash[26]= {0}; //unordered map ki jgh yhi use krlia kyuki we know 0 se 25 ke beech hi hai charcter apne whi
                           //isi me freq store krvalenge...

        int maxfreq=0;
        int maxlength=0;

        while(r<n){

            hash[s[r]-'A']++;
            maxfreq = max(maxfreq, hash[s[r]-'A']);

            while((r-l+1) -maxfreq >k){   //window se bahr..shrink kro sw apni..silly(out of bound wali me hmesha while lgate)

                hash[s[l]-'A']--;
                l++;
                //MAXFREQ UPDATE KRNI KI JOORAT NI.. nhi bhi kroge jab tk condition match ni hogi maxlegth update to krni re

            }

            if((r-l+1) - maxfreq <=k){

                maxlength = max(maxlength , r-l+1);
                r++;
            }
        }

        return maxlength;
        
    }
};