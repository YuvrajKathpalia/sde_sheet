


//brute force..nlogn..

class Solution {
public:
    void sortColors(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
    }
};



//better...

//o(n)..+o(n)..
//o(1)..

//count krlia teeno ka alg alg phle..
//fir loop lgaya phle  0 ke daale..fir 1 ke fir 2ke...start aur end dhyan selikhna for loop 
//easy h


class Solution {
public:
    void sortColors(vector<int>& arr) {

        int zero_count=0,one_count=0,two_count=0;

        int n=arr.size();

        for(int i=0;i<n;i++){

            if(arr[i]==0){
                zero_count++;
            }
            else if(arr[i]==1){
                one_count++;
            }
            else{
                two_count++;
            }
       
        }

        for(int i=0;i<zero_count;i++){
            arr[i]=0;           
        }

        for(int i=zero_count; i<zero_count+one_count;i++){
            arr[i]=1;
        }
        for(int i=zero_count+one_count; i<zero_count+one_count+two_count;i++){
            arr[i]=2;
        }

        
    }
};




//optimal...
//dutch national flag problem..

//o(n)..
//o(1)..
//3 pointers low,mid,high;...mid to traverse krne le lie hi kaam ara(0 se hi start hoga)(bas naam dene ke lie mid dedia)



// ### Dutch National Flag Problem - Summary(3 pointers maintain krenge low ar high se 0 aur 2 ki boundary maintain
//krenge...aur mid see travserse krenge elements shuru se leke end tak...)

// The objective of the Dutch National Flag problem is to sort an array of three distinct values (e.g., 0, 1, 2) efficiently in linear time `O(n)` using constant space `O(1)`.

// **Problem:** Sort an array containing only three distinct values (0, 1, 2) in a single pass.

// **Solution:** Use three pointers:
// - **Low:** Marks the boundary for 0s.
// - **Mid:** Traverses the array.
// - **High:** Marks the boundary for 2s.

// **Steps:**
// 1. **Traverse** the array with `mid`.
// 2. **Swap** elements as follows:
//    - If `arr[mid] == 0`, swap with `low` and increment both `low` and `mid`.
//    - If `arr[mid] == 1`, just increment `mid`.
//    - If `arr[mid] == 2`, swap with `high` and decrement `high`.
// 3. Continue until `mid` exceeds `high`.

// **Outcome:** The array is sorted in `O(n)` time with `O(1)` space, efficiently placing all 0s, 1s, and 2s in their correct order.

// This approach is ideal for problems like sorting colors represented by 0s, 1s, and 2s.


class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n=nums.size();

        int low=0;
        int mid=0;
        int high=n-1;

        while(mid<=high){   //silly..low<=high ni h

            if(nums[mid]==0){
               
               swap(nums[mid],nums[low]);
               low++;
               mid++;  

               //taki 0 se low-1tak 0 bhar jaye..dry run smj ajega easily..
            }

            else if(nums[mid]==1){

                mid++;
                //kyuki hume low se mid-1 me 1 chie na sare..
            }

            else{  //nums[mid]==2
              
              swap(nums[mid],nums[high]);
              high--;

              //taki high+1 se last tak 2 milje..
            }

        }
        
    }
};