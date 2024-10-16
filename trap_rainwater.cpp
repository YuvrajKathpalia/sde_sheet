//brute force...

//o(n^2)..//o(1)...

//har index kelie phlele leftmax nikal liaa(while loop)..similalrly fir 
//right max nikal lia...

//fir min(leftmax,rightmax)-arr[i]..for all index...
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& arr) {
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int leftMax = 0, rightMax = 0;

        while (j >= 0) {
            leftMax = max(leftMax, arr[j]);
            j--;
        }

        j = i;

        while (j < n) {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The water that can be trapped is " << trap(arr) << endl;

    return 0;
}


//BETTER APPROACH...
//PREFIX ,SUFFIX ARRAY...

//O(3N)..
//O(2N)

#include<bits/stdc++.h>

using namespace std;

int trap(vector < int > & arr) {

  int n = arr.size();
  int prefix[n], suffix[n];

  prefix[0] = arr[0];

  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }


  suffix[n - 1] = arr[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }

  int waterTrapped = 0;

  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}



//OPTIMAL...

//optimal 2 pointer...(brute har point pe leftmax ,rightmax nikalo..(2 alag alg while loop se)...fir 
//ans +=min(leftmax,rightmax) -ans[i])...

//better...prefix,suffix array lelo...(max maintain krte rho prefix me)..aur siffix me peeche se maintain krte rho...


//but in sabki joorat ni...

//best approach is 2 pointer....left,right..
////min wale pe operate krenge...
//agar left wala right wale se chota..to left ke hisab se bhrenge...

//agar left walaleftmax hai waha tak kaa...tab to leftmax hi update krenge ..bhr ni paenge us case me kcch...
//agar leftmax ni hia wo..to paani bhrskte..leftmax-height[l] se...fir l++...

//.similalrly... right walachota hai to same procedure..aur r++...

//O(n)..
//o(1)..

class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();

        int l=0;
        int r=n-1;

        int ans=0;
        int maxleft=0;
        int maxright=0;

        while(l<r){

            if(height[l]<=height[r]){

                if(maxleft>height[l]){
                    ans +=maxleft-height[l];
                }

                else{
                    maxleft = height[l];
                }

                l++;
             
            }

            else{
               
                if(maxright>height[r]){
                    ans += maxright-height[r];
                }
                else{
                    maxright = height[r];
                }

                r--;
                }
            
        }

        return ans;
        
    }
};