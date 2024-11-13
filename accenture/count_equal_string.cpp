
Alice gave you binary string str containing only 0 and 1...
and asked you to count unique subsequcnes which are equal string....
Alice defines equal string as a string which contains equal no of 1 and 0....

print total no of equal string string that can be formed using given binary string

#include <iostream>
#include <unordered_map>
using namespace std;

int countEqualSubsequences(const string &str) {
    unordered_map<int, int> balanceCount;
    int balance = 0;  // Start with balance 0
    int result = 0;
    
    // Initialize balanceCount[0] = 1 to handle the case where we find a valid subsequence starting from index 0
    balanceCount[0] = 1;

    // Traverse through the string
    for (char ch : str) {
        // Update the balance based on the character
        if (ch == '1') {
            balance++;
        } else {
            balance--;
        }
        
        // If the current balance has been seen before, it means there are subsequences from earlier positions
        // that form a valid subsequence with the current balance (equal number of 0's and 1's).
        result += balanceCount[balance];

        // Increment the count of the current balance in the map
        balanceCount[balance]++;
    }
    
    return result;
}

int main() {
    string str;
    cout << "Enter the binary string: ";
    cin >> str;

    int result = countEqualSubsequences(str);
    cout << "Total number of equal subsequences: " << result << endl;

    return 0;
}