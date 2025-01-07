https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        unordered_set<string> ans;

        for (string& x : words) {
            for (string& y : words) {
                
                if (x != y && y.find(x) != string::npos) {

                    ans.insert(x);
                }
     //cout<<string::npos<<" "<<endl;
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};


// string::npos is a special constant that represents an invalid position. It is defined as the largest possible value for a size_t type (which is an unsigned integer).
// string::npos is typically used to indicate that a search operation, such as find(), did not succeed.
