
//BRUTE FORCE..
//ITERATIVE...


//har point ke liye uske se leke usse left jate jayge
//kitna area max banskta hai...height= min wali lenge jo wha tak hogi ...obvio..


//loop lgao...o se n tk chalege....har point pe.
//.minheight nikaalo wha tak ki ...ek aur loop lgake...

// width calculate kro...aur area maximise kro...

//o(n^2)..
//o(1)...




#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int area = 0;

    // Iterate through each bar in the histogram
    for (int i = 0; i < n; i++) {
        int j = i;
        int minheight = heights[i]; 

        // Expand left until the first bar
        while (j >= 0) {
            minheight = min(minheight, heights[j]); 
            int width = i - j + 1; 

            area = max(area, minheight * width);  

            j--;  
        }
    }

    return area; 
}

int main() {
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << "The largest rectangle area in the histogram is " << largestRectangleArea(heights) << endl;

    return 0;
}



//OPTIMALL...USING STACK...USING CONCEPT OF NEXT SMMER ELEMENT ON RIGHT , AND PREVIOUS SMALLER ELEMENT ON LEFT

//HAR INDEX KE LIEE...USKI HEIGHT AUR NEXT SMALLER ELEMENT KA INDEX - PREVIUS SMALLER ELEMENT(YE HOGI WIDTH)* US BAR KI HEIGHT...
//DRY RUN SOCHO 5 WAALE BAAR KA.... 4-1-1=2*5=10...

//O(N)..
//O(N)>.

class Solution {
public:


vector<int> nextSmaller(vector<int>& heights) {

    int n = heights.size();

//HUM STACK ME INDEX MANAGE KRR RE THIS TIME....

    stack<int> st;  //initially kuch push ni kra..-1 bhi...kyuki jab empty stack hai ya koi nse possible ni hum n hi return krenge..
    //taki poori width cover kar payyee..logical baat hai...

    vector<int> ans(n); 

    // We start from the end of the array...

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {  
            st.pop();
        }
       if(st.empty()){
        ans[i]=n;
       }
       else{
        ans[i]= st.top();
       }
        st.push(i); // Push the current index(heights[i] ni....)
    }
    return ans;
}

vector<int> previousSmaller(vector<int>& heights) {

    int n = heights.size();
    stack<int> st;
    vector<int> ans(n);  //declare krnaa must..iske bina ni chlra tha..

    // We start from the beginning of the array
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
         if(st.empty()){
        ans[i]=-1;   //jab koi prev smaller na mile.. to -1 taki poori width cover krpaye..(nse me n kia tha)
       }
       else{
        ans[i]= st.top();
       }
        
        st.push(i); // Push the current index
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {


    int n = heights.size();

    vector<int> nse = nextSmaller(heights);
    vector<int> pse = previousSmaller(heights);

    int max_area = 0;

    for (int i = 0; i < n; i++) {
        // Calculate the area considering the current height as the smallest height
        max_area = max(max_area, heights[i] * (nse[i] - pse[i] - 1));
    }

    return max_area;
}
};