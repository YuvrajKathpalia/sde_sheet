

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


// The intuition behind Moore's Voting Algorithm is simple but powerful. It identifies a potential majority element by tracking a candidate and its frequency in a single pass through the array. If the count becomes zero, a new candidate is chosen. Afterward, the algorithm checks if the candidate is indeed the majority element by ensuring it appears more than half the time in the array. This approach works because a majority element, if it exists, will always outweigh other elements combined when tracked this way.

//n ,one


class Solution{
    public:

int majorityElement(vector<int> v) {

  

    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:

    for (int i = 0; i < n; i++) {

        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;

        else cnt--;
    }

    //checking if the stored element
    // is the majority element:...hoskta h to yhi hoskta h..verify krna pdega.... 

    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;

    return -1;
}
};

