#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Function to count merry substrings
int countMerrySubstrings(const string& s) {
    int n = s.length();
    int merryCount = 0;

    // Iterate over all substrings
    for (int i = 0; i < n; i++) {
        unordered_set<char> charSet;
        for (int j = i; j < n; j++) {
            if (charSet.find(s[j]) != charSet.end()) {
                // If character is repeated, break
                break;
            }
            charSet.insert(s[j]);
            // If all characters are unique, it's a merry substring
            merryCount++;
        }
    }

    return merryCount;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = countMerrySubstrings(s);
    cout << "Number of merry substrings: " << result << endl;

    return 0;
}
