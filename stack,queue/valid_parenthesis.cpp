
//o(n)
//o(n)


//easy doable..khud...
//stack<char>lo..
//loop lgao.. agar open brakcet to push..
//fir else case...agar close are(aur st empty ni hai).. to usme
//ek aur if else lgado agar ) aya hai to st.top()==( ye hona chie 
//vice versa ,,,else return false obvio...

//agar st empty haoi phle se tb bhi false(closing to opening ke baad hi ayga)

//last me st empty hai to true ,,warna false..




class Solution {
public:
    bool isValid(string s) {

        stack<char>st;

        int n=s.length();

        for(int i=0;i<n;i++){

            char ch=s[i];

            if(ch=='('|| ch=='{'|| ch=='['){

                st.push(ch);
            }

            else{


                if(!st.empty()){

                 if( (ch==')'&& st.top()=='(') ||
                    (ch==']'&& st.top()=='[') ||
                    (ch=='}'&& st.top()=='{') ){

                        st.pop();
                    }

                    else{

                        return false;
                    }
            }
            else{
                return false;
            }
           
            }
        }
        
        return st.empty();
    }
};