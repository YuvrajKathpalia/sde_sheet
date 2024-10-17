https://leetcode.com/problems/valid-parentheses/

//good famous...

//use stack..
//open aaya push krdo..else close aya to check kroo ki ) ye hai to top pe ) pda ya ni 
//and vice versa for other , agar yes to pop krdo..agar top pe ni pda closing to false krdo whi se..

//or phla hi closing ni askta to jab closing ka check krre ho to dekhlena ki st empty to ni hai na..empty hai to false...

//ab ye sab hojane ke baad..stack empty hai to true(mtlb jo opening aye the wo sab katgye apne
//apne relevant closing se)
//AGAR EMPTY NI H TO FALSE..

//O(N)..
//O(N)..

class Solution {
public:
    bool isValid(string s) {

        stack<char>st;

        int n=s.size();

        for(int i=0;i<n;i++){

            char ch=s[i];

            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }

            else{

                if(!st.empty()){
                
                 if(ch==')' && st.top()=='(' ||
                    ch=='}' && st.top()=='{' ||
                    ch==']' && st.top()=='['){
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

        if(st.empty()){
            return true;
        }

        return false;
        
    }
};