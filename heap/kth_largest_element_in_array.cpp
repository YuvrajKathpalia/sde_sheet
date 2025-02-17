
//o(nlogk)..agar normal tareeke se krte bina if condition lgaye..o(n) aati...

// Inserting Elements into the Heap:

// Each insertion into the heap takes O(log k) because the heap size is limited to k.
// For n elements, the total cost is O(n log k).

// Removing Elements from the Heap:

// When the heap size exceeds k, the smallest element (top element)is removed....kyuki aur jo bhi
// element ayege wo tab bhi kth largest to ni hopayge agar phle ni tha to...


// This operation also takes O(log k)...tab bhi..o(n*(logk+logk))hi to rhega..same hi baat..

// However, this is already accounted for in the insertion cost since we perform a pop only after an insertion when the heap size exceeds k.
// Total Time Complexity:--o(nlogk)..


//sc..o(K)...


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n=nums.size();

        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto x:nums){
            pq.push(x);

            if(pq.size()>k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};