
https://leetcode.com/problems/happy-number/description/

//easy..famous...approach1..
//o(logn)
//o(logn)..

class Solution {
public:


 int getNextNumber(int n) {  //19 ayga to 82 dena..digit nikalne jaise nikalte..nikalne ke baad square krdena..
        int output = 0;
        
        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }
        
        return output;
    }

    bool isHappy(int n) {

        unordered_set<int> visit;
        
        while (n!=1 && visit.find(n) == visit.end()) {


            visit.insert(n);
            n = getNextNumber(n); //19 ke baad 82..(1^2+9^2)..
        }
        
        return n==1;
    }

};



//better..use floyd detection...(slow-fast)pointers..instead of maintaining a set(set islie use kra tha
//kyuki jab happy number ni hoga input tab eventually wo cycle form krlega..repeaat hone lgjega..)(islie set se pta chl jata jab repeat hoyga..jab hoyga bahar ajege..)

//is approachme flooyd cycle detection..agar khi pe bhi slow=fast mtlb cycle form hogyi false.

//o(logn)..
//o(1)..

class Solution {
public:
    int getNext(int n) {

        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = getNext(n);
        
        while (slow != fast) {

            if(fast==1){
                break;
            }

            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};