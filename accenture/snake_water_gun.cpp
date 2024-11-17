
#include <bits/stdc++.h>
using namespace std;


char winner(string moveA, string moveB) {
    if ((moveA == "gun" && moveB == "snake") ||
        (moveA == "water" && moveB == "gun") ||
        (moveA == "snake" && moveB == "water")) {
        return 'A';
    } else if ((moveB == "gun" && moveA == "snake") ||
               (moveB == "water" && moveA == "gun") ||
               (moveB == "snake" && moveA == "water")) {
        return 'B';
    }
    return 'D';  // invalid..or incase of same input..(waterwater)..
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int awin = 0;
    int index = 0;

    while(index<s.size()) {
        
        
        string moveA = "";
        if (s.substr(index, 5) == "snake" || s.substr(index, 5) == "water") {
            moveA = s.substr(index, 5);
            index += 5;
        } else {
            moveA = s.substr(index, 3);
            index += 3;
        }


        string moveB = "";
        if (s.substr(index, 5) == "snake" || s.substr(index, 5) == "water") {
            moveB = s.substr(index, 5);
            index += 5;
        } else {
            moveB = s.substr(index, 3);
            index += 3;
        }


        if (winner(moveA, moveB) == 'A') {
            awin++;
        }
    }

    cout << awin << endl;

    return 0;
}