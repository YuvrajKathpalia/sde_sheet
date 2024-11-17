
Alice gave you binary string str containing only 0 and 1...
and asked you to count unique subsequcnes which are equal string....
Alice defines equal string as a string which contains equal no of 1 and 0....

print total no of equal string string that can be formed using given binary string

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

long long countEqualZeroOneSubsequences(const string& s) {
    unordered_map<int, int> prefixSumFreq;
    int prefixSum = 0;
    long long count = 0;

    // Initial frequency for prefix sum 0 (to handle equal subsequences from start)
    prefixSumFreq[0] = 1;

    for (char ch : s) {
        // Increment prefix sum for 1, decrement for 0
        if (ch == '1') {
            prefixSum += 1;
        } else {
            prefixSum -= 1;
        }

        // Check how many times this prefix sum has been seen before
        if (prefixSumFreq.find(prefixSum) != prefixSumFreq.end()) {
            count += prefixSumFreq[prefixSum];
        }

        // Update the frequency of the current prefix sum
        prefixSumFreq[prefixSum]++;
    }

    return count;
}

int main() {
    string s;
    cout << "Enter binary string: ";
    cin >> s;

    long long result = countEqualZeroOneSubsequences(s);
    cout << "Number of subsequences with equal number of 0s and 1s: " << result << endl;

    return 0;
}
