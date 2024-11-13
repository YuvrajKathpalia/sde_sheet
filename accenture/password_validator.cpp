

#include<bits/stdc++.h>
using namespace std;

int passwordValidator(string str) {
    int check_not_satisfied = 0;
    
    // 1. Length check: The password must be between 6 and 22 characters long
    if (str.length() < 6 || str.length() > 22) {
        check_not_satisfied++;
    }
    
    // 2. Uppercase check: It must contain at least one uppercase letter
    bool hasUppercase = false;
    for (char c : str) {
        if (isupper(c)) {
            hasUppercase = true;
            break;
        }
    }
    if (!hasUppercase) {
        check_not_satisfied++;
    }

    // 3. Lowercase check: It must contain at least one lowercase letter
    bool hasLowercase = false;
    for (char c : str) {
        if (islower(c)) {
            hasLowercase = true;
            break;
        }
    }
    if (!hasLowercase) {
        check_not_satisfied++;
    }

    // 4. Special character check (must contain at least two special characters)
    unordered_set<char> specialCharacters = {'6', '@', '!', ',', '%','&'};
    int specialCharCount = 0;
    for (char c : str) {
        if (specialCharacters.find(c) != specialCharacters.end()) {
            specialCharCount++;
        }
    }
    if (specialCharCount < 2) {
        check_not_satisfied++;
    }

    // 5. Numeric check: It must contain at least one numeric character
    bool hasDigit = false;
    for (char c : str) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        check_not_satisfied++;
    }

    // 6. Consecutive identical characters check
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i-1]) {
            check_not_satisfied++;
            break;
        }
    }

    return check_not_satisfied;
}

int main() {
    string str;
    // Read the input string
    cin >> str;
    
    // Call the passwordValidator function
    int result = passwordValidator(str);
    
    // Output the result
    cout << result << endl;

    return 0;
}