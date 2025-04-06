https://www.geeksforgeeks.org/problems/single-number1014/1


//koi ek number ki frequency odd hai wo return krna...
//brute force ..unirdered map..o(N)..o(n)..

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int,int>mpp;
        
        for(auto x:arr){
            mpp[x]++;
        }
        
        for(auto x:mpp){
            if(x.second%2==1){
                return x.first;
            }
        }
        
        return -1;
    }
};


// User function template for C++


//optimal approach...xor lelo poore array ka...jo even times aare hinge wo to cancel out 
//hojege...
//jo ek rehjayga whi odd hoyga..

//o(n)..o(1)..

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        
        int result =0;
        
        for(auto x:arr){
            result ^= x;
        }
        
        return result;
        
        
    }
};


///SIMILAR QUESTION...EK NUMBER ODD TIMES HAI..AUR BAKI NO PAIR ME HAI AUR CONSECUTIVE HAI..-- ..1122344..ANS=3.

//BINARY SEAARCH...PHLE TO 0TH AUR N-1TH INDEX PE CHECK KRLIA..
//FIR MID NIKALA FIR CHECK KIA AGAR MID APNE AGE WALE YA APNE PEECHE WALE KISI KE BHI EQUAL NI TO WHI ANS HAI..BREAK

//WARNA...BS SE SEARCH SPACE CHOTA KRO..AGAR MID KI POSITION ODD ARI MTLB PATTERN BREAK HOCHUKA(1122 WALA) TO MTLB WO ANS
//SI HALF ME HAI(LEFT HALF ME...RIGHT--)..WARNA LEFT++..

#include <iostream>

#include <vector>

using namespace std;

 

int main()

{

    int n;  
    cin >> n;

    vector<int> v(n);

    for(int i=0 ; i<n ; i++){

        cin >> v[i];

    }

    int left=0,right=n-1,mid,pre,nxt;

    if(v[0] != v[1]){

            cout << v[0];

        }

    else if(v[n-1] != v[n-2]){

            cout << v[n-1];

        }

    else{

        while(left <= right){

            mid = ((right-left)/2)+left;

            pre = mid-1;

            nxt = mid+1;

            if((v[pre] != v[mid]) && (v[nxt] != v[mid])){

                cout << v[mid];

                break;

            }

            else if(mid%2==0){  //EVEN POSITION ..MTLB PHLA NO OF PAIR HONA CHAYIE..MTLB USKE AAGE WALA SAME NO HONA CHIE//YA PEECHE WALA SAME NI 

                if(v[pre] == v[mid])  

                    right = mid - 1;

                else   //PEECHE WALA SAME NI ..YHI CHIE THA..SOLUTION YAHA NI AGE JAO...

                    left = mid + 1;

            }

            else{  // ODD POSITION.....MTLB PEECHE  WALA SAME HONA CHIE

                if(v[pre] == v[mid])         //PEECHE WALA SAME , TO SOLUTION IS HALF ME TO NI AGE JAO..

                    left = mid + 1;

                else

                    right = mid - 1;

            }

        }

    }

    return 0;

}