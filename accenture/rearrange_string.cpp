#include <bits/stdc++.h>


using namespace std;

int main() {
    string str;
    int k;

    cout << "Enter the string: ";
    cin >> str;

    cout << "Enter the value of k: ";
    cin >> k;

    // Sort the first k characters in ascending order
    sort(str.begin(), str.begin() + k);

    // Sort the next k characters in descending order
    sort(str.begin() + k, str.begin() + 2 * k, greater<char>());

    // Define the priority order for the remaining characters
    string priority = "abcdefghstuvwxyzijklmnopqr";

    // Iterate over the remaining characters and sort them based on priority
    for (int i = 2 * k; i < str.length(); i++) {
        char min_char = str[i];
        int min_index = i;
        for (int j = i + 1; j < str.length(); j++) {
            if (priority.find(str[j]) < priority.find(min_char)) {
                min_char = str[j];
                min_index = j;
            }
        }
        swap(str[i], str[min_index]);
    }

    cout << "The rearranged string is: " << str << endl;

    return 0;
}