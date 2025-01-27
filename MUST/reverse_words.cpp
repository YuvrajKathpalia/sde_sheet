
//phle to blank space shuru me sambhal lo..fir left right pointer lgado... while loop lgao..ek temp string bnalena jo words ko dekhega
//aur ek ans string jo sentence ko dekhega..

//jab tk space ni are characters ko temp string me dalte jo...jaise hi space aya.. ans handle krega fir..do case bnege.....phle to bahr if lgao temp khali ni hai na
// fir andar ek if..jab ans string khali shuru me tab to seedha ans=temp..aur temp khali krdo... ya fir else me... ans me hai ek do word phle se to ans = temp + " " + ans..aur temp khali..

//.aur left++ krte rhna...

//last me temp me akhri word rhjega usko loop se bahr handle krna pdega kyuki uske baad space to ayga ni..


//o(n)..
//o(n)..


#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.length();

    string temp = "";
    string ans = "";


    // Trim leading spaces
    int i=0;
    while (s[i] == ' ') {
        left++;
    }

    // Traverse the string
    while (i<n) {

        char ch = s[i];

        if (ch != ' ') {
            temp += ch;
        } 
        
        else {
            if (!temp.empty()) { // Add the word to ans
                if (!ans.empty()) {
                    ans = temp + " " + ans;
                } else {
                    ans = temp;
                }
            }
            temp = ""; // Reset temp for the next word
        }
        left++;
    }

    // Handle the last or single word
    
    if (!temp.empty()) {
        if (!ans.empty()) {
            ans = temp + " " + ans;
        } else {
            ans = temp;
        }
    }

    return ans;
}

int main() {
    string s;
    getline(cin, s); 

    string result = reverseWords(s);
    cout << result << endl;

    return 0;
}
