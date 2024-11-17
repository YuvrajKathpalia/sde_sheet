#include <iostream>
using namespace std;

// Function to count the number of set bits in a number
int countSetBits(int n) {
    int count = 0;
    while (n) {
        // Increment count if the least significant bit is 1
        count += n & 1;
        
        // Right shift the bits to check the next bit
        n >>= 1;
    }
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = countSetBits(num);
    cout << "Number of set bits in " << num << " is: " << result << endl;

    return 0;
}
