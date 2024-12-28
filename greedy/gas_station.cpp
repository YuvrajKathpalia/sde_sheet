
//o(n)..
//o(1)..

https://leetcode.com/problems/gas-station/

#include<bits/stdc++.h>
using namespace std;

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int m=gas.size();
        

        int totalgas=0;
        int totalcost=0;

        for(int i=0;i<m;i++){
            totalgas+=gas[i];
        }
        for(int i=0;i<m;i++){
            totalcost+=cost[i];
        }

        if(totalgas<totalcost){   //MTLB SOLUTION DOESNT EXIST...
            return -1;
        }

        //warna exists..aur starting index nikalna...

        //to loop lgao...har index pe check kro ki next index pe jaskte ya nahi...
        //agar gas[i]-cost[i] -ve ari to ni jaskte...next index pe try kro..
        //loop chlta rhega..agar kisi index se last tak condition satisfy hogyi to poore tour ki hi hojaygi obvio
        //last stored iundex return krdo..

        int currentgas=0;
        int index=0;

        for(int i=0;i<m;i++){

            currentgas += gas[i]-cost[i];  //1 se 2 jane ke lie.. 1 index ki gas - 1 index ki cost(1 se 2 jane ki cost hai jo)

            if(currentgas<0){
                
                index=i+1;
                currentgas=0;

            }

    
        }

        return index;  
        
        
    }


int main()
{
    
    int size;
    cin>>size;
    
    vector<int>gas(size);
    vector<int>cost(size);
    
    for(int i=0;i<size;i++){
        cin>>gas[i];
    }
    for(int i=0;i<size;i++){
        cin>>cost[i];
    }
    
    cout << canCompleteCircuit(gas,cost);

    return 0;
}