#include <iostream>
#include <string>
using namespace std;

string rotateString(string s, int k) {
    int n = s.length();
    
    // Handle edge cases where string length is 0 or 1
    if (n == 0 || n == 1 || k == 0) {
        return s;
    }

    // Compute the effective rotation count
    k = k % n;
    
    // Split the string into two parts and rotate
    string part1 = s.substr(n - k);  // Last 'k' characters
    string part2 = s.substr(0, n - k);  // The rest of the string

    // Concatenate the parts and return the result
    return part1 + part2;
}

int main() {
    string s;
    int k;
    
    cout << "Enter the string: ";
    cin >> s;
    
    cout << "Enter the number of rotations: ";
    cin >> k;
    
    string result = rotateString(s, k);
    
    cout << "Rotated string: " << result << endl;
    
    return 0;
}
