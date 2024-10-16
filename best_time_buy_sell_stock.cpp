#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxi = 0;  
    int n = prices.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int profit = prices[j] - prices[i];  
            maxi = max(maxi, profit);  
        }
    }

    return maxi;
}

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];  
    }

    int result = maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}



//optimal...

//o(n)..
//o(1)..

//buy price let krlia phle wala..fir 1 se n loop chlaaya..(hume buy price min krna aur profit max)

//to agar buy prices , prices[i] se bdaa to buy_price update krdo..(chota wala chayie)..

//ur profit max krdo..

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        int buy_price= prices[0];
        int max_profit=0;

        for(int i=1;i<n;i++){

            if(buy_price>prices[i]){
                buy_price=prices[i];
            }

            max_profit = max(max_profit , prices[i]-buy_price);


        }

        return max_profit;
        
    }
};