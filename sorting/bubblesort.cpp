//nested loop...but subarray type nii...
//bahar wale loop iterations ke lie chlra..n-1 iteration hoygi obvio

//aur andar wala loop 0 se n-i-1 tak chlra adjacent elements compare aur swap krraa...n-i-1 islie kyuki har iteration
//ke baad ek element to minimum apni jagah pe phoch jayga(sbse bade wala last pe phochjayga..)....


//tc..o(n^2)...
//sc..o(1)..

//this can be optimised ...see neeche wala code.

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {

    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) { // Number of passes
        
        for (int j = 0; j < n - i - 1; j++) { // Last i elements are sorted

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
                
            }
        }
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    cout << "Original Array: ";
    printArray(arr);
    
    bubbleSort(arr);
    
    cout << "Sorted Array: ";
    printArray(arr);
    
    return 0;
}


//optimised version...
//har iteration ke baad check krege ki koi swap hua bhi hai ya nhi , agar koi swap ni hua to mtlb phle
//se hi sorted hai array , tbhi break krdege...

//tc..worst case--o(n^2)..best case..o(n)..agar ek hi pass me chlgyi to
//sc..o(1).

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) { // Number of passes

        bool swapped = false;  // Optimization: Check if swapping happened

        for (int j = 0; j < n - i - 1; j++) { // Last i elements are sorted

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // If no swapping occurred, array is sorted
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    cout << "Original Array: ";
    printArray(arr);
    
    bubbleSort(arr);
    
    cout << "Sorted Array: ";
    printArray(arr);
    
    return 0;
}
