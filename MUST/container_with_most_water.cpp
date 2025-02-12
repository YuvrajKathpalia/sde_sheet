https://leetcode.com/problems/container-with-most-water/description/


//easier earsion of trap rainwater..usme total water nikalna tha..

//isme max water jo 2 container ke beech aaskta....MATLAB AREA MAXIMISE KRENGE...WIDTH AUR HEIGHT SE..
//MAIN HEIGHT SE KHELNA MTB.. MIN WALE HEIGHT LENI 2 DANDO ME SE..USI KE BEECH WATER STORE HOSKTA
///USI SE AREA NIKAL SKTA..

//brute..nested loops..n^2..optimal-2 pointer..o(N).



//brute--o(n^2)..

        int maxwater=0; 
        int h=0;
        int width=0;

        int n=height.size()

        //checking all possible container 

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++){

                width=j-i;  

                h=min(height[j],height[i]);

                
                int area=width*h;      //area of the container

                maxwater=max(area,maxwater);


            }
        }
        return maxwater;



//optimal...o(N)//.o(1)...

//2 pointer..l aur r lo..
//loop chlao l<r....
//width nikalo..height=min wali lo..
//area maximise krdo....

//l,r kese increment/decrement?-- agar l chota to l bdado
//agar r chota to r kum krdo..obvio...max area nikalna naa



class Solution {
public:
    int maxArea(vector<int>& height) {

    
       int n=height.size();

       int l=0;
       int r=n-1;
       

       int ans=0;

       while(l<r){

        int width = r-l;

        int heightt = min(height[l],height[r]);

        ans = max(ans,width*heightt);

        if(height[l]<=height[r]){  //l try krchuke hai na mtlb agar wo chota to...islie l bdadia....
            l++;
        }
        else{
            r--;
        }

        
       }

       return ans;
        
    }
};






//trap rainwater optimal solution---...

class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        
        int l=0;
        int r=n-1;

        int leftmax=0;
        int rightmax=0;

        int ans=0;

        while(l<r){

            if(height[l]<=height[r]){

                if(height[l]>=leftmax){
                    leftmax= height[l];
                }
                else{
                    ans+=leftmax-height[l];
                }

                l++;
            }
            else{

                if(height[r]>=rightmax){
                    rightmax= height[r];
                }
                else{
                    ans+=rightmax-height[r];
                }

                r--;
            }
        }

        return ans;

    }
};