
//o(nlogk)..

// Inserting Elements into the Heap:

// Each insertion into the heap takes O(log k) because the heap size is limited to k.
// For n elements, the total cost is O(n log k).

// Removing Elements from the Heap:

// When the heap size exceeds k, the smallest element is removed.
// This operation also takes O(log k).
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