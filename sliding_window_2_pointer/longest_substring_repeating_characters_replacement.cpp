//aisi substribg btani jiske characters atmax k times replace krne pe jo string bnegi wo longest repeating substring bnni chie..

//ex..ABAB ,K=2... to 2 bar a ko b kro ya b ko a== AAAA..length =4..return 4...
//ex..AABABBA... k=1... EK b ko a se replace...AAAABBA..LENGTH=4...

//FUNDA= CHANGES<=K == LENGTH - MAXFREQ (KISI BHI CH KI) <=K


//APPROACH1..brute..nested...
//har substring jo bnski uske lie check kro.....

//outer loop 0 se n....//ek hash array lelo jisme freq store kroge(26 size ka lelo as sirf capital letters h string me its given)
//andar ka loop..i se n..


//hash array me count++ kro character karte jo ch ka , maxfreq maintain krte rhnaa...
//agar length of subtring - maxfreq<=k hai... TO MAXLENGTH UPDATE KRDO..
//AGAR >=K HOGYI HAI TAB TO BREAK KRJO DOOSRI STRING KE IE CHECK KRO....

//O(N^2)..
//O(26)=O(1)...


//OPTIMAL..SW..2 POINTER...USME BHI YHI R KE SATH KHELTE JAO... WINDOW FAIL CONDITION LGADENA..L++ KRTE RHENA...
//AGAR CHANGES<=K ARE TO MAXLENGTH MAINTAIN KRTE RHNA..


class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.length();

        
        int maxlength=0;

        for(int i=0;i<n;i++){

            int hash[26]={0}; //ek array lelenge jisme freq store krte rhgee har charcter ki..
            int maxfreq=0;


            for(int j=i;j<n;j++){

                hash[s[j]-'A']++;

                
                maxfreq= max(maxfreq,hash[s[j]-'A']);

                int length = j-i+1;


                if(length-maxfreq<=k){

                    maxlength = max(maxlength ,length);
                }

                else{

                    break;
                }
            }


        }

        return maxlength;
        
    }
};


//optimal...

//2 pointer slidiwing window....same approach main condition whi hai length-maxfreq us point tak should be <=k to hi valid..


//O(N+N)...NOT O(N^2)... The algorithm uses a sliding window approach, processing each character
// at most twice(JADA SE JADA)
//EK BAR RIGHT.LEFT DONO POINTER SE USSE JADAA NI CHANCES), resulting in a linear time complexity of O(n), avoiding the O(n²) complexity of nested loops...ASA TO HAI NI EK R KE LIE HAR JAGAH L MOVE KRRA VICE VERSA...
//(ISLIE WO ANDAR OUTOF BOUND WALA LOOP WHILE KI JAGAH IF BHI KRSKTE HAI)


class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.length();

        int l=0;
        int r=0;

        int maxlength=0;
        int maxfreq=0;

        int hash[26]={0};


        while(r<n){

            hash[s[r]-'A']++;

            maxfreq=max(maxfreq,hash[s[r]-'A']);

            int length = r-l+1;

            while(length-maxfreq>k){

                hash[s[l]-'A']--;
                l++;
                length--;
            }

            if(length-maxfreq<=k){

                maxlength = max(maxlength , length);
            }

            r++;
        }


        return maxlength;
        
    }
};