#include <bits/stdc++.h>
using namespace std;

int countSpaces(const string& str) {
    int spaceCount = 0;
    for (char ch : str) {
        if (ch == ' ') {
            spaceCount++;
        }
    }
    return spaceCount;
}

void compareSpaces(const string& str1, const string& str2) {
    int spaces1 = countSpaces(str1);
    int spaces2 = countSpaces(str2);

    int difference = abs(spaces1 - spaces2);  // Absolute difference
    string parity = (difference % 2 == 0) ? "even" : "odd";

    cout << "Difference in number of spaces: " << difference << endl;
    cout << "The difference is " << parity << "." << endl;
}

int main() {
    string str1, str2;
    
    cout << "Enter first string: ";
    getline(cin, str1);
    
    cout << "Enter second string: ";
    getline(cin, str2);

    compareSpaces(str1, str2);

    return 0;
}
