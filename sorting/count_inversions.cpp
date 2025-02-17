
// brute force..o(n^2).very easy
//nested loop...andr wala i+1 se startkrna... aur bs condition check krlo
//.atch hogyi to count++...

class Solution {
  public:
   
   
    long long int inversionCount(long long arr[], int n) {
        
        long long int count=0;
        
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             
             if(arr[i]>arr[j]){
                 count++;
             }
         }
     }
     
     return count;
    }
};




//approach 2..use funda of merge sort...
//dekh phle..
//agar hum array ko 2 sorted hisso me baatde(low-mid,mid+1-high)

//aur compare kre elements agar phli array me bda milgya doosri array ke element
//se to obviously phli array ke aage walee bhhi uss dusri array ke elemnt se
//bade hongeee...poora count++...

//merge sort me yhi to hota tha phle tod tod ke sort krte the
//fir jab merge krne ka time ata tha tb compare krte the..
//ussi code me addition krne hai bass..
//count wala funda jodna hai...


//O(NLOGN)
//O(N)...


#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high, int& count) {
        vector<int> temp;
        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
                // Count inversions
                count += (mid - i + 1); // Correctly count the inversions..(agar i , j se bada hai
                                     // to i ke aage waale bhi to j se bade hongee.. )
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy the sorted elements back into the original array
        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    int mergesort(vector<int>& arr, int low, int high, int& count) {
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;

        mergesort(arr, low, mid, count);
        mergesort(arr, mid + 1, high, count);
        merge(arr, low, mid, high, count);

        return count;
    }

    int inversionCount(vector<int>& arr) {
        
        int n = arr.size();
        int count = 0; 
        
        mergesort(arr, 0, n - 1, count);
        return count;
    }
    
};

