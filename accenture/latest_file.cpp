Given a string array of file names, return the highest version number among correctly 
named files in the format "File_X" (X is numeric). 
If no valid files exist or the array is empty, return -1.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isValidFileName(const string& file) {
    if (file.substr(0, 5) != "File_") return false;

    // Manually check if the rest of the string contains only digits
    for (size_t i = 5; i < file.size(); ++i) {
        if (!isdigit(file[i])) {
            return false;
        }
    }

    return true;
}

int findLatestVersion(const vector<string>& files, int size) {
    if (size == 0) return -1; // If the array is empty, return -1

    int maxVersion = -1;

    for (const string& file : files) {
        if (isValidFileName(file)) {
            int version = stoi(file.substr(5));
            maxVersion = max(maxVersion, version);
        }
    }

    return maxVersion;
}

int main() {
    vector<string> input1 = {"File_1", "File_3", "File_2", "InvalidFile", "File_X"};
    int input2 = input1.size();

    int result = findLatestVersion(input1, input2);
    cout << "Latest version: " << result << endl; // Output: 3

    return 0;
}
