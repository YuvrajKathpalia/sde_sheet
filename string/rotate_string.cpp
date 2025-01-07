
#include <iostream>
#include <string>
using namespace std;

string rotateString(string s, int k) {
    int n = s.length();
    
    // Handle edge cases where string length is 0 or 1
    if (n == 0 || n == 1 || k == 0) {
        return s;
    }

    // Compute the effective rotation count
    k = k % n;
    
    // Split the string into two parts and rotate
    string part1 = s.substr(n - k);  // Last 'k' characters
    string part2 = s.substr(0, n - k);  // The rest of the string

    // Concatenate the parts and return the result
    return part1 + part2;
}

int main() {
    string s;
    int k;
    
    cout << "Enter the string: ";
    cin >> s;
    
    cout << "Enter the number of rotations: ";
    cin >> k;
    
    string result = rotateString(s, k);
    
    cout << "Rotated string: " << result << endl;
    
    return 0;
}



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