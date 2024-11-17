#include <iostream>
#include <string>
using namespace std;

int countCharacterOccurrences(const string &str, char ch) {
    int count = 0;
    // Traverse through the string and count occurrences of the character
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    string input1;
    char input2;
    
    // Taking input from the user
    cout << "Enter the string: ";
    cin >> input1;
    cout << "Enter the character: ";
    cin >> input2;

    // Call the function to count occurrences and print the result
    int result = countCharacterOccurrences(input1, input2);
    cout << "The character '" << input2 << "' appears " << result << " times in the string." << endl;

    return 0;
}
