
https://leetcode.com/problems/rotate-string/

//acha famous..



//goal ko double krdo..
//fir loop lgao goal me...aur i se leke n size tak ki substr nikalte jao..khi bhi jaake substr==s hui to true...warna false;


class Solution {
public:
    bool rotateString(string &s, string &goal) {


        int n = s.size();

        if(s.size()!=goal.size()){
          return false;
        } 

        goal+=goal;

        for(int i=0; i<n; i++){

            if(goal.substr(i, n)==s){  //o(n)..
                return true;
             }

        }

        return false;
    }
};