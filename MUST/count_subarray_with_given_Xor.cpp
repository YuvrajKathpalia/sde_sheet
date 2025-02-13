

//brute force...

//n cube...



#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}




//better...

//n square....




#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}




//optimal....

//prefix..

//dekh..
//example ... 4, 2, 2, 6, 4 , k=6..ans= chaar subarray {4, 2}, 
            //   {4, 2, 2, 6, 4}, {2, 2, 6},
            //    and {6}

//zero ka xor chaar se= chaar...abb chaar ka xor kisse kre ki 6 ajaye , do...check krenge do map me
//maped hai ya nahi...nahi..to age badjayge... aur chaar ka count ++ krdee\ge...

//ab char ka xor do se..aya 6 yhi chayie tha....ab 6 ka xor kisse kre ki 6 ajayge..zero se..
//islie zero ka count one rkhenge phle se...ans++ krdo.. aur 6 ka count bhi ++


//ab 6 ka xor do se, aya chaar..ab chaar ka xor kisse kre ki 6 aje..to ..do map me haini...
//age bdo..aur char ka count dubara plus plus...

//ab chaar ka xor 6 se..aya .. do ...ab do ka xor kisse kree ki 6 aje....chaar..
//aur chaar phle se hai mapped vo bhi do barr...to do bar ans++...ans= hochuka...iska mtlb
//ye hai ki char,,do,6 tak  subarray bnre with xor 6..char,do to phle milgya tha.. do ka map bhi ++ krdena

//ab do aur milgye...do,do,6 aur doosra sirf 6..shi chlra...

//ab do ka xor chaar se..aya 6..aur zero hai amped hai phle se...to ans++ dubara...ans =.chhar subarray



//This approach efficiently finds subarrays with XOR **K** using **prefix XOR** and 
//a **hashmap** in **O(N) time**. 
//We maintain a running XOR (`currentXor`) and check how many times **(currentXor ^ K)** has appeared before,
// as it indicates valid subarrays. The **hashmap stores prefix XOR frequencies**, allowing quick lookups and eliminating the need for nested loops. 🚀

//kyuki currxor^(currxor^k)==k....hota na  isie...


// n
//n


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubarraysWithXOR(vector<int>& nums, int K) {
    int n = nums.size();
    unordered_map<int, int> prefixXorCount;
    
    // Initialize the map with 0 XOR count as 1
    prefixXorCount[0] = 1;

    int count = 0;
    int currentXor = 0;

    
    for (int i = 0; i < n; i++) {

        // Compute prefix XOR up to the current element
        currentXor ^= nums[i];

    
        // Check if (currentXor ^ K) exists in the prefix map
        
        if (prefixXorCount.find(currentXor ^ K) != prefixXorCount.end()) {
            count += prefixXorCount[currentXor ^ K];
        }

        // Add the current prefix XOR to the map
        prefixXorCount[currentXor]++;
    }

    return count;
}

int main() {
    vector<int> nums = {4, 2, 2, 6, 4};  // Example array
    int K = 6;  // Example XOR value

    int result = countSubarraysWithXOR(nums, K);
    cout << "Number of subarrays with XOR " << K << " is: " << result << endl;

    return 0;
    
}
