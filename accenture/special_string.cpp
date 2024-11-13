#include <iostream>
#include <string>
using namespace std;

bool isSpecial(const string& s) {
    int n = s.length();
    if (n < 2) return false; // A special string must have at least 2 characters.

    for (int i = 1; i < n; i++) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i);

        // Check if s1 contains only 'b'
        bool s1IsAllB = true;
        for (char c : s1) {
            if (c != 'b') {
                s1IsAllB = false;
                break;
            }
        }

        // If s1 is all 'b' and s2 is non-empty, it's special.
        if (s1IsAllB && !s2.empty()) {
            return true;
        }
    }

    return false; // If no valid split found, it's not special.
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    if (isSpecial(input)) {
        cout << "The string is special." << endl;
    } else {
        cout << "The string is not special." << endl;
    }

    return 0;
}