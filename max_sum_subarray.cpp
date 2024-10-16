

//brutr force...o(n^3)...
//o(1)..


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                int sum=0; 

                for(int k=i;k<=j;k++){
                    sum += nums[k];
                }

                maxi= max(maxi,sum);


            }
        }

        return maxi;
        
    }
};




//better ...o(n^2)...
//o(1)..


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){

            int sum=0;
            for(int j=i;j<n;j++){

               sum += nums[j];
               maxi= max(maxi,sum);
        }
               
            }

        return maxi;
        
    }
};






//optimaal...o(n)...kadane algorithm...
//o(1)..

//ek hi lloop lgaege...at any point you have to choices include it in the subarray or start a new subarray...
//agar pichle index tak -ve sum bnraa to ...us index pe sum-0 krdenge...warna to hum normal sum calculate krte rhenge
//aur maxi maintain krte rhenge...



class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;

        int sum=0;

        for(int i=0;i<n;i++){

        sum += nums[i];

        if(sum>maxi){
            maxi = sum;
        }

        if(sum<0){
            sum=0;
        }
            }

        return maxi;
        
    }
};



//FOLLOW-UP-QUESTION...AGAR SUBARRAY PRINT KRANE KO BHI BOLE...

//JHA SUM ZERO -VE HORA.WHA SUM=0 KRDETE THE NA..TO USKE AGLE
//INDEX STORE KRLIO AS A POTENTIAL START INDEX...

//CHLTA RHEGA...

//AGAR SUM>MAXSUM SE BDA AGYA...TO START INDEX KO US TEMP INDEX SE REPLACE
//KARDO ..AUR END INDEX TO I HI RHEGA....

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;  // To store the maximum sum
    int sum = 0;         // To store the current sum
    
    int start = 0;       // To track the start index of the subarray
    int end = 0;         // To track the end index of the subarray
    int tempStart = 0;   // Temporary start index to track possible new subarray

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // If the current sum is greater than the previous maximum sum
        if (sum > maxi) {
            maxi = sum;
            start = tempStart;  // Update the start index of the maximum sum subarray
            end = i;            // Update the end index
        }

        // If the current sum becomes negative, reset it to 0
        // and set tempStart to the next index
        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
    }

    // Print the subarray with the maximum sum
    cout << "The subarray with the maximum sum is: ";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return maxi;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxSum = maxSubArray(nums);
    cout << "The maximum sum is: " << maxSum << endl;

    return 0;
}
