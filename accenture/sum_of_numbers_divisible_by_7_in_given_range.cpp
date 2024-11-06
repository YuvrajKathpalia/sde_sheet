#include <iostream>
using namespace std;

int sumOfDivisibleBy7(int start, int end) {
    int sum = 0;

    // Iterate through the range
    for (int i = start; i <= end; ++i) {
        if (i % 7 == 0) {  // Check if divisible by 7
            sum += i;
        }
    }

    return sum;
}

int main() {
    int start, end;

    // Take input for the range
    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;

    // Call the function and display the result
    int result = sumOfDivisibleBy7(start, end);
    cout << "Sum of numbers divisible by 7 in the range [" << start << ", " << end << "] is: " << result << endl;

    return 0;
}
