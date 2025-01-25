
https://leetcode.com/problems/longest-valid-parentheses/

//stack..
//o(N)..o(N)..



//phle se -1 push krke rakhenge..kyuki jab ( ye aye (index let say=0)..aur fir ) ayee..tab 0 pop kro..
//to maxlen update krni pegi na..isliye shuru se stack me -1 daldo , jo invalid match ki boundary manage krega..
//to maxlen = max9maxlen, 1-(-1)==2 ajegi tabhi to...

//aur agar st empty hogya pop krne se matlb jo ) aya wo mismatch hai naya...



// the stack helps match parentheses and track the boundaries of valid substrings.
// Calculating the length of valid parentheses uses the difference between the current index i and the top of the stack after popping.
// Pushing unmatched indices ensures proper calculation for future substrings.

class Solution {
public:
    int longestValidParentheses(string s) {


        int n=s.size();

        stack<int>st;

        st.push(-1);

        int maxlen =0;

        for(int i=0;i<n;i++){

            char ch=s[i];

            if(ch=='('){
                st.push(i);
            }

            else{

                st.pop();

                if(!st.empty()){

                    maxlen = max(maxlen , i-st.top());
                }

                else{

                    st.push(i);
                }
            }
        }

        return maxlen;
        
    }
};