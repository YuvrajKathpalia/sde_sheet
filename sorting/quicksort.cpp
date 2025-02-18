// Quick Sort is a divide-and-conquer algorithm. It selects a pivot, 
// partitions the array around it (elements smaller on the left, larger on the right), 
// and recursively sorts the sub-arrays. 


// This process continues 
// until the array is fully sorted.
//  Its average time complexity is O(n log n), but worst-case is O(n²).

//

//Best Case: The array is split into nearly equal halves at each step, 
//leading to a recursion depth of O(log n) and time complexity O(n log n).


//Worst Case: The array is split very unevenly (pivot always at one extreme), 
//leading to a recursion depth of O(n) and time complexity O(n²).



//Best Case Space Complexity: O(log n) (because recursion depth is balanced).
//Worst Case Space Complexity: O(n) (due to deep recursion when the pivot choice is poor and the array is unbalanced).




#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>&nums , int low , int high){

    int pivot=nums[high]; //last wala element let krlio pivot..isko sahi jagah lana..

    int i=low;


    for(int j=low;j<high;j++){ //aur high-last element hai..to mtlb low-pivot-1 tak chlrhaa loop..

        if(nums[j]<=pivot){       //agar pivot se chota koi bhi milraha usse shuru me late aao..aur iteration khtm hone baad pivot in sab choto ke baad ayga aur usse bado se phle ayga
            swap(nums[j],nums[i]);
            i++;
        }
    }

    swap(nums[i],nums[high]); //pivot ko shi jagah laao(such that uske left me sare usse kum aur right me jada)..

    return i;//pivotindex return krdo..
}

void quicksort(vector<int>&nums, int low , int high){

    if(low<high){

        int pi = partition(nums,low,high);  //pivotindex nikalo...aur recrsively sort krte rho left aur right side..

        quicksort(nums,low,pi-1);
        quicksort(nums,pi+1,high);


    }
}

int main(){

    int n;

    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    quicksort(nums,0,n-1);

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}