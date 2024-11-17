#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Function to count consonants in the word
int countConsonants(const string& word) {
    int count = 0;
    for (char ch : word) {
        if (ch >= 'a' && ch <= 'z' && !isVowel(ch)) { // Lowercase consonant
            count++;
        } else if (ch >= 'A' && ch <= 'Z' && !isVowel(ch)) { // Uppercase consonant
            count++;
        }
    }
    return count;
}

// Function to calculate factorial of a number
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate permutations of consonants
long long permutationsOfConsonants(const string& word) {
    int consonantCount = countConsonants(word);
    return factorial(consonantCount);
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    long long result = permutationsOfConsonants(word);
    cout << "Total number of permutations of consonants: " << result << endl;

    return 0;
}
