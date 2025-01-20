https://leetcode.com/problems/count-and-say/


//acha..famous.

//iterative...


//1 pe kaam krenge..
//phle 1 ka 11 bnega...fir 21...1211...111221..---...nth return krna...

//phle bahar loop chlega 2 se n tak...
//temp string lenge... phla charcter lenge string ka..

//fir loop lgaenge us string me(1/11/21--)...
//phle character se match krenge agar same aya to count++ krdnge , 
//agar same ni aya , mtlb 21 tak 2 ka count to 1 krdia fir jab 1 aya to same to hai ni, islie phle
//2 print krvaynge - 12 , mtlb temp+=to_string(count)+ch, where ch was phla cgacrer of ans(ans[0]...)
//aurr ch ko ab ans[i] se replace krna pdgea kyuki ab 1 ka count calculate krnge na next iteration se(agar bachi h string)...
//asa chlta rhega...

//last me hmare paaas count rha ho skta hai jab repeating characters hoi...ex in case of 11..count=2 agya..
//ab isko likhna... temp+=to_string(count)+ch...

//fir ab ans ko update krna pdega temp se har iteration ke baad...1 -11..to ab 11 pe kaam krenge na obvio...---...


//tc..o(2^n).. in worst case...har iteration me max to max double hori na length...
//sc=o(2^n).....

//but n chota number hi hai constraint ke according to ye chljaygi no issues...



class Solution {
public:
    string countAndSay(int n) {

        string ans="1";  //ispe kaam krenge..
         
         for(int i=2;i<=n;i++){

            string temp="";
            int count=0;

            char ch=ans[0];
           
           for(int i=0;i<ans.size();i++){

            if(ans[i]==ch){  //1 hai jaise sirf...count bdao=1..bahr..../ya 11 hai , count bdao dono ka.count 2 ...bahr
                count++;
            }
            else{
                temp += to_string(count) + ch;  //jaise 11 ke bad 21 aya..2 ka count bdgya..but ab 1 aya !=ch..to phle 2 ko 12 krna pdega na..aur ch ko 1 se update krna pdega next iteration(if any)ke lie
                ch=ans[i];
                count=1;  
            }
           }

           temp += to_string(count) + ch;  //last elemnt ke lie..
           ans=temp;                     //ab jaise 11 pe chlega yhi same loop
         }

         return ans;
        
    }
};