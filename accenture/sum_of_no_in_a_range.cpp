

//optimal... j tak ka sum - i tak ka sum + i...== i se lke j ka sum(both inclusive)..

#include <iostream>
using namespace std;

int main() {
    int i, j;
    cin >> i >> j;
    
    // Validation
    if (i > j || i < 0 || j > 10000) {
        cout << "Invalid range! i should be <= j and between 0 and 10000" << endl;
        return 1;
    }
    
    // Use long long to prevent overflow..vimp..

    long long sum_j = (long long)j * (j + 1) / 2;
    long long sum_i = (long long)i * (i + 1) / 2;
    
    cout << sum_j - sum_i + i << endl;

    return 0;
}


// //brute..
// long long sum = 0;
//     for (int k = i; k <= j; k++) {
//         sum += k;
//     }
//     return sum;