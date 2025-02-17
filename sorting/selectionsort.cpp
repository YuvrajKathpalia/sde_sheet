
//iterations lgayge...har ith iteration me ith element ko minimum element in whole array(after i) se swapkrdege...
//mtlb har iteration ke baad ek ek element apni shi position pe jata jayga... 


//tc...o(n^2)..
//sc..o(1)


#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i; // Assume the first element is the minimum

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update the index of the minimum element
            }
        }
        swap(arr[i], arr[minIndex]); // Swap the found minimum with the first element
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Before Sorting: ";
    printArray(arr);
    
    selectionSort(arr);
    
    cout << "After Sorting: ";
    printArray(arr);
    
    return 0;
}
