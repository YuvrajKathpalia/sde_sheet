#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isPermutation(string str1, string str2) {
    // If lengths are different, they cannot be permutations
    if (str1.length() != str2.length()) return false;
    
    // Sort both strings and compare
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    return str1 == str2;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    
    if (isPermutation(str1, str2)) {
        cout << "Yes, the strings are permutations of each other." << endl;
    } else {
        cout << "No, the strings are not permutations of each other." << endl;
    }
    
    return 0;
}
