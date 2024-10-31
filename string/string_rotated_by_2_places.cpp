https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1
//acha..silly..concept clearing substr.. 

//s1 ko left shift,right shift dono krke dekhenge..khi se bhi aya true...
//drr run easy..


//o(N)..
//o(n).


class Solution {
  public:
    bool isRotated(string s1, string s2) {
        
          if (s1.size() != s2.size() || s1.size() < 2) {
              return false;
          }
        
        int n = s1.size();
        
        // Left rotation by 2 places
        string leftRotate = s1.substr(2) + s1.substr(0, 2);  //2nd index se string li puri + usme 0 se 2 index tk elements lelia..
        
        // Right rotation by 2 places
        string rightRotate = s1.substr(n - 2) + s1.substr(0, n - 2);
        //akhri 2+usme 0 se n-2...
        
        
        

        return (s2 == leftRotate || s2 == rightRotate);
    }
};