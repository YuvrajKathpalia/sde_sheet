

//brute...
//n square...

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

//better..using map..
//n ,n

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int,int>count;

        for(int i=0; i<n;i++){
            count[nums[i]]++;
        }

        for(auto i : count){
            if(i.second>n/2){
                return i.first;
            }
        }
        return -1;
    }
};



//optimal
//moore voting...


//array traverse krenge...
//ek elemnt lenge..


// The intuition behind Moore's Voting Algorithm is simple but powerful. 

//It identifies a potential majority element by tracking a candidate and its frequency in a single pass 
//through the array. If the count becomes zero, a new candidate is chosen.

// Afterward, the algorithm checks if the candidate is indeed the
// majority element by ensuring it appears more than half the time in the array. 

//This approach works because a majority element, if it exists, will always outweigh
// other elements combined when tracked this way.


// The program uses the Boyer-Moore Voting Algorithm to find the majority element in an array
//  (element appearing more than n/2 times). It first selects a candidate by 
//  canceling out minority elements, then validates the 
// candidate by counting its occurrences. Time complexity is \(O(n)\), and space complexity is \(O(1)\).

//no extra space..o(1) me hogya kaam...

//o(n)..o(1)..

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size(); 


        int count = 0; // To keep track of the count of the current candidate
        int element; // To store the potential majority element

         //Finding the candidate for the majority element

        for (int i = 0; i < n; i++) {

            if (count == 0) { 
                // If the count is 0, set the current element as the candidate
                element = nums[i];
                count = 1; // Start counting this candidate
            } 
            else if (nums[i] == element) {
                 // If the current element matches the candidate, increment the count
                count++;
            } 
            else {
                // If the current element does not match, decrement the count
                count--;
            }
        }

        //  Verifying the candidate
        //hoskta h to yhi hoskta h..verify krna pdega.... (kya pta koi bhi na ho)..

        count = 0; 
        for (int i = 0; i < n; i++) {
            if (nums[i] == element) {
                count++; 
            }
        }

        //  Check if the candidate is the majority element

        if (count > (n / 2)) {
            return element; 
        }

        return -1; 
    }
};

