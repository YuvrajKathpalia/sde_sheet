//approach1..unordered set...o(N)..o(n)..

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> result;

        for (auto num : set1) {
            if (set2.find(num) != set2.end()) {
                result.push_back(num);
            }
        }

        return result;
    }
};



//approach2..use unordered map..count store krlo ek array ka..
///doosre array me loop lgake check kro agar mapped to ans vector
//me store , aur map se erase krdo taki bad me na aye
//kyuki duplicates ni chie na..