//glt h ye

Given a positive integer, rearrange its bits such that all set bits (1s) are positioned consecutively,
 and return the minimum possible value obtained by rearranging the bits in binary form.

//sari 1 bits right me...

//to phle count krlo 1 bits(set bits)..
//fir jitni baar set bits aari.. utni baar 0 ko leftshift krna 1 se...

//examlleinout 5..101..set bits=2...
//isko 011 krdena..ans=3.. to agar 0 ko ekbar leftshift by1  =01 . do baar.. 011


#include <iostream>
using namespace std;



int countSetBits(int n) {
    int count = 0;


    while (n > 0) {
        if (n & 1) {  // If the least significant bit is 1, increment count
            count++;
        }
        n >>= 1;  // Right shift n to process the next bit
    }
    return count;
}

// Function to rearrange the bits to create the minimum possible number
int rearrangeBits(int n) {
    




    // Step 2: Build the smallest number by placing all set bits at the rightmost
    int result = 0;
    for (int i = 0; i < setBits; i++) {
        result |= (1 << i);  // Set each bit in the result starting from the least significant position

        //bits me += kki jgh |= use krte(or)..same baaat..retain krleta purana..
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int result = rearrangeBits(n);
    cout << "Minimum possible value after rearranging bits: " << result << endl;

    return 0;
}
