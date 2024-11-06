#include <bits/stdc++.h>
using namespace std;

int longestDecreasingSubarray(const vector<int>& temperatures) {
    if (temperatures.empty()) return 0;

    int maxLength = 1;  
    int currentLength = 1;  

    for (int i = 1; i < temperatures.size(); i++) {

        if (temperatures[i] < temperatures[i - 1]) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        }
         else {
            currentLength = 1;  // Reset length for new subarray
        }
    }

    return maxLength;
}

int main() {
    vector<int> temperatures;
    int n, temp;
    
    cout << "Enter the number of temperatures: ";
    cin >> n;

    cout << "Enter the temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        temperatures.push_back(temp);
    }

    int result = longestDecreasingSubarray(temperatures);
    cout << "Length of the largest monotonically decreasing subarray: " << result << endl;

    return 0;
}


//example...Temperatures: 73 72 71 70 68 69 65 64


// The longest monotonically decreasing subarray in this case is the subarray [73, 72, 71, 70, 68] with a length of 5.