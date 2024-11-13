#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool canFormPalindrome(string s) {
    unordered_map<char, int> freq;
    
    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }
    
    int oddCount = 0;
    for (auto& entry : freq) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }
    
    // For a palindrome, there can be at most one character with an odd count
    return oddCount <= 1;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    
    if (canFormPalindrome(str)) {
        cout << "Yes, a permutation of the string can form a palindrome." << endl;
    } else {
        cout << "No, a permutation of the string cannot form a palindrome." << endl;
    }
    
    return 0;
}
