


//O(N).. BAHR WALA LOOP KI N..AUR ANDAR WALA WHILE LOOP..KABHII 1 BAR KBHI 2 BAAR---KBHI N-1 BAR CHLEGA
//par kar to st pop hi rha...o(1) hi chlta...



//O(N)... 
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {

    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if(st.empty()){
            nge[i]=-1;
        }
       else{
        nge[i]=st.top();
       }

        st.push(nums[i]);
    }

    return nge;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


//SIMILALRY....NEXT SMALLER,...


vector<int> nextSmallerElement(vector<int>& nums) {


    int n = nums.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (st.empty()) {
            nse[i] = -1;
        } else {
            nse[i] = st.top();
        }

        st.push(nums[i]);
    }

    return nse;
}



//PREVIOUS GREATER..


vector<int> previousLargerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ple(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if (st.empty()) {
            ple[i] = -1;
        } else {
            ple[i] = st.top();
        }

        st.push(nums[i]);
    }

    return ple;
}


//PREVIOUS SMALLER...

vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (st.empty()) {
            pse[i] = -1;
        } else {
            pse[i] = st.top();
        }

        st.push(nums[i]);
    }

    return pse;
}



//SIMILALRY..NEXT GREATER...IN CIRCULAR ARRAY....


#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }

        if (i < n) {
            if (st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }
        }

        st.push(nums[i % n]);
    }

    return nge;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

// The intuition behind **Next Greater Element in a 
//Circular Array** is to treat the array as if it loops.
// By iterating twice, we simulate this circular behavior.
// A stack tracks potential next greater elements, 
//and for each element, we pop smaller values
// until finding a larger one or assigning `-1`.