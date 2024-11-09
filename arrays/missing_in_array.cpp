
https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&category=Arrays&sprint=a663236c31453b969852f9ea22507634&sortBy=submissions

//brute..khud...o(nlogn)..o(1)..
//sort

class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int j=1;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]!=j){
                return j;
            }
            j++;
        }
        
        return j; //agar sirf arr[]=[1] hai..to 2 reutrn krna..mtlb last value of j..(islie j maintain krre the)
    }
};



//better , use set...o(n)..o(n)..

//1 se leke array ke size+1 tak numbers daldo ek set me..
//fir array me loop lgao jo jo number ata jara hatade jao set se...ek last bachjega,,
//wo return krna..


class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        
       int n = arr.size() + 1;  // Since one number is missing
        unordered_set<int> s;

        // Insert all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }

        // Remove numbers present in the array
        for (int num : arr) {
            s.erase(num);
        }

        // The only remaining number in the set is the missing number...
        return *s.begin();
        
    }
};



//totalsum-actual sum

//better..o(n)..o(1_..)

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        
        
        int n = arr.size() + 1;  // Since one number is missing
        int expectedSum = n * (n + 1) / 2;  // Sum of first n numbers
        int actualSum = 0;
        
        for (int num : arr) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;  // The missing number
    }
};



//best.o(n)..o(1)..


///1 se leke n+1(n-array ka size) tak xor lelo...

//fir array me xor lgake , jo xor aya tha usse xor krte jaoo....simialr number cancel out hojege
//a^a=0 we know that

//jo xor bchjega, whi missing number hoga..



class Solution {
public:
    int missingNumber(vector<int>& arr) {
        
        
        int n = arr.size() + 1;  // Since one number is missing
        int xorSum = 0;

        // XOR all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            xorSum ^= i;
        }

        // XOR with all elements in the array
        for (int num : arr) {
            xorSum ^= num;
        }

        return xorSum;  // The missing number
    }
};