#include <iostream>
using namespace std;


void countVowelsAndConsonants(string s) {
    int vowels = 0, consonants = 0;

    for (char c : s) {
        // Convert character to lowercase manually
        c = (c >= 'A' && c <= 'Z') ? c + 32 : c;  // Convert uppercase to lowercase

        // Check if the character is a letter and count vowels or consonants
        if ((c >= 'a' && c <= 'z')) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    // Output the result
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);  // Read the entire line, including spaces

    countVowelsAndConsonants(s);

    return 0;
}
