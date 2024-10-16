

//brute...
//n square..

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int length=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(nums[j]>=nums[i]){
                    length=max(length,j-i);
                }
            }
        }

        return length;
        
    }
};


//optimal...

https://leetcode.com/problems/maximum-width-ramp/?envType=daily-question&envId=2024-10-10

/// The solution uses a **monotonic stack** to efficiently find the maximum width ramp in an array. First, it builds a decreasing stack of indices, ensuring each index represents a potential ramp start. Then, it checks from the right, calculating the width by popping valid indices. This approach ensures \(O(n)\) complexity by pushing and popping each index only once.

//famous...

//good..n,n

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        stack<int>st;
        int n=nums.size();

        for(int i=0;i<n;i++){
            
            if(st.empty() || nums[i]<=nums[st.top()]){
                st.push(i);                  //store indexes in decresasing order..//sbse upar sbse chota mtlb 
            }
        }

            //ab peeche se loop chlaenge..
            //ab peeche bade eleents hi pde hone chie jo stack me ni aaye...
            //maxwidth nikal lenge..

            int length=0;

            for(int j=n-1;j>=0;j--){

                while(!st.empty() && nums[j]>=nums[st.top()]){
                    length=max(length,j-st.top());
                    st.pop();
                }
            }         

            return length;
        
    }
};