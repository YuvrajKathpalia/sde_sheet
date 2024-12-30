//approach1..brute force..o(n^3) 



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        int n=nums.size();

      
      set<vector<int>> output;   //set apna..duplicate hatane ke lie

for (int i = 0;i<n;i++) {
  for(int j = i+1;j<n; j++) {
     for(int k = j+1; k<n; k++) {

         if(nums[i] + nums[j] + nums[k] == 0) {

     vector<int> temp = {nums[i], nums[j], nums[k] };

         sort(temp.begin(), temp.end());    //sort krke set me dalna pdega..
                                            //jaise [-1,0,1] hai aur [-1,1,0] hogya
                                            // hai to ek hi na..set to exact duplicate hatayga na
                                         // to phle sort to krna hi pdega set me dalne se phle bhi
                                         //agr uske baad bhi duplicate koi aya to set ni lega apne 
                                         //aap usee..
        output.insert(temp);
         }
}
}
}

//fir apne 2d vector me store krvate gye..aur yhi return
    for(auto x: output){
        ans.push_back(x);

    }    
    return ans;    
    }
};




// //better...ISSE NEECHE WALI APPROACH BHI N^2 HAI...WO DEKHLO..YE UPAR UPAR SE..
// //on^sq
// //o n^sq

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// // Function to find unique triplets that sum to zero
// vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<vector<int>> ans;   
//     int n = nums.size();

//     set<vector<int>> output;    // To store unique triplets
    
    
//     for(int i = 0; i < n; i++) {
//         set<int> hashset;      // HashSet to store already seen values in this iteration
        
//         // Inner loop for the second element nums[j]
//         for(int j = i + 1; j < n; j++) {

//             int k = -(nums[i] + nums[j]);  // Find the required third element (k)
            
            
//             if(hashset.find(k) != hashset.end()) { 
                
//                 vector<int> temp = {nums[i], nums[j], k};
                
//                 // Sort the triplet to avoid duplicates in different order
//                 sort(temp.begin(), temp.end());
//                 output.insert(temp);  // Insert the triplet into the set
//             } 
//             else {
//                 // Otherwise, add nums[j] to the hashset
//                 hashset.insert(nums[j]);
//             }
//         }
//     }
    
//     // Convert the set of triplets into a 2D vector
//     for(auto x : output) {
//         ans.push_back(x);
//     }    
    
//     return ans;
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements in the array: ";
//     cin >> n;  // Input the size of the array
//     vector<int> nums(n);  // Create a vector of size n

//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];  // Input elements of the array
//     }

//     vector<vector<int>> result = threeSum(nums);

//     // Print the result
//     cout << "Triplets that sum to zero:" << endl;

    
//     for (const auto& triplet : result) {  //printing 2d array... ( [[-1,-1,2],[-1,0,1]])..

//         cout << "[";
//         for (int num : triplet) {
//             cout << num << " ";
//         }

//         cout << "]" << endl;
//     }

//     return 0;
// }


// You can use only auto, but it creates a copy of each element, which might be inefficient.
// Use auto& for modifying the original, and const auto& for read-only access. This ensures better performance and avoids unnecessary copies.




//approach threee.better ..isme hashset einsert ni krrreee ...isme bas whi two d setof vector lia
//store krne lie...aur usse answer baadme two d vector me daldia..phle hi sort krdia aur isme

//o n^sq
//o n^sq...


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        
        sort(nums.begin(), nums.end());

        set<vector<int>> s;

        vector<vector<int>> output;

        for (int i = 0; i < nums.size(); i++){

//2 pointers--
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                } else if (sum < 0) {
                    j++;

                } else {
                    k--;
                }
            }
        }


        for(auto x : s){
            output.push_back(x);
        }

        return output;
    }
};
