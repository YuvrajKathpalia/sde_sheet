Given an integer array, find a pair whose sum is 18 and the first element is greater than the second. Return the pair with the maximum product, or an empty array if none exist.


#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> maximizePairProduct(int N, const vector<int>& A) {
    int maxProduct = INT_MIN;
    vector<int> result;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int x = A[i], y = A[j];

            // Check if the pair satisfies the sum and order conditions
            if ((x + y == 18 && x > y) || (x + y == 18 && y > x)) {
                int product = x * y;

                if (product > maxProduct) {
                    maxProduct = product;
                    result = {x, y};
                }
            }
        }
    }

    return result;
}

int main() {
    int N = 7;
    vector<int> A = {10, 8, 9, 9, 12, 6, 7};

    vector<int> result = maximizePairProduct(N, A);

    if (!result.empty()) {
        cout << "The pair: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        cout << "No valid pairs found.\n";
    }

    return 0;
}
