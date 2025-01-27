//brute force...

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        int maxprofit=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                maxprofit = max(maxprofit ,prices[j]-prices[i]);
            }
        }

        return maxprofit;
        
    }
};


//optimal..o(n)..o(1)
//ek min price maintain krlo , ek maxprofit maintain krlo..

//agar current price , min price se bhi chota tab profit to honi skta, minprice update krdo
//else profit update kroo...

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        int minprice=INT_MAX;
        int maxprofit= 0;

        for(int i=0;i<n;i++){

            if(prices[i]<minprice){
                minprice=prices[i];
            }
            else{
                maxprofit=max(maxprofit , prices[i]-minprice);
            }
        }

        return maxprofit;
        
    }
};
