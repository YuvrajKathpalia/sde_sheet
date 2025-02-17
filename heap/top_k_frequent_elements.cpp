// unordered map se frequency maintain kro..
// min heap lo(priority pq..pair wala lo ..taki count , elemnt dono maintain kr payo)
//fir push kro min heap me..sare ek sath mat kro.. jab bhi size >k hora ..top wala mtlb least frequent nikalte jao..
//obvio agar kam size me vo least frequent bnra to bde size me to kya hi bnega waise bhi

//fir pq bnjega ..top k elemnts ka..bas ab ek vector lo...aur push krvate jao usme..



//tc...o(n)+o(k+n-k*(logk)= o(nlogk)) +o(klogk) ==o(nlogk)
//sc..o(n)+o(k)+o(k)...


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freqMap;

    
        for (int num : nums) {
            freqMap[num]++;
        }

        // Min heap..

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


        for (auto& x : freqMap) {  //silly..nums pe loop mt lgadena..

            pq.push({x.second, x.first});  //o(logk)..

            // If heap size exceeds k, remove the least frequent element
            if (pq.size() > k) {  //o(logk)..
                pq.pop();
            }
        }

        // Extract elements from the heap

        vector<int> result;

        while (!pq.empty()) {

            result.push_back(pq.top().second);
            pq.pop();

        }

        return result;
    }
};
