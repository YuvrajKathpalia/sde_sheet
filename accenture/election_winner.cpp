

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> age, vector<int> vote) {
    unordered_map<int, int> mpp; // To store frequency of votes
    
    for (int i = 0; i < n; i++) {
        if (age[i] <= 18) { // Consider votes from those aged 18 or less
            mpp[vote[i]]++;
        }
    }
    
    int maxFrequency = 0;
    int candidate = -1;
    bool multipleMax = false; // To track if there are multiple maximums
    
    for (auto x : mpp) {
        if (x.second > maxFrequency) {
            maxFrequency = x.second;
            candidate = x.first;
            multipleMax = false; // Reset the flag
        } else if (x.second == maxFrequency) {
            multipleMax = true; // Found another vote with same max frequency
        }
    }
    
    return multipleMax ? -1 : candidate; // Return -1 if there's a tie for max
}

int main() {
    int n;
    cin >> n;

    vector<int> age(n);
    vector<int> vote(n);

    for (int i = 0; i < n; i++) {
        cin >> age[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> vote[i];
    }

    int result = solve(n, age, vote);
    cout << result << endl;

    return 0;
}
