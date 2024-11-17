#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int findKthLargestFactor(int n, int k) {
    
    vector<int> factors;

    // Find all factors of n

  for(int i=1;i<=sqrt(n);i++){
      
      if(n%i==0){
          factors.push_back(i);
      }
      if(i!=n/i){          //36 ke lie..agar 4 dala sath ke sath 9 bhi daldia..bs 6 dubaara ni dalenge wo to fir uska eprfect square hi hai na
          factors.push_back(n/i);
      }
  }
    // Sort factors in descending order
    sort(factors.begin(), factors.end(),greater<int>());

    // Return the kth largest factor if it exists, else return 1
    
    if (k <= factors.size()) {
        return factors[k - 1];
    } else {
        return 1;
    }
}

int main() {
    int n, k;
    cout << "Enter the number and k: ";
    cin >> n >> k;

    int result = findKthLargestFactor(n, k);
    cout << "The " << k << "th largest factor of " << n << " is: " << result << endl;

    return 0;
}
